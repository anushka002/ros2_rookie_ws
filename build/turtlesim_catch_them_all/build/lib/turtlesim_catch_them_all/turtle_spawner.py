#!/usr/bin/env python3
from functools import partial
import random
import math
import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
from my_robot_interfaces.msg import Turtle
from my_robot_interfaces.msg import TurtleArray
from my_robot_interfaces.srv import CatchTurtle
from turtlesim.srv import Kill

class TurtleSpawnerNode(Node):

    def __init__(self):
        super().__init__("turtle_controller")
        self.get_logger().info("Turtle Spawner Node has been started....")
        self.declare_parameter("spawn_frequency", 1.0)
        self.declare_parameter("turtle_name_prefix", "turtle")
        self.frequency_ = self.get_parameter("spawn_frequency").value
        self.spawn_turtle_timer_ = self.create_timer(1.0 / self.frequency_, self.spawn_new_turtle)     # spawn turtles at a given rate ....
        self.alive_turtles_publisher = self.create_publisher(TurtleArray, "alive_turtles", 10)
        self.alive_turtles_ = []   # array of Turtle msgs
        self.name_prefix_ = self.get_parameter("turtle_name_prefix").value
        self.counter_ = 0
        self.catch_turtle_service = self.create_service(CatchTurtle, "catch_turtle", self.callback_catch_turtle)
    
    def publish_alive_turtles(self):
        msg = TurtleArray()
        msg.turtles = self.alive_turtles_
        self.alive_turtles_publisher.publish(msg)
    
    def spawn_new_turtle(self):
        name = self.name_prefix_ + str(self.counter_)
        self.counter_ += 1
        x = random.uniform(1.0, 10.0)
        y = random.uniform(1.0, 10.0)
        theta = random.uniform(0.0, 2 * math.pi)
        self.call_spawn_server(name, x, y, theta)
        
    def call_spawn_server(self, turtlename, x, y, theta):        
        client_ = self.create_client(Spawn, "spawn")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for the Server to start....")
            
        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = turtlename
        
        future_ = client_.call_async(request)
        future_.add_done_callback(partial(self.callback_call, turtlename = turtlename,
                                          x = x, y = y, theta = theta))
        
    def callback_call(self, future_, turtlename, x, y, theta):
        try:
            response = future_.result()                         # NEW TURTLES CREATED HERE!
            if response.name != "":
                self.get_logger().info("Turtle: " + str(response.name) + " is now alive.")
                # ADD THE CALLBACK FOR ALIVE TURTLES HERE
                new_turtle = Turtle()
                new_turtle.name = response.name
                new_turtle.x = x
                new_turtle.y = y
                new_turtle.theta = theta
                self.alive_turtles_.append(new_turtle)
                self.publish_alive_turtles()
                
        except Exception as e:
            self.get_logger().error("Service failed %r" %(e,))
        
    # callback for service catch turtle
    def callback_catch_turtle(self, request, response):
        self.call_kill_server(request.name)
        response.success = True
        return response
    
    # service callback for killing turtle
    def call_kill_server(self, turtlename):        
        client_ = self.create_client(Kill, "kill")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Kill Server to start....")
            
        request = Kill.Request()
        request.name = turtlename
        
        future_ = client_.call_async(request)
        future_.add_done_callback(partial(self.callback_kill, turtlename = turtlename))
    
    def callback_kill(self, future_, turtlename):
        try:
            future_.result()
            for (i,turtle) in enumerate(self.alive_turtles_):
                if turtle.name==turtlename:
                    del self.alive_turtles_[i]
                    self.publish_alive_turtles()    # to publish the new array after removing previous turtle
                    break
            self.get_logger().info("")

        except Exception as e:
            self.get_logger().error("Service failed %r" %(e,))

def main(args=None):
    rclpy.init(args=args)   
    node = TurtleSpawnerNode()   
    rclpy.spin(node)
    rclpy.shutdown()     



if __name__=="__main__":
    main()
    