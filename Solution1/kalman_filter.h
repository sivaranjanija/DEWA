#include "Eigen/Dense"
#include <iostream>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

class CKalmanFilter
{
protected:

  //dimensions l-number of input signals, m-number of measured values, dimension of state vector
  int l, m, n;
 
  //input and output vector
  Eigen::VectorXd u_;
  Eigen::VectorXd y_;

  //system matrices A_ n*n, B_ n*1
  Eigen::MatrixXd A_;
  Eigen::MatrixXd B_;
 

  //state vector
  Eigen::VectorXd x_;

  //state covariance matrix n*n
  Eigen::MatrixXd P_;

  //process covariance matrix n*n
  Eigen::MatrixXd Q_;

  //measurement matrix m*n
  Eigen::MatrixXd H_;

  //measurement covariance matrix m*m
  Eigen::MatrixXd R_;

  //kalman gain matrix n*m
  Eigen::MatrixXd K_;

public:

  CKalmanFilter();
  ~CKalmanFilter();

  void setKF(Eigen::MatrixXd &A_, Eigen::MatrixXd &B_,
             Eigen::VectorXd &x_, Eigen::MatrixXd &P_,
             Eigen::MatrixXd &H_, Eigen::MatrixXd &R_, Eigen::MatrixXd &Q_);

  
  void predict(Eigen::VectorXd u_);

  void update(const Eigen::VectorXd &z);

};
