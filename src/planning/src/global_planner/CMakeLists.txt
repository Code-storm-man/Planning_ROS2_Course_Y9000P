cmake_minimum_required(VERSION 3.29.6)
project(global_planner) # 子级项目名

# 设置依赖
set(DEPENDS
    "rclcpp"
    "geometry_msgs"
    "nav_msgs"
    "base_msgs"
)

# 添加动态库
# global_planner库: 作为可重用的组件，编译为动态库，可以被其他模块链接使用
# 显式指定SHARED关键字告诉CMake创建动态链接库(.so文件)
# 动态库可以在运行时被多个程序共享，节省内存空间
add_library(global_planner SHARED  # 注意这里要SHARED 
    ${CMAKE_CURRENT_SOURCE_DIR}/global_planner_normal/global_planner_normal.cpp  # 全局规划是动态库
)

# 添加节点
# global_path_server节点: 作为独立的可执行程序，直接运行提供服务
# add_executable命令用于创建可执行文件
# 可执行文件本身就是独立的程序，不需要也不能指定为SHARED
add_executable(global_path_server # 这里不用SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/global_path_server.cpp   # 服务器编译成节点
)

set(project_targets
    global_planner
    global_path_server
)

# 添加依赖
# 循环遍历project_targets中的每一个目标，让他们都依赖上DEPENDS
foreach(target ${project_targets})
  ament_target_dependencies(${target}
    ${DEPENDS}
  )
endforeach()

# 链接三方库
# 修改这里的依赖关系
# target_link_libraries(
#     global_path_server
#     config_reader
#     global_planner
# )
target_link_libraries(global_planner
    config_reader
)
target_link_libraries(global_path_server
    global_planner
)

# 安装动态库、节点和相关的目录
install(TARGETS
    global_planner
    LIBRARY DESTINATION lib  # 安装动态库
)

install(TARGETS
    global_path_server    
    DESTINATION lib/${PLANNING_PACKAGE_NAME}  # 安装节点
)

