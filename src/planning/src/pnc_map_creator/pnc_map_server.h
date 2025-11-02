#ifndef PNC_MAP_SERVER_H_
#define PNC_MAP_SERVER_H_

#include "rclcpp/rclcpp.hpp"
#include "pnc_map_creator_straight.h"
#include "pnc_map_creator_sturn.h"


namespace Planning
{
    // 服务器需要保留成服务器的节点
    class PNCMapServer : public rclcpp::Node  //PNC地图服务器
    {
    public:
        PNCMapServer();
    private:

    };
}  // namespace Planning
#endif  // PNC_MAP_SERVER_H_
