cmake_minimum_required(VERSION 3.8)
project(simple_client_template)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(simple_interfaces REQUIRED)

include_directories(include)

add_executable(simple_client src/simple_client.cpp)
ament_target_dependencies(simple_client
  rclcpp
  sensor_msgs
  simple_interfaces
)

install(TARGETS 
simple_client
DESTINATION lib/${PROJECT_NAME})

ament_package()
