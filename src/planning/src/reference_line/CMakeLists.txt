cmake_minimum_required(VERSION 3.29.6)
project(reference_line) # 子级项目名

# 设置依赖
set(DEPENDS
    "rclcpp"
    "geometry_msgs"
    "nav_msgs"
    "base_msgs"
    "tf2"
)

# 添加动态库
add_library(reference_line SHARED # 要指定成SHARED才会编译成动态库
    ${CMAKE_CURRENT_SOURCE_DIR}/reference_line_creator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/reference_line_smoother.cpp
)

set(target
    reference_line
)

# 添加依赖
ament_target_dependencies(${target} 
    ${DEPENDS}
)

target_link_libraries(${target}
    config_reader
    mathlibs
    Eigen3::Eigen
    OsqpEigen::OsqpEigen
)

# 安装动态库、节点和相关的目录
install(TARGETS 
    ${target}
    # DESTINATION lib/${PLANNING_PACKAGE_NAME})  # 这是节点的安装目录，不严谨，修改成动态库的安装目录
    LIBRARY DESTINATION lib)
