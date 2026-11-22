#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
#include <string>
#include <cmath>

const double defaultX = 5.544444561004639;
const double defaultY = 5.544444561004639 + 2;

class TurtleTopic: public rclcpp::Node
{
public:
    TurtleTopic(std::string name) : Node(name) {
        RCLCPP_INFO(this->get_logger(), "Turtle subscribe running");
        subscribe_pose_ = create_subscription<turtlesim::msg::Pose>(
            "/turtle1/pose", 10,
            std::bind(&TurtleTopic::triggered, this, std::placeholders::_1)
        );
    }

private:
    void triggered(const turtlesim::msg::Pose::SharedPtr msg) {
        double x, y, theta;
        x = msg->x;
        y = msg->y;
        theta = msg->theta;
        double distance = pow(x - defaultX, 2) + pow(y - defaultY, 2);
        if (distance > 4 + 0.1 || distance < 4 - 0.1) {
            RCLCPP_WARN(this->get_logger(), "需要修正方向");
        }
        RCLCPP_INFO(this->get_logger(), "x=%.3f, y=%.3f, theta: %.3f", x, y, theta);
    }
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscribe_pose_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleTopic>("turtle_topic_subscribe");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}