#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <string>

class TurtleTopic: public rclcpp::Node
{
public:
    TurtleTopic(std::string name) : Node(name) {
        RCLCPP_INFO(this->get_logger(), "Turtle publisher running");
        publisher_ = create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        timer_ = create_wall_timer(std::chrono::milliseconds(500),
            std::bind(&TurtleTopic::timer_callback, this));
    }

private:
    void timer_callback() {
        geometry_msgs::msg::Twist twist;
        twist.linear.x = 2.0;
        twist.angular.z = 1.0;
        publisher_->publish(twist);
    }
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleTopic>("turtle_topic_publisher");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}