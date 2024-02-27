#! usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("py_test_p")
        self.counter_ = 0
        self.get_logger().info("Hello everyone! ROS2 here......")
        self.create_timer(0.5, self.timer_callback_func)

    def timer_callback_func(self):
        self.counter_+=1
        self.get_logger().info("Hello..... "+str(self.counter_))


def main(args=None):
    rclpy.init(args=args)   #initialize ros2 communication, arguments from main
    node = MyNode()    #name of node is not the name of the file...
    rclpy.spin(node)
    rclpy.shutdown()     #last line of node



if __name__=="__main__":
    main()
    