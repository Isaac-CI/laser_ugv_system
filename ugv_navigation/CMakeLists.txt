cmake_minimum_required(VERSION 3.8)
project(ugv_navigation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(action_msgs REQUIRED)

add_executable(goal_pose_publisher /home/isaac/Documents/Estudos/robotica/omni_final_ws/src/laser_ugv_system/ugv_navigation/scripts/goal_pose_publisher.cpp)

ament_target_dependencies(goal_pose_publisher
rclcpp 
geometry_msgs
rclcpp_action 
nav2_msgs 
lifecycle_msgs
action_msgs
)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

install(TARGETS goal_pose_publisher
  DESTINATION lib/${PROJECT_NAME})

# Inclua os diretórios de inclusão dos pacotes nav2_msgs
#include_directories(
#  include
#  ${nav2_msgs_INCLUDE_DIRS}
#)

install(DIRECTORY 
	launch
  config
  rviz
  scripts
  DESTINATION share/${PROJECT_NAME}
)

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
