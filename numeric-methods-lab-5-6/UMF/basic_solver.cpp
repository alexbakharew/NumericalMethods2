#include "basic_solver.h"
BasicSolver::BasicSolver(int N, int K, double l, int T, double a, MethodName(method), double teta)
{
    this->N = N;
    this->K = K;
    this->l = l;
    this->T = T;
    this->a = a;
    this->teta = teta;
    this->MethName = method;
}
void BasicSolver::InitMesh()
{
   mesh = std::vector<std::vector<long double>>(K, std::vector<long double>(N, 0.0));
   h = double(l) / N;
   tau = double(T) / K;
   sigma = (a * a * tau) / (h * h);
   //teta = .5;
   for(int i = 0; i < N; ++i)
   {
       mesh[K - 1][i] = initial_condition_t0(i * h);
   }
   ApprType = ApproximationType::Zero; // When few approximation types will be added, this line will be deleted
   if(ApprType == ApproximationType::Zero)
   {
       for(int i = K - 2; i >= 0; --i)
       {
           mesh[i][0] = boundary_condition_x0(i * tau);
           mesh[i][N - 1] = boundary_condition_xl(i * tau);
       }
   }
}
