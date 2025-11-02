#include "global_planner_normal.h"

namespace Planning
{
    GlobalPlannerNormal::GlobalPlannerNormal() // 普通全局路径规划期
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "global_planner_normal created");
    }

}  // namespace Planning
