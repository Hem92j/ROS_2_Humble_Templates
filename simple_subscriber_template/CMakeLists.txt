cmake_minimum_required(VERSION 3.8)
project(simple_subscriber_template)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

add_executable(simple_subscriber src/simple_subscriber.cpp)

ament_target_dependencies(simple_subscriber
  rclcpp
  std_msgs
)

install(TARGETS
  simple_subscriber

  DESTINATION lib/${PROJECT_NAME})

ament_package()
