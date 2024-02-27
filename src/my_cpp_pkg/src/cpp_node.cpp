#include "rclcpp/rclcpp.hpp"

class MyNode: public rclcpp::Node
{
public:
    MyNode(): Node("cpp_test_node_2"), counter_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello CPP Node!!!");
        RCLCPP_INFO(this->get_logger(), "My name is Anushka Satav!!!");
        timer_ = this->create_wall_timer(std::chrono::seconds(1), 
                                        std::bind(&MyNode::timer_Callback, this));
    };

private:

    void timer_Callback()
    {
        counter_++;
        RCLCPP_INFO(this->get_logger(), "Hey!....%d", counter_);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;
};


int main(int argc,char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}