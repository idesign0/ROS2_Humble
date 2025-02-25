from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    robot_names = ["giskard", "c3po", "bb3", "daneel", "lander"]
    my_robot_names_nodes = []

    for name in robot_names:
        my_robot_names_nodes.append(Node(
            package="my_cpp_pkg",
            executable="robot_radio_station",
            name= "robot_news_station_" + name,
            parameters=[
            {"robot_name": name}
        ]
        ))

    node_smartphone = Node(
        package="my_cpp_pkg",
        executable="smartphone",
    )

    for node in my_robot_names_nodes:
         ld.add_action(node)
    
    ld.add_action(node_smartphone)

    return ld