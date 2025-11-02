#ifndef CONFIG_READER_H_
#define CONFIG_READER_H_

#include "rclcpp/rclcpp.hpp"
#include <yaml-cpp/yaml.h>
#include <ament_index_cpp/get_package_share_directory.hpp> 

namespace /* namespace_name */
{
    struct VehicleStruct  // 车辆
    {
        int id_= 0;                            // 序列号
        std::string frame_ = "base_footprint"; // 坐标名
        double length_ = 3.0;                  // 长度
        double width_ = 1.5;                   // 宽度
        double pose_x_ = 0.0;                  // x坐标
        double pose_y_ = 0.0;                  // y坐标
        double pose_theta_ = 0.0;              // 航向角
        double speed_ori_ = 1.0;               // 初速度
    };

    struct MapStruct  // 地图
    {
        std::string map_file_ = "map.txt"; // 地图文件名
    };
    
    class ConfigReader  // 配置文件读取器
    {
    public:
        ConfigReader();
    };
}  // namespace /* namespace_name */
#endif  // CONFIG_READER_H_
