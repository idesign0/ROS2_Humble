import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/parallels/ros2_ws/ROS2_Humble/install/components_py'
