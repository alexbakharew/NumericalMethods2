#include "solver.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
Solver::Solver(int N, int K, double l, int T)
{
    this->N = N;
    this->K = K;
    this->l = l;
    this->T = T;
    this->a = 1;
}

void Solver::InitMesh()
{
   mesh = std::vector<std::vector<double>>(K, std::vector<double>(N, -10000));
   h = double(l) / N;
   tau = double(T) / K;
   for(int i = 0; i < N; ++i)
   {
       mesh[K - 1][i] = initial_condition_t0(i * h);
   }
   for(int i = K - 1; i >= 0; --i)
   {
       mesh[i][0] = boundary_condition_x0(i * tau);
   }
   for(int i = K - 1; i >= 0; --i)
   {
       mesh[i][N - 1] = boundary_condition_xl((i - 1) * h, i * h);
   }
}

double Solver::initial_condition_t0(double x)
{
    return 0.0;
}

double Solver::boundary_condition_x0(double t)
{
    return sin(t);
}

double Solver::boundary_condition_xl(double t0, double t1)
{
    return -(sin(t0) + sin(t1)) / h;
}

void Solver::ExplicitSolve()
{
    for(int i = K - 2; i >= 0; --i)
    {
        for(int j = 1; j < N - 1; ++j)
        {
            mesh[i][j] = (a * a * (mesh[i + 1][j + 1] - 2 * mesh[i + 1][j] + mesh[i + 1][j - 1]) * tau / h * h) + mesh[i + 1][j];
        }
    }
}

bool SolutionSaver::SaveResults(const std::string &path, const Solver &slv)
{
    std::fstream output(path, std::ios::out);
    if(!output.is_open())
        return false;
    output << std::setprecision(3) << std::fixed;
    output << slv.N << " " << slv.K << std::endl;
    output << slv.l << " " << slv.T  << std::endl;
    for(int i = 0; i < slv.K; ++i)
    {
        for(int j = 0; j < slv.N; ++j)
        {
            auto tmp = slv.mesh[i][j];
            output << tmp << " ";
        }
        output << std::endl;
    }
    return true;
}
