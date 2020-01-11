#include <cmath>
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
        mesh[K - 1][i] = initial_condition_t0(i * h) + second_layer_condition(i * h) * tau;
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

}

