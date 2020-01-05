#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "parabolic_solver.h"
#include "matrix.h"
#include "tridiagonal.h"
Solver::Solver(int N, int K, double l, int T, double a, MethodName(method))
{
    this->N = N;
    this->K = K;
    this->l = l;
    this->T = T;
    this->a = a;
    this->MethName = method;
}

void Solver::InitMesh()
{
   mesh = std::vector<std::vector<double>>(K, std::vector<double>(N, 0.0));
   h = double(l) / N;
   tau = double(T) / K;
   teta = a * a * tau / double(h * h);
   for(int i = 0; i < N; ++i)
   {
       mesh[K - 1][i] = initial_condition_t0(i * h);
   }
   ApprType = ApproximationType::Zero; // When few approximation types will be added, this line will be deleted
   if(ApprType == ApproximationType::Zero)
   {
       for(int i = 0; i < K - 1; ++i)
       {
           mesh[i][0] = boundary_condition_x0(i * tau);//tau ?
           mesh[i][N - 1] = boundary_condition_xl(i * tau);// tau ?
       }
   }
}

double Solver::initial_condition_t0(double x) const
{
    return std::cos(x);
}

double Solver::boundary_condition_x0(double t) const
{
    return std::exp(- a * t);
}

double Solver::boundary_condition_xl(double t) const
{
    return std::exp(- a * t);
}

double Solver::AnalyticFunction(double x, double t) const
{
    return std::exp(- a * t) * std::cos(x);
}

void Solver::AnalyticSolve() const
{
    for(int i = K - 2; i >= 0; --i)
    {
        for(int j = 0; j < N; ++j)
        {
            mesh[i][j] = AnalyticFunction(j * h, i * tau);
        }
    }
}

void Solver::ExplicitSolve() const
{
    for(int i = K - 2; i >= 0; --i)
    {
        for(int j = 1; j < N - 1; ++j)
        {
            mesh[i][j] = teta * mesh[i + 1][j + 1] + (1 - 2 * teta) * mesh[i + 1][j] + teta * mesh[i + 1][j - 1];
            //            if(ApprType == ApproximationType::Zero)
            //            {
            //                mesh[i][0] = boundary_condition_x0(i * h);
            //                mesh[i][N - 1] = boundary_condition_xl(i * h);
            //            }
        }
    }
}
void Solver::ImplicitSolve() const
{
    double a = teta, c = teta;
    double b = - (1 + 2 * teta);

    for(int i = K - 2; i >= 0; --i)
    {
        Matrix matrix(N, 0);
        Vector res(N);
        for(int j = 0; j < N; ++j)
        {
            if(j == 0)
            {
                matrix[0][0] = b;
                matrix[0][1] = c;
                res[0] = - (mesh[i + 1][0]) + teta * boundary_condition_x0(i * tau);
            }
            else if(j == N - 1)
            {
                matrix[N - 1][N - 2] = a;
                matrix[N - 1][N - 1] = b;
                res[N - 1] = - (mesh[i + 1][N - 1] + teta * boundary_condition_xl(i * tau));
            }
            else
            {
                matrix[j][j - 1] = a;
                matrix[j][j] = b;
                matrix[j][j + 1] = c;
                res[j] = - mesh[i + 1][j];
            }
        }
        Tridiagonal tri_mat = matrix;
        auto solution = tri_mat.SolveEqutation(res.GetBuffer());
        auto tmp = solution.GetBuffer();
        for(int k = 0; k < N; ++k)
        {
            mesh[i][k] = tmp[k];
        }
    }
}
void Solver::Crank_Nikolsn() const
{
    double a = teta, c = teta;
    double b = - (1 + 2 * teta);

    for(int i = K - 2; i >= 0; --i)
    {
        Matrix matrix(N, 0);
        Vector res(N);
        for(int j = 0; j < N; ++j)
        {
            if(j == 0)
            {
                matrix[0][0] = b;
                matrix[0][1] = c;
                res[0] = - (mesh[i + 1][0]) + teta * boundary_condition_x0(i * tau);
            }
            else if(j == N - 1)
            {
                matrix[N - 1][N - 2] = a;
                matrix[N - 1][N - 1] = b;
                res[N - 1] = - (mesh[i + 1][N - 1] + teta * boundary_condition_xl(i * tau));
            }
            else
            {
                matrix[j][j - 1] = a;
                matrix[j][j] = b;
                matrix[j][j + 1] = c;
                res[j] = - (mesh[i + 1][j] + teta * tau) /*+ (1 - teta) * )*/;
            }
        }
        Tridiagonal tri_mat = matrix;
        auto solution = tri_mat.SolveEqutation(res.GetBuffer());
        auto tmp = solution.GetBuffer();
        for(int k = 0; k < N; ++k)
        {
            mesh[i][k] = tmp[k];
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
    output << slv.l << " " << slv.T  << " " << slv.a << std::endl;
    for(size_t i = 0; i < slv.K; ++i)
    {
        for(size_t j = 0; j < slv.N; ++j)
        {
            auto tmp = slv.mesh[i][j];
            output << tmp << " ";
        }
        output << std::endl;
    }
    return true;
}
