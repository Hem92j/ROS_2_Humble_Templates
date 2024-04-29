#include "simple_subscriber_template/simple_subscriber.hpp"
#include "std_msgs/msg/string.hpp"

SimpleSubscriber::SimpleSubscriber() : Node("simple_subscriber")
{
    subscriber_ = this->create_subscription <std_msgs::msg::String>("my_publisher",
    10, 
    std::bind(&SimpleSubscriber::subscription_callback, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "Subscriber initialized...");
}


void SimpleSubscriber::subscription_callback(const std_msgs::msg::String::SharedPtr string_msg) {
    RCLCPP_INFO(this->get_logger(), "Received data. %s", string_msg->data.c_str());

}


int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}