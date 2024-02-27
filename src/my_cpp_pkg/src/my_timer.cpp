#include "rclcpp/rclcpp.hpp"

class MyTimer_: public rclcpp::Node
{
public:
    MyTimer_():Node("timer_node"), i(0)
    {
        RCLCPP_INFO(this->get_logger(), "This is a timer node...");
        timer_ = this->create_wall_timer(std::chrono::seconds(1), 
                                         std::bind(&MyTimer_::timer_callback, this));
    };

private:
    void timer_callback()
    {
        i++;
        RCLCPP_INFO(this->get_logger(), "Counting: %d", i);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    int i;

};


int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<MyTimer_>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
    
}