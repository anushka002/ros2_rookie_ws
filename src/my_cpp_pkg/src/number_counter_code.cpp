#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"
using std::placeholders::_1;
using std::placeholders::_2;

class NumCounterNode : public rclcpp::Node
{

public:
    NumCounterNode() : Node("number_counter"), sum_(0)
    {
        sub_ = this->create_subscription<example_interfaces::msg::Int64>("number", 10, 
                                    std::bind(&NumCounterNode::callback_sub, this, std::placeholders::_1));
        pub_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&NumCounterNode::publish_count, this));
        reset_counter_ = this->create_service<example_interfaces::srv::SetBool>("reset_counter",
                             std::bind(&NumCounterNode::callback_reset, this, _1, _2));
    }

private:
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr sub_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr reset_counter_;

    int sum_;

    void callback_sub(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        sum_ += msg->data;
        RCLCPP_INFO(this->get_logger(),"<Received> ");
    }

    void publish_count()             
    {
        auto sum_msg = example_interfaces::msg::Int64();
        sum_msg.data = sum_;
        pub_->publish(sum_msg);
        RCLCPP_INFO(this->get_logger(), "Published Sum: %d", sum_);
    }
    void callback_reset(const example_interfaces::srv::SetBool::Request::SharedPtr request, 
                        const example_interfaces::srv::SetBool::Response::SharedPtr response)
    {
        if (request->data == true){
            response->success = true;
            response->message = "Resetting counter to Zero...";
            sum_ = 0;
        }
        else{
            response->success = false;
            response->message = "Not resetting counter...";
        }
    }
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}                       