cmake_minimum_required(VERSION 3.8)
project(simple_service_template)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(simple_interfaces REQUIRED)

include_directories(include)

add_executable(simple_service src/simple_service.cpp)

ament_target_dependencies (simple_service
  rclcpp
  sensor_msgs
  simple_interfaces
)

install(TARGETS 
simple_service
DESTINATION lib/${PROJECT_NAME})

ament_package()
