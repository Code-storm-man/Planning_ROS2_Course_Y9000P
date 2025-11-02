#ifndef DECISION_CENTER_H_
#define DECISION_CENTER_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "main_car_info.h"  // 决策中心会用到一些车辆的信息，所以需要将这两个文件包含进来
#include "obs_car_info.h"

namespace Planning
{
    class DecesionCenter  // 决策中心
    { 
    public:
        DecesionCenter();
    private:

    };
}  // namespace Planning
#endif  // DECISION_CENTER_H_
