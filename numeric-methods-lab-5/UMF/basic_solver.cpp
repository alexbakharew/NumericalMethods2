#include "basic_solver.h"
BasicSolver::BasicSolver(int N, int K, double l, int T, double a, MethodName(method))
{
    this->N = N;
    this->K = K;
    this->l = l;
    this->T = T;
    this->a = a;
    this->MethName = method;
}
void BasicSolver::InitMesh()
{
   mesh = std::vector<std::vector<double>>(K, std::vector<double>(N, 0.0));
   h = double(l) / N;
   tau = double(T) / K;
   sigma = a * a * tau / double(h * h);
   teta = .5;
   for(int i = 0; i < N; ++i)
   {
       mesh[K - 1][i] = initial_condition_t0(i * h);
   }
   ApprType = ApproximationType::Zero; // When few approximation types will be added, this line will be deleted
   if(ApprType == ApproximationType::Zero)
   {
       for(int i = 0; i < K - 1; ++i)
       {
           mesh[i][0] = boundary_condition_x0(i * tau);
           mesh[i][N - 1] = boundary_condition_xl(i * tau);
       }
   }
}
