#include "kalman_filter.h"


//set function for kalman filter params
CKalmanFilter::CKalmanFilter(int l, int m, int n, 
                Eigen::MatrixXd &A_, Eigen::MatrixXd &B_, Eigen::MatrixXd &C_,
                Eigen::VectorXd &u_, Eigen::VectorXd &y_, Eigen::VectorXd &x_,
                Eigen::MatrixXd &Q_, Eigen::MatrixXd &H_, Eigen::MatrixXd &R_)
{
  l = l;
  m = m;
  n = n;
  A_ = A_;
  B_ = B_;
  C_ = C_;
  Q_ = Q_;
  H_ = H_;
  R_ = R_;
  u_ = u_;
  y_ = y_;
  xest_ = x_;
  xpred_ = x_;
}

CKalmanFilter::~CKalmanFilter() {}


//predict step
void CKalmanFilter::predict(const Eigen::VectorXd u_) 
{
  //state transition matrix
  xpred_ = A_ * xest_ + B_ * u_;

  //Update the covariance matrix using the process noise and state transition matrix
  MatrixXd At_ = A_.transpose();
  P_ = A_ * P_ * At_ + Q_;

}

//update step
void CKalmanFilter::update(const VectorXd &z)
{

  MatrixXd Ht_ = H_.transpose();
  MatrixXd PHt_ = P_ * Ht_;
  
  //Innovation
  VectorXd y = z - H_ * xpred_;

  S_ = H_ * PHt_ + R_;

  //Kalman gain
  K_ = PHt_ * S_.inverse();

  //Update State
  xest_ = xpred_ + (K_ * y);
  //Update covariance matrix
  long x_size = xpred_.size();
  MatrixXd I = MatrixXd::Identity(x_size, x_size);  
  P_ = (I - K_* H_) * P_;
}

int main()
{
 return 0;
}


