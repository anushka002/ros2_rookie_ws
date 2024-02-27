#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumPublishNode : public rclcpp::Node
{
public:
    NumPublishNode() : Node("number_publisher") // , number_(2)
    {
        this->declare_parameter("number_to_publish", 10);
        number_ = this->get_parameter("number_to_publish").as_int();

        this->declare_parameter("frequency", 1.0);
        double freq_ = this->get_parameter("frequency").as_double();

        pub_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        //timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&NumPublishNode::PublishNum, this));
        timer_ = this->create_wall_timer(
                                        std::chrono::milliseconds( (int)  (1000.0 / freq_ ) ), 
                                        std::bind(&NumPublishNode::PublishNum, this));
        RCLCPP_INFO(this->get_logger(), "Number Publisher Node is started...");
    }

private:
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    int number_;


    void PublishNum()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_;
        //msg.data = number_;
        pub_->publish(msg);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumPublishNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

