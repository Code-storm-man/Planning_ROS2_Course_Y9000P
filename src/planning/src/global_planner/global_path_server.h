#ifndef GLOBAL_PATH_SERVER_H_
#define GLOBAL_PATH_SERVER_H_

#include "rclcpp/rclcpp.hpp"
#include "global_planner_normal.h"

namespace Planning
{
    // 服务器需要保留成服务器的节点
    class GlobalPathServer : public rclcpp::Node   
    {
    public:
        GlobalPathServer();
    private:

    };
}  // namespace Planning
#endif  // GLOBAL_PATH_SERVER_H_
