# include "rclcpp/rclcpp.hpp"
# include "example_interfaces/srv/add_two_ints.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class AddTwoIntsServiceNode: public rclcpp::Node
{
public:
    AddTwoIntsServiceNode(): Node("add_two_ints_server_cpp")
    {
        server_ = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", std::bind(&AddTwoIntsServiceNode::callback_service, this, _1,_2));
        RCLCPP_INFO(this->get_logger(), "Service - Add Two Ints has been started!!");
    }
private:
    void callback_service(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request, const example_interfaces::srv::AddTwoInts::Response::SharedPtr response)
    {
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "%ld + %ld = %ld", request->a , request->b , response->sum);
    }
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsServiceNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}