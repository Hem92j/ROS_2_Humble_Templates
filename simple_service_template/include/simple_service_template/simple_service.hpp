#pragma once

#include "rclcpp/rclcpp.hpp"



class SimpleService : public rclcpp::Node {
public:
    SimpleService();
private:
    rclcpp::Service<>::SharedPtr service_;
    void service_callback(

    );
};
