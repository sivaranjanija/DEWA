#include "kalman_filter.h"


CKalmanFilter::CKalmanFilter() {}

CKalmanFilter::~CKalmanFilter() {}

//set function for kalman filter params
void CKalamnFilter::setKF(Eigen::MatrixXd &A_, Eigen::MatrixXd &B_, 
             Eigen::VectorXd &x_, Eigen::MatrixXd &P_,
             Eigen::MatrixXd &H_, Eigen::MatrixXd &R_, Eigen::MatrixXd &Q_)
{
  A_ = A_;
  B_ = B_;
  x_ = x_;
  P_ = P_;
  H_ = H_;
  R_ = R_;
  Q_ = Q_;
}

//predict step
void CKalmanFilter::predict(const Eigen::VectorXd u_) 
{
  //state transition matrix
  x_ = A_ * x_ + B_ * u_;

  //Update the covariance matrix using the process noise and state transition matrix
  MatrixXd At_ = A_.transpose();
  P_ = A_ * P_ * Ft_ + Q_;

}

//update step
void CKalmanFilter::update(const VectorXd &z)
{

  MatrixXd Ht_ = H_.transpose();
  MatrixXd PHt_ = P_ * Ht_;

  VectorXd y = z - H_ * x_;
  MatrixXd S = H_ * PHt_ + R_;
  K_ = PHt_ * S.inverse();

  //Update State
  x_ = x_ + (K_ * y);
  //Update covariance matrix
  long x_size = x_.size();
  MatrixXd I = MatrixXd::Identity(x_size, x_size);  
  P_ = (I - K_*H_) * P_;
}


