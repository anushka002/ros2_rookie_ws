#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsClientsNode: public rclcpp::Node
{
public:
    AddTwoIntsClientsNode(): Node("add_two_ints_client_node")
    {
        thread1 = std::thread(std::bind(&AddTwoIntsClientsNode::CallService, this, 1, 4));
    }

    void CallService(int a, int b)
    {
        auto client_ = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
        while (!client_->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for Service to start....");
        }
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;

        auto future = client_->async_send_request(request);
        
        try
        {
            auto response = future.get();                   // will wait until future response is recieved.... we use get() as we cannot use spin twice
            RCLCPP_INFO(this->get_logger(), "output: %d + %d = %d",a,b, (int)response->sum);
        }
        catch(const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(),"Service Call Failed.....");
        }
    
    }
private:
    std::thread thread1;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<AddTwoIntsClientsNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}