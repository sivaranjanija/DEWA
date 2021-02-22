#include "extended_kalman_filter.h"


//constructor
CExtendedKalmanFilter::CExtendedKalmanFilter(int l, int m, int n, 
                Eigen::MatrixXd &A_, Eigen::MatrixXd &B_, Eigen::MatrixXd &C_,
                Eigen::VectorXd &u_, Eigen::VectorXd &y_, Eigen::VectorXd &x_,
                Eigen::MatrixXd &Q_, Eigen::MatrixXd &H_, Eigen::MatrixXd &R_) :
                CKalmanFilter(l, m, n, A_, B_, C_, u_, y_, x_, Q_, H_, R_){}

//destructor
CExtendedKalmanFilter::~CExtendedKalmanFilter() {}


//process function
void CExtendedKalmanFilter::setProcessFunction(std::function<Eigen::VectorXd(const Eigen::VectorXd& x,
                                                  const Eigen::VectorXd& u)> processFunction) 
{
  processFunction_ = processFunction;
}


//output function
void CExtendedKalmanFilter::setOutputFunction(std::function<Eigen::VectorXd(const Eigen::VectorXd& x)> outputFunction) 
{
  outputFunction_ = outputFunction;
}


//process jacobian
void CExtendedKalmanFilter::setProcessJacobian(std::function<Eigen::MatrixXd(const Eigen::VectorXd& x,
                                                  const Eigen::VectorXd& u)> processJacobian) 
{
  processJacobian_ = processJacobian;
}


//output jacobian
void CExtendedKalmanFilter::setOutputJacobian(std::function<Eigen::MatrixXd(const Eigen::VectorXd& x)> outputJacobian) 
{
  outputJacobian_ = outputJacobian;
}


//predict
void CExtendedKalmanFilter::predict(const Eigen::VectorXd u_) 
{
  xpred_ = processFunction_(xest_, u_);
  A_ = processJacobian_(xest_, u_);
  //Update the covariance matrix using the process noise and state transition matrix
  MatrixXd At_ = A_.transpose();
  P_ = A_ * P_ * At_ + Q_;
}


//update
void CExtendedKalmanFilter::update() 
{
  H_ = outputJacobian_(xest_);
  MatrixXd Ht_ = H_.transpose();
  MatrixXd PHt_ = P_ * Ht_;
  S_ = H_ * PHt_ + R_;

  //Kalman gain
  K_ = PHt_ * S_.inverse();
 
  //Update State
  xest_ = xpred_ + K_ * (y_ - outputFunction_(xpred_));
   
  //Update covariance matrix
  long x_size = xpred_.size();
  MatrixXd I = MatrixXd::Identity(x_size, x_size);  
  P_ = (I - K_* H_) * P_;
}



int main()
{
return 0;
}
