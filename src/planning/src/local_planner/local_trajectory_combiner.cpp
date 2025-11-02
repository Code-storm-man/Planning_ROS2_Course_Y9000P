#include "local_trajectory_combiner.h"


namespace Planning
{
    Planning::LocalTrajectoryCombiner::LocalTrajectoryCombiner()  // 局部轨迹合成器
    {
        RCLCPP_INFO(rclcpp::get_logger("local_trajectory_combiner"), "local_trajectory_combiner created");
    }
} // namespace Planning
