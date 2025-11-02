#include "obs_car_info.h"

namespace Planning
{
    ObsCar::ObsCar()  // 主车信息
    {
        RCLCPP_INFO(rclcpp::get_logger("vehicle"), "obs_car created");
    }
}// namespace Planning