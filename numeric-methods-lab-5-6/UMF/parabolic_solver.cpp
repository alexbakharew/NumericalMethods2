#include <cmath>
#include <iostream>
#include "parabolic_solver.h"
#include "matrix.h"
#include "tridiagonal.h"
double ParabolicSolver::initial_condition_t0(double x) const
{
    return std::cos(x);
}

double ParabolicSolver::boundary_condition_x0(double t) const
{
    return std::exp(- a * t);
}

double ParabolicSolver::boundary_condition_xl(double t) const
{
    return - std::exp(- a * t);
}

double ParabolicSolver::AnalyticFunction(double x, double t) const
{
    return std::exp(- a * t) * std::cos(x);
}

void ParabolicSolver::AnalyticSolve() const
{
    for(int i = K - 1; i >= 0; --i)
    {
        for(int j = 0; j < N; ++j)
        {
            mesh[i][j] = AnalyticFunction(j * h, i * tau);
        }
    }
}

void ParabolicSolver::ExplicitSolve() const
{
    for(int i = K - 2; i >= 0; --i)
    {
        for(int j = 1; j < N - 1; ++j)
        {
            mesh[i][j] = a * sigma * (mesh[i + 1][j + 1] - 2 * mesh[i + 1][j] + mesh[i + 1][j - 1]) + mesh[i + 1][j];
            //            if(ApprType == ApproximationType::Zero)
            //            {
            //                mesh[i][0] = boundary_condition_x0(i * h);
            //                mesh[i][N - 1] = boundary_condition_xl(i * h);
            //            }
        }
    }
}
void ParabolicSolver::ImplicitSolve() const
{
    double a1 = sigma * a, c1 = sigma * a;
    double b1 = - (1 + 2 * sigma * a);

    for(int i = K - 2; i >= 0; --i)
    {
        Matrix matrix(N, 0);
        Vector res(N);
        for(int j = 0; j < N; ++j)
        {
            if(j == 0)
            {
                matrix[0][0] = b1;
                matrix[0][1] = c1;
                res[0] = - ((mesh[i + 1][0]) + sigma * boundary_condition_x0(i * tau));
            }
            else if(j == N - 1)
            {
                matrix[N - 1][N - 2] = a1;
                matrix[N - 1][N - 1] = b1;
                res[N - 1] = - (mesh[i + 1][N - 1] + sigma * boundary_condition_xl(i * tau));
            }
            else
            {
                matrix[j][j - 1] = a1;
                matrix[j][j] = b1;
                matrix[j][j + 1] = c1;
                res[j] = - mesh[i + 1][j];
            }
        }
        Tridiagonal tri_mat = matrix;
        auto solution = tri_mat.SolveEqutation(res);
        for(int k = 1; k < N - 1; ++k)
        {
            mesh[i][k] = solution[k];
        }
        //std::copy(solution.GetBuffer().begin() + 1, solution.GetBuffer().end() - 1, mesh[i].begin());

    }
}
void ParabolicSolver::Crank_Nikolsn() const
{
    double a1 = - teta * sigma * a, c1 = - teta * sigma * a;
    double b1 = (1 + 2 * teta * sigma * a);
    for(int i = K - 2; i >= 0; --i)
    {
        Matrix matrix(N, 0);
        Vector res(N);
        for(int j = 0; j < N; ++j)
        {

            if(j == 0)
            {
                matrix[0][0] = b1;
                matrix[0][1] = c1;
                res[0] = - (mesh[i + 1][0]) + sigma * boundary_condition_x0(i * tau);
            }
            else if(j == N - 1)
            {
                matrix[N - 1][N - 2] = a1;
                matrix[N - 1][N - 1] = b1;
                res[N - 1] = - (mesh[i + 1][N - 1] + sigma * boundary_condition_xl(i * tau));
            }
            else
            {
                double explicit_part = (mesh[i + 1][j + 1] - 2 * mesh[i + 1][j] + mesh[i + 1][j - 1]);
                matrix[j][j - 1] = a1;
                matrix[j][j] = b1;
                matrix[j][j + 1] = c1;
                res[j] = (mesh[i + 1][j] + (1 - teta) * a * explicit_part);
            }
        }
        Tridiagonal tri_mat = matrix;
        auto solution = tri_mat.SolveEqutation(res.GetBuffer());
        auto tmp = solution.GetBuffer();
        for(int k = 1; k < N - 1; ++k)
        {
            mesh[i][k] = tmp[k];
        }
    }
}

