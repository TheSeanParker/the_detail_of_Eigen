#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <GeographicLib/LocalCartesian.hpp>

int main() {

    std::string input_filename = "/home/deploy/Eigen/LLA2NED/fromENU2NED/0_gps_ins.txt";
    std::string output_filename = "/home/deploy/calmcar_LIO/calmcar_lio_slam/src/LogPose/0_gps_slam4d_data_NED222ENU.txt";
    
    std::ifstream input_file(input_filename);
    std::ofstream output_file(output_filename);

    if (!input_file.is_open()) {
        std::cout << "Error opening input file!" << std::endl;
        return -1;
    }
    
    if (!output_file.is_open()) {
        std::cout << "Error opening output file!" << std::endl;
        return -1;
    }

    bool first_flag = true;
    GeographicLib::LocalCartesian geoConverter;
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        std::vector<double> values;
        double value;
        
        // 读取所有数值
        while (iss >> value) {
            values.push_back(value);
        }
        
        double lat = values[1];
        double lon = values[2];
        double alt = values[3];

        if (first_flag) {
            first_flag = false;
            // 当前点的经纬度和高度，作为局部坐标系的原点
            // 初始化 LocalCartesian 对象，并设置原点
            geoConverter.Reset(lat, lon, alt);
        }

        // 转换为局部直角坐标系
        double x, y, z;
        geoConverter.Forward(lat, lon, alt, x, y, z);
        // geoConverter.Reverse()
        // 输出转换后的局部坐标
        std::cout << "Local Cartesian coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;

        // double offset_x = 0.049253;
        // double offset_y = 0.231776;
        // double offset_z = 0.066306;

        double offset_x = 0.0;
        double offset_y = 0.0;
        double offset_z = 0.0;

        values[1] = x + offset_x;
        values[2] = y + offset_y;
        values[3] = z + offset_z;

        // 补齐4原数
        double new_values[8] = {};
        new_values[0] = values[0];
        new_values[1] = values[1];
        new_values[2] = values[2];
        new_values[3] = values[3];
        new_values[4] = 0.0;
        new_values[5] = 0.0;
        new_values[6] = 0.0;
        new_values[7] = 1.0;
        
        output_file << std::fixed;
        output_file << std::setprecision(6) << new_values[0];
        output_file << std::setprecision(6);
        for (size_t i = 1; i < 8; ++i) {
            if (i != 0) output_file << " ";
            output_file << new_values[i];
        }
        output_file << "\n";

    }

    input_file.close();
    output_file.close();
    
    std::cout << "output: " << output_filename << std::endl;
 
    return 0;
}