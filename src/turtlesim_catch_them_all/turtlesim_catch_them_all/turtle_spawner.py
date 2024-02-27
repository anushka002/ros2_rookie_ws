#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class TurtleSpawnerNode(Node):

    def __init__(self):
        super().__init__("turtle_controller")
        self.get_logger().info("Turle Controller Node has been started....")


def main(args=None):
    rclpy.init(args=args)   
    node = TurtleSpawnerNode()   
    rclpy.spin(node)
    rclpy.shutdown()     



if __name__=="__main__":
    main()
    