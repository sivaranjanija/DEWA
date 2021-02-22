#include "kalman_filter.h"

class CExtendedKalmanFilter : public CKalmanFilter
{
private:

  // ProcessFunction()
  std::function<Eigen::VectorXd(const Eigen::VectorXd & x, const Eigen::VectorXd & u)> processFunction_;

  //OutputFunction()
  std::function<Eigen::VectorXd(const Eigen::VectorXd & x)> outputFunction_;

  //process Jacobian
  std::function<Eigen::MatrixXd(const Eigen::VectorXd & x, const Eigen::VectorXd & u)> processJacobian_;
  
  //output Jacobian
  std::function<Eigen::MatrixXd(const Eigen::VectorXd & x)> outputJacobian_;

public:
  CExtendedKalmanFilter(int l, int m, int n, 
                Eigen::MatrixXd &A_, Eigen::MatrixXd &B_, Eigen::MatrixXd &C_,
                Eigen::VectorXd &u_, Eigen::VectorXd &y_, Eigen::VectorXd &x_,
                Eigen::MatrixXd &Q_, Eigen::MatrixXd &H_, Eigen::MatrixXd &R_);
  ~CExtendedKalmanFilter();
  
   void setProcessFunction(std::function<Eigen::VectorXd(const Eigen::VectorXd& x,
                                                  const Eigen::VectorXd& u)> processFunction);

   void setOutputFunction(std::function<Eigen::VectorXd(const Eigen::VectorXd& x)> outputFunction);

   void setProcessJacobian(std::function<Eigen::MatrixXd(const Eigen::VectorXd& x,
                                                  const Eigen::VectorXd& u)> processJacobian);

   void setOutputJacobian(std::function<Eigen::MatrixXd(const Eigen::VectorXd& x)> outputJacobian);

  
  //predict
  virtual void predict(Eigen::VectorXd u_);

  //update
  void update();

};
