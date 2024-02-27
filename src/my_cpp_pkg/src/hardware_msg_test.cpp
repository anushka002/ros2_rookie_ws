#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

class TestNode: public rclcpp::Node
{

public: 
    TestNode(): Node("hardware_status_node")
    {
        pub_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hardware_msg", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&TestNode::callback_msg, this));
    }

private:
    void callback_msg()
    {
        auto msg = my_robot_interfaces::msg::HardwareStatus();
        msg.temp = 25;
        msg.motors_ready = true;
        msg.debug_msg = "Hello, Motors are ready to Start!";
        pub_->publish(msg);
    }
    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<TestNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}