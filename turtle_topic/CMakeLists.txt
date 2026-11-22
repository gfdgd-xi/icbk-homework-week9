cmake_minimum_required(VERSION 3.8)
project(turtle_topic)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
add_executable(turtle_topic_publisher src/turtle_topic_publisher.cpp)
add_executable(turtle_topic_subscribe src/turtle_topic_subscribe.cpp)
ament_target_dependencies(turtle_topic_publisher rclcpp geometry_msgs)
ament_target_dependencies(turtle_topic_subscribe rclcpp geometry_msgs)
install(TARGETS
  turtle_topic_publisher
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  turtle_topic_subscribe
  DESTINATION lib/${PROJECT_NAME}
)