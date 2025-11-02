import rclpy  
from rclpy.node import Node  # 
import numpy as np  # 后面绘图用到
import matplotlib.pyplot as plt

# 写一个节点
class PlotData(Node):
    def __init__(self):
        super().__init__('data_plot_node')
        # print("data_plot_node created") # python自带的打印，在ROS2里面不是很专业，用别的打印方式
        self.get_logger().info('data_plot_node created')

def main():
    rclpy.init()
    plot_node = PlotData()

    try:
        rclpy.spin(plot_node)
    except KeyboardInterrupt:
        print("Interprrupted by user")
    finally:
        rclpy.shutdown()  # 防止按Ctrl+C时无法关闭


if __name__ == '__main__':
    main()



