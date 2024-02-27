import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts
from functools import partial

class AddTwoIntsClientNode(Node):
    def __init__(self):
        super().__init__("add_two_ints_client_n")
        self.call_service(1,11)
        
    def call_service(self, a, b):        
        client_ = self.create_client(AddTwoInts, "add_two_ints")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for the Server to start....")
        request = AddTwoInts.Request()
        request.a = a
        request.b = b
        future_ = client_.call_async(request)
        future_.add_done_callback(partial(self.callback_call, a = a, b = b))
        
    def callback_call(self, future_, a, b):
        try:
            response = future_.result()
            self.get_logger().info("Output: "+str(a)+" + "+str(b)+" = "+str(response.sum))
        except Exception as e:
            self.get_logger().error("Service failed %r" %(e,))
    
def main(args = None):
    rclpy.init(args=args)
    node = AddTwoIntsClientNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main":
    main()
        