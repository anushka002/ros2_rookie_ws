import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import HardwareStatus

class TestNode(Node):
    def __init__(self):
        super().__init__("hardware_test_msg")
        self.get_logger().info("Hardware Status Publisher has been started!")
        self.pub_ = self.create_publisher(HardwareStatus, "hardware_status", 10)
        self.timer_ = self.create_timer(0.5, self.callback_pub)
        
    def callback_pub(self):
        msg = HardwareStatus()
        msg.temp = 25
        msg.motors_ready = True
        msg.debug_msg = "Motors have started...."
        self.pub_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = TestNode()
    rclpy.spin(node)
    rclpy.shutdown()