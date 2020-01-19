#include <cmath>
#include "matrix.h"
#include "tridiagonal.h"
#include "hyperbolic_solver.h"
double HyperbolicSolver::AnalyticFunction(double x, double t) const
{
    return std::sin(x - a * t);
}

void HyperbolicSolver::AnalyticSolve() const
{
    for(int i = K - 1; i > 0; --i)
    {
        for(int j = 0; j < N; ++j)
        {
            mesh[i][j] = AnalyticFunction(j * h, i * tau);
        }
    }
}

double HyperbolicSolver::boundary_condition_x0(double t) const
{
    return - std::sin(a * t);
}

double HyperbolicSolver::boundary_condition_xl(double t) const
{
    return std::sin(a * t);
}

double HyperbolicSolver::initial_condition_t0(double x) const
{
    return std::sin(x);
}

double HyperbolicSolver::second_layer_condition(double x) const
{
    return - a * std::cos(x);
}
void HyperbolicSolver::init_second_layer() const
{
    for(int i = 1; i < N - 1; ++i)
    {
        mesh[K - 2][i] = initial_condition_t0(i * h) + second_layer_condition(i * h) * tau - (a * a * tau * tau * 0.5 * std::sin(i * h));
    }
}

void HyperbolicSolver::ExplicitSolve() const
{
    init_second_layer();
    for(int i = K - 3; i >= 0; --i)
    {
        for(int j = 1; j < N - 1; ++j)
        {
            mesh[i][j] = sigma * (mesh[i + 1][j + 1]) + 2 * mesh[i + 1][j] * (- sigma + 1) + sigma * (mesh[i + 1][j - 1]) - mesh[i + 2][j];
        }
    }
}

void HyperbolicSolver::ImplicitSolve() const
{
    init_second_layer();
    double a = sigma, c = sigma;
    double b = - 2 * sigma - 1;
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
                res[0] = (- 2 * mesh[i + 1][j] + mesh[i + 2][j]) - sigma * boundary_condition_x0(i * tau);
            }
            else if(j == N - 1)
            {
                matrix[N - 1][N - 2] = a;
                matrix[N - 1][N - 1] = b;
                res[N - 1] = (- 2 * mesh[i + 1][j] + mesh[i + 2][j]) - sigma * boundary_condition_xl(i * tau);
            }
            else
            {
                matrix[j][j - 1] = a;
                matrix[j][j] = b;
                matrix[j][j + 1] = c;
                res[j] = - 2 * mesh[i + 1][j] + mesh[i + 2][j];
            }
        }
        Tridiagonal tri_mat = matrix;
        auto solution = tri_mat.SolveEqutation(res);
        for(int k = 1; k < N - 1; ++k)
        {
            mesh[i][k] = solution[k];
        }
    }
}

