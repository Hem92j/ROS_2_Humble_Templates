#include "simple_publisher_template/simple_publisher.hpp"
#include "std_msgs/msg/string.hpp"

#include <chrono>
#include <memory>
#include <functional>

SimplePublisher::SimplePublisher() : Node("simple_publisher"), count(0) 
{

    publisher_ = this-> create_publisher<std_msgs::msg::String>("my_publisher", 10);

    timer_ = this->create_wall_timer(std::chrono::milliseconds(200), 
                                     std::bind(&SimplePublisher::timer_callback, this));

    RCLCPP_INFO(this->get_logger(), "Publisher initialized...");
} 

void SimplePublisher::timer_callback() {

    auto msg = std_msgs::msg::String();
    msg.data = "count:  " + std::to_string(count++);    
    publisher_->publish(msg);

}


int main(int argc, char** argv) {

    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimplePublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}