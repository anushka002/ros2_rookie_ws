#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LedStateArray
from my_robot_interfaces.srv import SetLed

class LedPublisherNode(Node):

    def __init__(self):
        super().__init__("led_states_server")
        self.pub_ = self.create_publisher(LedStateArray, "led_states", 10)
        self.timer_ = self.create_timer(4, self.publish_status)
        
        self.declare_parameter("led_states", [0, 0, 0])
        self.led_states_ = self.get_parameter("led_states").value
        #self.led_states_ = [0, 0, 0]        
        self.counter_ = 0
        self.get_logger().info("Starting LED STATES SERVER......")
        self.server_ = self.create_service(SetLed, "set_led", self.service_callback)
        
    def publish_status(self):
        self.counter_+= 4
        msg = LedStateArray()
        msg.led_states = self.led_states_
        msg.status = f" 'LEDS ARE OFF'   Time: {str(self.counter_)}"
        self.pub_.publish(msg)

    def service_callback(self, request, response):
        led_number = request.led_number
        state = request.state
        
        if led_number > len(self.led_states_) or led_number <= 0:
            self.get_logger().error("ERROR OCCURED...")
            response.success = False
            return response
        
        if state not in [0, 1]:
            response.success = False
            return response
        
        self.led_states_[led_number-1] = state
        response.success = True
        self.publish_status()
        return response
        
        
    

def main(args=None):
    rclpy.init(args=args)   
    node = LedPublisherNode()    
    rclpy.spin(node)
    rclpy.shutdown()    


if __name__=="__main__":
    main()
    