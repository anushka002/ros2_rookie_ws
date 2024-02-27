#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class MobileNode(Node):

    def __init__(self):
        super().__init__("mobilephone")
        self.sub_ = self.create_subscription(String, "robot_news",self.sub_callback,10)
        self.get_logger().info("Hello everyone! Starting mobile phone!!")

    def sub_callback(self, msg):
        self.get_logger().info(msg.data) 


def main(args=None):
    rclpy.init(args=args)   #initialize ros2 communication, arguments from main
    node = MobileNode()    #name of node is not the name of the file...
    rclpy.spin(node)
    rclpy.shutdown()     #last line of node



if __name__=="__main__":
    main()
    