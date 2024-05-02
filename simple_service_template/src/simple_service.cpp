#include "simple_service_template/simple_service.hpp"
#include "sensor_msgs/msg/image.h"

SimpleService::SimpleService() : Node("simple_service") {

    rmw_qos_profile_t qos_profile = rmw_qos_profile_default;

    service_ = this->create_service<simple_interfaces::srv::GetImage>(
        "image_service",
        std::bind(&SimpleService::service_callback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
        qos_profile);
    
    RCLCPP_INFO(this->get_logger(), "Service created !!!");

}

void SimpleService::service_callback(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<simple_interfaces::srv::GetImage::Request> request,
    const std::shared_ptr<simple_interfaces::srv::GetImage::Response> response
) {
    (void)request_header;

    RCLCPP_INFO(this->get_logger(), "Request received...");

    auto img = sensor_msgs::msg::Image();

    img.width = request->res_w;
    img.height = request->res_h;
    img.data.resize(img.width * img.height);
    for (size_t i = 0; i < img.width * img.height; i++) {
        img.data[i] = (std::rand() % (255 + 1));
    }
    response->image = img;
}


int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleService>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}