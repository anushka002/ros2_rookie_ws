# usr/bin/env python3 

import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class NumPublishNode(Node):
    def __init__(self):
        super().__init__("number_publisher")
        self.get_logger().info("Number Publisher has been started!")

        self.declare_parameter("number_to_publish", 2)        
        self.num_ = self.get_parameter("number_to_publish").value 
        
        self.declare_parameter("frequency", 1.0)        
        self.frequency_ = self.get_parameter("frequency").value    
        
        self.pub_ = self.create_publisher(Int64, "number", 10)
        self.timer_ = self.create_timer(1.0 / self.frequency_, self.publish_num)
    
    def publish_num(self):
        msg = Int64()
        msg.data = self.num_
        self.pub_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = NumPublishNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__=="__main__":
    main()
    