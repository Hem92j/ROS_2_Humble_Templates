#pragma once


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class SimpleSubscriber : public rclcpp::Node{
public:
    SimpleSubscriber();

private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
    void subscription_callback(const std_msgs::msg::String::SharedPtr  string_msg);  

};