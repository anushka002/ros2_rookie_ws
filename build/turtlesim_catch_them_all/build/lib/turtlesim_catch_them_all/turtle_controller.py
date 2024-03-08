#!/usr/bin/env python3
import rclpy
import math
from functools import partial
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from my_robot_interfaces.msg import Turtle
from my_robot_interfaces.msg import TurtleArray
from my_robot_interfaces.srv import CatchTurtle

class TurtleControllerNode(Node):
    def __init__(self):
        super().__init__("turtle_controller")
        self.get_logger().info("Turtle Controller Node has been started....")
        self.pose_ = None
        self.turtle_to_catch_ = None
        self.catch_closest_turtle_first_ = self.declare_parameter("catch_closest_turtle_first", True).value
        #self.catch_closest_turtle_first_ = True
        #self.target_x = 8.0
        #self.target_y = 4.0
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", 
                                                         self.callback_turtle_pose , 10)    # get master turtle position

        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)       # control turtle movement
        
        self.alive_turtles_subscriber_ = self.create_subscription(TurtleArray, "alive_turtles", 
                                                                  self.callback_alive_turtles, 10)  # location of turtles

        self.control_loop_timer_ = self.create_timer(0.01, self.control_loop)     # controlling the master turtle to catch other turtles



    def callback_turtle_pose(self, msg):
        self.pose_ = msg
        
    def callback_alive_turtles(self, msg):
        if len(msg.turtles)>0:
            if self.catch_closest_turtle_first_:
                # get distance between master turtle and other turtles
                closest_turtle = None
                closest_turtle_distance_ = None
                
                for turtle in msg.turtles:
                    dist_x = turtle.x - self.pose_.x
                    dist_y = turtle.y - self.pose_.y
                    distance = math.sqrt(dist_x*dist_x + dist_y*dist_y)
                    if closest_turtle == None or distance < closest_turtle_distance_:
                        closest_turtle = turtle
                        closest_turtle_distance_ = distance
                        
                self.turtle_to_catch_ = closest_turtle
                
            else:
                self.turtle_to_catch_ = msg.turtles[0]
    
    def control_loop(self):
        if self.pose_ == None or self.turtle_to_catch_ == None:
            return
        
        dist_x = self.turtle_to_catch_.x - self.pose_.x     
        dist_y = self.turtle_to_catch_.y - self.pose_.y
        distance = math.sqrt(dist_x*dist_x + dist_y*dist_y)  # distance between turtle and target
        
        msg = Twist()  # fill with velocities
        
        if distance > 0.5:    # P-CONTROLLER
            # position
            msg.linear.x = 1.5*distance
            # orientation               ----> 0 (ANTI +)
            goal_theta = math.atan2(dist_y, dist_x)
            diff = goal_theta - self.pose_.theta
            if diff > math.pi:
                diff -= 2*math.pi
            elif diff < -2*math.pi:
                diff+= 2*math.pi
                
            msg.angular.z = 5.5*diff    # try different values ;)
            
        else:
            # target caught
            self.get_logger().info("Target caught...")
            msg.linear.x = 0.0
            msg.angular.z = 0.0
            self.call_catchturtle_server(self.turtle_to_catch_.name)
            self.turtle_to_catch_ = None
        
        self.cmd_vel_publisher_.publish(msg)
        
    def call_catchturtle_server(self, turtlename):        
        client_ = self.create_client(CatchTurtle, "catch_turtle")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Kill Server to start....")
            
        request = CatchTurtle.Request()
        request.name = turtlename
        
        future_ = client_.call_async(request)
        future_.add_done_callback(partial(self.callback_call_catch_turtle, turtlename = turtlename))
    
    def callback_call_catch_turtle(self, future_, turtlename):
        try:
            response = future_.result()
            if not response.success:
                self.get_logger().error("Turle - " + str(turtlename) + " could not be caught")
            self.get_logger().info("")

        except Exception as e:
            self.get_logger().error("Service failed %r" %(e,))

def main(args=None):#
    rclpy.init(args=args)   
    node = TurtleControllerNode()   
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()
    