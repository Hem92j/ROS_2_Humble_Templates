#include "simple_action_service/count_until_server.hpp"

SimpleActionService::SimpleActionService() : rclcpp::Node("simple_action_service") 
{
    this->action_server_ = this->create_server<simple_interfaces::action::CountUntill>("")
}