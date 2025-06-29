#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
void printMatriXd(MatrixXd& test)
{
    std::cout<<"MatrixXd.rows()="<<test.rows() <<std::endl;
    std::cout<<"MatrixXd.cols()="<<test.cols() <<std::endl;
     for (size_t i = 0; i < test.rows(); i++)
     {
        for (size_t j = 0; j < test.cols(); j++)
        {
            std::cout<<test(i,j)<<std::endl;
        }
     }
}
void printMatriXd(Matrix3d& test)
{
    std::cout<<"Matrix3d.rows()="<<test.rows() <<std::endl;
    std::cout<<"Matrix3d.cols()="<<test.cols() <<std::endl;
     for (size_t i = 0; i < test.rows(); i++)
     {
        for (size_t j = 0; j < test.cols(); j++)
        {
            std::cout<<test(i,j)<<";";
        }
        std::cout<<std::endl;
     }
}
int main()
{
        // LiDAR->ego，再通过乘以extrinsicRPYFromIMU2ego的逆矩阵，变换到IMU坐标系
        // Matrix3d extrinsicRot{{0.999353, 0.0348689, 0.00884299},
        //                             {-0.0348982, 0.999386, 0.00318398},
        //                             {-0.00872654, -0.00349052, 0.999956}};

        // extrinsicRot<<-0.92496147, -0.37893334, -0.02925401,
        //                               0.37898535, -0.9253942, 0.00396077,
        //                              -0.02857236, -0.00742328, 0.99956416;
        // Matrix<int, 1, 6> a{{1, 2, 3, 4, 5, 6}};
        // MatrixXd a {
        //                         {1, 2, 3},
        //                         {4, 5, 6}
        //                         };
        // std::cout << a << std::endl;
Matrix<int, 1, 6> a(1, 2, 3, 4, 5, 6);
Matrix<int, 3, 1> b {1, 2, 3};
cout << a << "\n\n" << b << endl; 
        // Matrix<int, 3, 1> b {1, 2, 3};  
        // VectorXi v {{1, 2}};
        //     cout << v << endl;
        // std::cout<<"------------------"<<std::endl;
        // std::cout<< "\n\n" << b << std::endl;
      
        // std::cout<<extrinsicRot<<std::endl;
        std::cout<<"------------------"<<std::endl;
}

