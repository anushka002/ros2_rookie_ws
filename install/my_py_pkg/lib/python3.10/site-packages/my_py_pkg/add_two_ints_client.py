#! usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

def main(args=None):
    rclpy.init(args=args)
    add_two_ints_client = Node('add_two_ints_client')
    client = add_two_ints_client.create_client(AddTwoInts, 'add_two_ints')

    while not client.wait_for_service(timeout_sec=1.0):
        add_two_ints_client.get_logger().info('Service not available, waiting again...')

    # Get user input
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))

    request = AddTwoInts.Request()
    request.a = a
    request.b = b

    future = client.call_async(request)
    rclpy.spin_until_future_complete(add_two_ints_client, future)

    if future.result() is not None:
        add_two_ints_client.get_logger().info(f"Result: {future.result().sum}")
    else:
        add_two_ints_client.get_logger().error('Service call failed %r' % (future.exception(),))

    add_two_ints_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

