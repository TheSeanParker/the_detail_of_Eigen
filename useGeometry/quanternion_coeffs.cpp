#include <iostream>
#include <cmath>
using namespace std;
#include <Eigen/Geometry>// Eigen 几何模块
int main(int argc, char const *argv[])
{
    Eigen::Matrix3d rotation_matrix=Eigen::Matrix3d::Identity();
    Eigen::Quaterniond Q(2.0,0.0,0.0,0.0);
    Q.coeffs();
    Eigen::Quaterniond q = Eigen::Quaterniond ( rotation_matrix );
    // Eigen::Matrix3d rotation_matrix=Eigen::Matrix3d::Identity();
    q = Eigen::Quaterniond ( rotation_matrix );
    q=q*Q;
    cout<<"quaternion = \n"<<q.coeffs() <<endl;
    (q*Q).toRotationMatrix();
    return 0;
}
