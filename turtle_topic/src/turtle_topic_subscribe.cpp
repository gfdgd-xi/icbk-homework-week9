#include <rclcpp/rclcpp.hpp>
#include <string>

class TurtleTopic: public rclcpp::Node
{
public:
    TurtleTopic(std::string name) : Node(name) {
        RCLCPP_INFO(this->get_logger(), "Turtle subscribe running");
    }

};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleTopic>("turtle_topic_subscribe");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}