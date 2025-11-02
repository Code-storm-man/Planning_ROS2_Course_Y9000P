#include "pnc_map_server.h"

namespace Planning
{
    PNCMapServer::PNCMapServer() : Node("pnc_map_server_node") // PNC地图服务器
    {
        RCLCPP_INFO(this->get_logger(), "pnc_map_server_node created");
    }
}  // namespace Planning


// 对于ROS2的节点，需要使用main函数作为入口，即需要一个单独的main函数
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Planning::PNCMapServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
