# usr/bin/env python3 

import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

from example_interfaces.srv import SetBool


class NumCounterNode(Node):
    def __init__(self):
        super().__init__("number_counter")
        self.get_logger().info("Number Counter has been started and will start counting now:")
        self.create_subscription(Int64, "number", self.callback_numberpub, 10)
        self.num1_ = 0
        self.sum_ = 0
        
        self.pub_ = self.create_publisher(Int64, "number_count", 10)
        self.timer_ = self.create_timer(1, self.publish_counter)
        
        self.service_reset_ = self.create_service(SetBool, "reset_counter", self.reset_counter)
        
    def reset_counter(self, request, response):
        if request.data == True:
            response.success = True
            response.message = "Resetting the counter to zero...."
            self.get_logger().info("Resetting the counter to zero.")
            self.sum_ = 0
        else:
            response.success = False
            response.message = "Not Resetting the counter...."
        return response
        
    def callback_numberpub(self, msg):
        self.num1_ = msg.data
        self.get_logger().info("<received> "+ str(msg.data))
        self.sum_ = self.sum_ + self.num1_
        
    
    def publish_counter(self):
        msg = Int64()
        msg.data = self.sum_
        self.pub_.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = NumCounterNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__=="__main__":
    main()
    