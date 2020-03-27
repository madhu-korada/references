#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
void setConfigValues( std::string warning_logic_yaml_file)
{
    cv::FileStorage fs;
    fs.open(warning_logic_yaml_file, cv::FileStorage::READ);

    cv::FileNode obj_filenode = fs["Parameters"];   
    
    float x_axis_threshold           = (double)(obj_filenode["x_axis_threshold"]);
    float y_axis_threshold           = (double)(obj_filenode["y_axis_threshold"]);

}


int main()
{
    std::string warning_logic_yaml_file = "fcw_radar.yaml";

    setConfigValues(warning_logic_yaml_file);

    std::cout << x_axis_threshold   << std::endl; 
}
