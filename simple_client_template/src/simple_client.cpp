#include "simple_client_template/simple_client.hpp"
#include <chrono>

using namespace std::chrono_literals;


SimpleClient::SimpleClient(): Node("simple_client") {

    rmw_qos_profile_t qos_profile = rmw_qos_profile_default;

    client_ = this->create_client<simple_interfaces::srv::GetImage>(
        "image_service",
        qos_profile 
        );

    while (!client_->wait_for_service(100ms)){
        if (!rclcpp::ok()) 
        {
            RCLCPP_ERROR(this->get_logger(), "Client interrupted!!!");
            assert(0);
        }
        RCLCPP_INFO(this->get_logger(), "Waiting for service to appear...");
    }

    RCLCPP_INFO(this->get_logger(), "Client created!!!");

}

void SimpleClient::run_request_loop() 
{
    rclcpp::WallRate loop_rate(250ms);
    while (rclcpp::ok()) {

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        auto request = std::make_shared<simple_interfaces::srv::GetImage::Request>();

        request->res_w = 480;
        request->res_h = 320;

        auto result_future = client_->async_send_request(request);
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_future) !=
            rclcpp::FutureReturnCode::SUCCESS){
            RCLCPP_ERROR(this->get_logger(), "Service call failed :(");
            assert(0);
        }


        std::shared_ptr<simple_interfaces::srv::GetImage::Response> response = result_future.get();

        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        auto request_duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        RCLCPP_INFO(this->get_logger(), "Got response in %ld seconds", request_duration);

        loop_rate.sleep();
    }

}


int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleClient>();
    node->run_request_loop();
    rclcpp::shutdown();
    return 0;
}


