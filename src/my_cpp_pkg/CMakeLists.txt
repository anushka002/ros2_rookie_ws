cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(my_robot_interfaces REQUIRED)

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

add_executable(cpp_node_c src/my_first_node.cpp)
add_executable(cpp_node_c2 src/cpp_node.cpp)
add_executable(timer_node_1 src/my_timer.cpp)

ament_target_dependencies(cpp_node_c rclcpp)
ament_target_dependencies(cpp_node_c2 rclcpp)
ament_target_dependencies(timer_node_1 rclcpp)

add_executable(robot_news_station_exe src/robot_news_station_code.cpp)
ament_target_dependencies(robot_news_station_exe rclcpp example_interfaces)

add_executable(smartphone_exe src/smartphone_code.cpp)
ament_target_dependencies(smartphone_exe rclcpp example_interfaces)

add_executable(number_publisher src/number_publisher_code.cpp)
ament_target_dependencies(number_publisher rclcpp example_interfaces)

add_executable(number_counter src/number_counter_code.cpp)
ament_target_dependencies(number_counter rclcpp example_interfaces)

add_executable(add_two_ints_server_exe src/add_two_ints_server.cpp)
ament_target_dependencies(add_two_ints_server_exe rclcpp example_interfaces)

add_executable(add_two_ints_client_no_oop_exe src/add_two_ints_client_no_oop.cpp)
ament_target_dependencies(add_two_ints_client_no_oop_exe rclcpp example_interfaces)

add_executable(add_two_ints_client_exe src/add_two_ints_client.cpp)
ament_target_dependencies(add_two_ints_client_exe rclcpp example_interfaces)

add_executable(hardware_exe src/hardware_msg_test.cpp)
ament_target_dependencies(hardware_exe rclcpp my_robot_interfaces)

install(TARGETS
  cpp_node_c
  cpp_node_c2
  timer_node_1
  robot_news_station_exe
  smartphone_exe
  number_publisher
  number_counter
  add_two_ints_server_exe
  add_two_ints_client_no_oop_exe
  add_two_ints_client_exe
  hardware_exe
  DESTINATION lib/${PROJECT_NAME}
)
ament_package()
