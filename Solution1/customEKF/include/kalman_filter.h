#include <Eigen/Dense>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

class CKalmanFilter
{
protected:

  //dimensions l-number of input signals, m-number of measured values, dimension of state vector
  int l, m, n;
 
  //input and output vector u_l, v_m;
  Eigen::VectorXd u_;
  Eigen::VectorXd y_;
  
  //predicted state vector, estimated state vector dim n
  Eigen::VectorXd xpred_;
  Eigen::VectorXd xest_;

  //system matrices A_ n*n, B_ n*1, C_ m*n
  Eigen::MatrixXd A_;
  Eigen::MatrixXd B_;
  Eigen::MatrixXd C_;


  //state covariance matrix n*n
  Eigen::MatrixXd P_;

  //process covariance matrix n*n
  Eigen::MatrixXd Q_;

  //measurement matrix m*n
  Eigen::MatrixXd H_;

  //measurement covariance matrix m*m
  Eigen::MatrixXd R_;
  
  //innovation covariance matrix m*m
  Eigen::MatrixXd S_;

  //kalman gain matrix n*m
  Eigen::MatrixXd K_;

public:

  CKalmanFilter(int l, int m, int n, 
                Eigen::MatrixXd &A_, Eigen::MatrixXd &B_, Eigen::MatrixXd &C_,
                Eigen::VectorXd &u_, Eigen::VectorXd &y_, Eigen::VectorXd &x_,
                Eigen::MatrixXd &Q_, Eigen::MatrixXd &H_, Eigen::MatrixXd &R_);
  ~CKalmanFilter();

  
  virtual void predict(Eigen::VectorXd u_);

  void update(const Eigen::VectorXd &z);

};
