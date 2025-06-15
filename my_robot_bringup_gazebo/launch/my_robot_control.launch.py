from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Paths
    desc_pkg = get_package_share_directory('my_robot_description')
    gz_pkg = get_package_share_directory('ros_gz_sim')

    urdf_path = os.path.join(desc_pkg, 'urdf', 'my_robot_controller.urdf.xacro')
    rviz_path = os.path.expanduser('~/ros2_ws/src/my_robot_description/rviz/roboconfig_controller.rviz')

    # 1. gzserver
    gzserver = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gz_pkg, 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={'gz_args': '-v 4 empty.sdf -s'}.items()
    )

    # 2. gzclient (after 2 sec)
    gzclient = TimerAction(
        period=5.0,
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(gz_pkg, 'launch', 'gz_sim.launch.py')
                ),
                launch_arguments={'gz_args': '-g -r --render-engine ogre2'}.items()
            )
        ]
    )

    # 3. robot_state_publisher (after 4 sec)
    robot_state_publisher = TimerAction(
        period=6.0,
        actions=[
            Node(
                package='robot_state_publisher',
                executable='robot_state_publisher',
                parameters=[{
                    'robot_description': Command(['xacro ', urdf_path])
                }]
            )
        ]
    )

    # 4. Spawn model (after 6 sec)
    spawn_robot = TimerAction(
        period=8.0,
        actions=[
            Node(
                package='ros_gz_sim',
                executable='create',
                arguments=['-topic', 'robot_description']
            )
        ]
    )

    # 5. Spawner (after 8 sec)
    spawner = TimerAction(
        period=60.0,
        actions=[
            Node(
                package='controller_manager',
                executable='spawner',
                arguments=['joint_state_broadcaster']
            )
        ]
    )

    # 6. RViz2 (after 10 sec)
    rviz = TimerAction(
        period=10.0,
        actions=[
            Node(
                package='rviz2',
                executable='rviz2',
                output='screen'
            )
        ]
    )

    return LaunchDescription([
        gzserver,
        gzclient,
        robot_state_publisher,
        spawn_robot,
        spawner,
        rviz
    ])
