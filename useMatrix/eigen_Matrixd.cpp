#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
//  LiDAR->ego，再通过乘以extrinsicRPYFromIMU2ego的逆矩阵，变换到IMU坐标系
//   extrinsicRot:  [0.999353, 0.0348689, 0.00884299,
//                                -0.0348982, 0.999386, 0.00318398,
//                                -0.00872654, -0.00349052, 0.999956]
//   extrinsicRPY:  [0.999353, 0.0348689, 0.00884299,
//                                -0.0348982, 0.999386, 0.00318398,
//                                -0.00872654, -0.00349052, 0.999956]
//   extrinsicRPYradian:  [-0.00349066, 0.00872665, -0.0349066]
int main()
{
        // LiDAR->ego，再通过乘以extrinsicRPYFromIMU2ego的逆矩阵，变换到IMU坐标系
        Matrix3d extrinsicRot;
        // extrinsicRot<<0.999353, 0.0348689, 0.00884299,
                                    // -0.0348982, 0.999386, 0.00318398,
                                    // -0.00872654, -0.00349052, 0.999956 ;
        extrinsicRot<<-0.92496147, -0.37893334, -0.02925401,
                                      0.37898535, -0.9253942, 0.00396077,
                                     -0.02857236, -0.00742328, 0.99956416;
    
        Vector3d demoRPY=extrinsicRot.eulerAngles(2,1,0);
        double rad2angle=57.29577;
        std::cout<<"demoRPY rad="<<demoRPY<<std::endl;
        std::cout<<"demoRPY degree="<<demoRPY*rad2angle<<std::endl;
        std::cout<<"yaw rad="<<demoRPY(0)<<std::endl;
        std::cout<<"yaw degree="<< rad2angle*demoRPY(0)<<std::endl;

    //     Eigen::Matrix3d  extrinsicRPYFromIMU2ego;
    //     extrinsicRPYFromIMU2ego<<1,  0,  0,
    //                                                                 0, -1, 0,
    //                                                                 0,  0, -1;
    //     Matrix3d FromLiDAR2IMU=(extrinsicRPYFromIMU2ego);
    // // std::cout<<"行列式的值="<<FromLiDAR2IMU.determinant()<<std::endl;
    // // 创建一个旋转矩阵（示例：绕Z轴旋转45°，Y轴30°，X轴60°）
    // Eigen::Matrix3f R = (Eigen::AngleAxisf(-0.0349066, Eigen::Vector3f::UnitZ())  * 
    //                                         Eigen::AngleAxisf(0.00872665, Eigen::Vector3f::UnitY())  * 
    //                                         Eigen::AngleAxisf(-0.00349066, Eigen::Vector3f::UnitX())).toRotationMatrix();    // X轴旋转60°
    // std::cout << "Rotation Matrix:\n" << R << std::endl;
    //     Vector3d demoRPY=FromLiDAR2IMU.eulerAngles(2,1,0);
    //     double rad2angle=57.29577;
    //     std::cout<<"demoRPY="<<demoRPY<<std::endl;

//    printMatriXd(FromLiDAR2IMU);
// 下面是同事用python库解析出来的，对于旋转矩阵是一样的，但是解析出的欧拉角是不同；但是结果是相同的！
// import numpy as np
// import math
// import scipy
// import scipy.spatial
// R=np.array([0.999353, 0.0348689, 0.00884299,
//             -0.0348982, 0.999386, 0.00318398,
//             -0.00872654, -0.00349052, 0.999956]).reshape(3,3)
// r:scipy.spatial.transform.Rotation = scipy.spatial.transform.Rotation.from_matrix(R)
// print(scipy.spatial.transform.Rotation.as_euler(r))
 // 还有清华使用的是
//  np.array(cpp_utils_ext.get_transform_from_RPYT(x, y, z, yaw, pitch, roll)).reshape(4, 4) 
}

