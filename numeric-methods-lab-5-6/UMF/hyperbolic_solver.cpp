#include <cmath>
#include "matrix.h"
#include "tridiagonal.h"
#include "hyperbolic_solver.h"
double HyperbolicSolver::AnalyticFunction(double x, double t) const
{
    return std::cos(x) * std::sin(2 * t);
}

void HyperbolicSolver::AnalyticSolve() const
{
    for(int i = 0; i < K; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            mesh[i][j] = AnalyticFunction(j * h, i * tau);
        }
    }
}

double HyperbolicSolver::second_layer_condition(double x) const
{
    return 2 * std::cos(x);
}

double HyperbolicSolver::initial_condition_t0(double t) const
{
    return 0;
}

double HyperbolicSolver::boundary_condition_x0(double t) const
{
    return std::sin(2 * t);
}

double HyperbolicSolver::boundary_condition_xl(double t) const
{
    return - std::sin(2 * t);
}

void HyperbolicSolver::init_second_layer() const
{
    for(int i = 0; i < N; ++i)
    {
        mesh[K - 2][i] = initial_condition_t0(i * h) + second_layer_condition(i * h) * tau;
    }
}

void HyperbolicSolver::ExplicitSolve() const
{
    init_second_layer();
    for(int i = K - 2; i >= 0; --i)
    {
        for(int j = 1; j < N - 1; ++j)
        {
            mesh[i][j] = sigma * (mesh[i + 1][j + 1] - 2 * mesh[i + 1][j] + mesh[i + 1][j - 1]) + 5 * mesh[i + 1][j] - mesh[i + 2][j];
        }
    }
}

void HyperbolicSolver::ImplicitSolve() const
{
    double a = sigma, c = sigma;
    double b = 2 * sigma + 1;
    for(int i = K - 3; i >= 0; --i)
    {
        Matrix matrix(N, 0);
        Vector res(N);
        for(int j = 0; j < N; ++j)
        {

            if(j == 0)
            {
                matrix[0][0] = b;
                matrix[0][1] = c;
                res[0] = - (mesh[i + 1][0]) + sigma * boundary_condition_x0(i * tau);
            }
            else if(j == N - 1)
            {
                matrix[N - 1][N - 2] = a;
                matrix[N - 1][N - 1] = b;
                res[N - 1] = - (mesh[i + 1][N - 1] + sigma * boundary_condition_xl(i * tau));
            }
            else
            {
                matrix[j][j - 1] = a;
                matrix[j][j] = b;
                matrix[j][j + 1] = c;
                res[j] = mesh[i + 1][j] * (- 2 - 3 * tau) + mesh[i + 2][j];
            }
        }
        Tridiagonal tri_mat = matrix;
        auto solution = tri_mat.SolveEqutation(res);
        for(int k = 0; k < N; ++k)
        {
            mesh[i][k] = solution[k];
        }
    }
}

