cmake_minimum_required(VERSION 3.29.6)
project(planning_process)

# 设置依赖
set(DEPENDS
    "rclcpp"
    "nav_msgs"
    "base_msgs"
    "tf2"
    "tf2_ros"
)

# 添加节点 add_executable函数
# 注意规划主过程也不是用动态库，而是用节点
# 这个节点会调用别的动态库
add_executable(planning_node
    ${CMAKE_CURRENT_SOURCE_DIR}/planning_node.cpp  # 获取当前目录下的planning_node.cpp文件
    ${CMAKE_CURRENT_SOURCE_DIR}/planning_process.cpp  # 获取当前目录下的planning_process.cpp文件 
)

# 习惯使然，把节点添加到target变量中，即把节点命名成一个target
set(target
    planning_node
)

# 添加依赖
# 注意这里不是cmake里面的API而是ament_cmake的API
ament_target_dependencies(${target}   # 让我们的target(planning_node)依赖上DEPENDS变量中的内容
    ${DEPENDS}
)

# 下面的函数可以去连接到我们自己写的一些三方库
target_link_libraries(${target}
    config_reader
    decision_center
    vehicle_info
    reference_line
    local_planner
)

# 安装动态库、节点和相关的目录
# 下面函数的TARGETS是我要安装内容的一个目标集合
install(TARGETS
    ${target}
    DESTINATION lib/${PLANNING_PACKAGE_NAME};  # 安装节点的写法
)
