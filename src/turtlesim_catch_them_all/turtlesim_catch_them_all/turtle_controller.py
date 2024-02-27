#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist


class TurtleControllerNode(Node):
    def __init__(self):
        super().__init__("turtle_controller")
        self.get_logger().info("Turtle Controller Node has been started....")
        
        self.pose_ = None
        
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        
        self.subcriber_ = self.create_subscription(Pose, "turtle1/pose", 
                                                   self.callback_turtle_pose , 10)
        
        self.control_loop_tmier_ = self.create_timer(0.01, self.control_loop)
        
        
        
    def callback_turtle_pose(self, msg):
        self.pose_ = msg
    
    
    def control_loop(self):
        pass 
        
def main(args=None):
    rclpy.init(args=args)   
    node = TurtleControllerNode()   
    rclpy.spin(node)
    rclpy.shutdown()     



if __name__=="__main__":
    main()
    