#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotNewsStationNode : public rclcpp::Node
{
public:
    RobotNewsStationNode() : Node("robot_news_station_node")  //, robot_name_("C3PO")
    {
        this->declare_parameter("robot_name", "R2D2");
        robot_name_ = this->get_parameter("robot_name").as_string();

        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&RobotNewsStationNode::PublishNews, this));
        RCLCPP_INFO(this->get_logger(), "Starting the Robot News Station!...");
    }

private:
    std::string robot_name_;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void PublishNews()
    {
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("Hello this is my name: ") + robot_name_ + std::string(" and welcome to my news station!");
        publisher_->publish(msg);
    }
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<RobotNewsStationNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}