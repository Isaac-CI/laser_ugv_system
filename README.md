# Readme
## Description

This repository contains launch and run commands for  simulation using ROS2 (Robot Operating System 2). It includes commands for launching the world simulation, robot descriptions, navigation, SLAM (Simultaneous Localization and Mapping), RViz visualization, and goal pose publishing. Additionally, it provides instructions for saving a map generated during the simulation.

## Prerequisites

To run the  simulation, you need to have the following software installed:

    ROS2: Make sure you have ROS2 installed on your system. You can refer to the official ROS2 documentation for installation instructions.


## Building and Installing Packages



Install the nav2 package by executing the following command:


    sudo apt-get install ros-${ROS_DISTRO}-nav2

Install the slam_toolbox package by executing the following command:


    sudo apt-get install ros-${ROS_DISTRO}-slam-toolbox

Build the packages using colcon by executing the following command in your workspace directory:

    colcon build --symlink-install

## Launching the Simulation

Launch the world simulation by executing the following command:


    ros2 launch ugv_simulation world_launch.py

Launch the robot descriptions by executing the following command:


    ros2 launch ugv_robots_descriptions oni_description_launch.py

Launch the navigation system by executing the following command:


    ros2 launch ugv_navigation navigation_launch.py use_sim_time:=True autostart:=True params_file:=./src/laser_ugv_system/ugv_navigation/config/nav2_params.yaml use_sim_time:=true

Launch the SLAM system by executing the following command:


    ros2 launch ugv_navigation slam_launch.py slam_params_file:=./src/laser_ugv_system/ugv_navigation/config/slam_params.yaml

Launch RViz2 for visualization using the following command:


    ros2 run rviz2 rviz2 -d $(ros2 pkg prefix ugv_navigation)/share/ugv_navigation/rviz/nav2_default_view.rviz

Run the goal pose publisher using the following command:


    ros2 run ugv_navigation goal_pose_publisher

### Saving the Map

To save the generated map during the simulation, use the following command:


    ros2 run nav2_map_server map_saver_cli -f ./src/laser_ugv_system/images/maps/mapa_oni_final

    This command will save the map in the specified file path (./src/laser_ugv_system/images/maps/mapa_oni_final).

## Authors

- Isaac Nobréga
- João Galvão
- Joelder Aguiar