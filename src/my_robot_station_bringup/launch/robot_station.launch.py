from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    node_robot_news_giskard = Node(
        package="my_cpp_pkg",
        executable="robot_radio_station",
        name= "robot_news_station_giskard",
        parameters=[
            {"robot_name":"giskard"}
        ]
    )

    node_robot_news_c3po = Node(
        package="my_cpp_pkg",
        executable="robot_radio_station",
        name= "node_robot_news_c3po",
        parameters=[
            {"robot_name":"c3po"}
        ]
    )

    node_robot_news_bb8 = Node(
        package="my_cpp_pkg",
        executable="robot_radio_station",
        name= "node_robot_news_bb8",
        parameters=[
            {"robot_name":"bb8"}
        ]
    )

    node_robot_news_daneel = Node(
        package="my_cpp_pkg",
        executable="robot_radio_station",
        name= "node_robot_news_daneel",
        parameters=[
            {"robot_name":"daneel"}
        ]
    )

    node_robot_news_lander = Node(
        package="my_cpp_pkg",
        executable="robot_radio_station",
        name= "node_robot_news_lander",
        parameters=[
            {"robot_name":"lander"}
        ]
    )

    node_smartphone = Node(
        package="my_cpp_pkg",
        executable="smartphone",
    )

    ld.add_action(node_robot_news_giskard)
    ld.add_action(node_robot_news_c3po)
    ld.add_action(node_robot_news_bb8)
    ld.add_action(node_robot_news_daneel)
    ld.add_action(node_robot_news_lander)
    ld.add_action(node_smartphone)

    return ld