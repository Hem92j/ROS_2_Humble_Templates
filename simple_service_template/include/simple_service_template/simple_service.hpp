#pragma once


#include "rclcpp/rclcpp.hpp"
#include "simple_interfaces/srv/get_image.hpp"

#include <memory>

class SimpleService : public rclcpp::Node {
public:
    SimpleService();
private:
    rclcpp::Service<simple_interfaces::srv::GetImage>::SharedPtr service_;
    void service_callback(
        const std::shared_ptr<rmw_request_id_t> request_header,
        const std::shared_ptr<simple_interfaces::srv::GetImage::Request> request,
        const std::shared_ptr<simple_interfaces::srv::GetImage::Response> response
    );
};
