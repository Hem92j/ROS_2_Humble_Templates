#pragma once

#include "rclcpp/rclcpp.hpp"
#include "simple_interfaces/srv/get_image.hpp"


class SimpleClient : public rclcpp::Node {
public:
    SimpleClient();

    void run_request_loop();
    
private:
    rclcpp::Client<simple_interfaces::srv::GetImage>::SharedPtr client_;
};