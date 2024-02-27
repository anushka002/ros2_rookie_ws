# include "rclcpp/rclcpp.hpp"
# include "example_interfaces/srv/add_two_ints.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<rclcpp::Node>("add_two_int_no_oop_client");
    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
    while(!client->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_WARN(node->get_logger(), "Waiting for Service to start...");
    }
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 8;
    request->b = 10;
    auto future = client->async_send_request(request);

    if (rclcpp::spin_until_future_complete(node, future) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(node->get_logger(), "output: %d + %d = %d", (int)request->a, (int)request->b, (int)future.get()->sum);
    }
    else
    {
        RCLCPP_ERROR(node->get_logger(), "Error while calling Server!");
    }
    rclcpp::shutdown();
    return 0;
}