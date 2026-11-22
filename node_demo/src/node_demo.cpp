#include <rclcpp/rclcpp.hpp>

int main(int argc, char **argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("node_demo");
    RCLCPP_INFO(node->get_logger(), "node_demo running");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}