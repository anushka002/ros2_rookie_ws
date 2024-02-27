from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    robot_news_c3p0 = Node(
        package = "my_py_pkg",
        executable = "robot_news_station",
        name = "robot_news_c3p0",
        parameters=[
            {"robot_name": "C3PO"},
        ]
    ) 
    robot_news_R2D2 = Node(
        package = "my_py_pkg",
        executable = "robot_news_station",
        name = "robot_news_R2D2",
        parameters=[
            {"robot_name": "R2D2"},
        ]
    ) 
    robot_news_WALLE = Node(
        package = "my_py_pkg",
        executable = "robot_news_station",
        name = "robot_news_WALLE",
        parameters=[
            {"robot_name": "WALLE"},
        ]
    ) 
    robot_news_JANDER = Node(
        package = "my_py_pkg",
        executable = "robot_news_station",
        name = "robot_news_JANDER",
        parameters=[
            {"robot_name": "JANDER"},
        ]
    ) 
    robot_news_BB8 = Node(
        package = "my_py_pkg",
        executable = "robot_news_station",
        name = "robot_news_BB8",
        parameters=[
            {"robot_name": "BB8"},
        ]
    ) 
    
    smartphone_node = Node(
        package="my_py_pkg",
        executable="mobilephone",
        name = "my_smartphone",
    )
    
    ld.add_action(robot_news_c3p0)
    ld.add_action(robot_news_R2D2)
    ld.add_action(robot_news_WALLE)
    ld.add_action(robot_news_JANDER)
    ld.add_action(robot_news_BB8)
    
    ld.add_action(smartphone_node)
    
    return ld