#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class RobotNewsStationNode(Node):

    def __init__(self):
        super().__init__("robot_news_stationx")
        self.get_logger().info("Hello everyone! Welcome to news station ......")
        
        self.declare_parameter("robot_name", "WALL-E")
        self.robot_name_ = self.get_parameter("robot_name").value
        
        self.pub_ = self.create_publisher(String,"robot_news", 10)
        
        self.timer_ = self.create_timer(1, self.publish_news)
        self.str1_ = f"Hi my name is {str(self.robot_name_)} .... Nice to meet you!"
        self.get_logger().info(self.str1_)

    def publish_news(self):
        msg = String()
        msg.data = f"Hello! I am {str(self.robot_name_)}"
        self.pub_.publish(msg)


def main(args=None):
    rclpy.init(args=args)   #initialize ros2 communication, arguments from main
    node = RobotNewsStationNode()    #name of node is not the name of the file...
    #node.get_logger().info("Hello ! I am Anushka...\n")
    rclpy.spin(node)
    rclpy.shutdown()     #last line of node


if __name__=="__main__":
    main()
    