#pragma once

#include <memory>
#include <functional>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "simple_interfaces/action/count_until.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

class SimpleActionService : public rclcpp::Node {
public:
    SimpleActionService();
private:
    rclcpp_action::Server<simple_interfaces::action::CountUntill>::SharedPtr action_server_; 
};