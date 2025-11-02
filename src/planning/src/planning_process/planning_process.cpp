#include "planning_process.h"

namespace Planning
{
    PlanningProcess::PlanningProcess() : Node("planning_node") // 规划总流程
    {
        RCLCPP_INFO(this->get_logger(), "Planning node created");
    }

    bool PlanningProcess::process()
    {
        return true;
    }; // 总流程函数，要么成功，要么失败

}