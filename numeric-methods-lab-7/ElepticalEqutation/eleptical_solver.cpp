#include "eleptical_solver.h"
#include <algorithm>
#include <cmath>
double ElepticalSolver::initial_condition_x_0(double x) const
{
    return x;
}

double ElepticalSolver::initial_condition_x_1(double x) const
{
    return x + 1;
}

double ElepticalSolver::initial_condition_0_y(double y) const
{
    return y;
}

double ElepticalSolver::initial_condition_1_y(double y) const
{
    return y + 1;
}

ElepticalSolver::ElepticalSolver(double _N1, double _N2) :
    N1(_N1), N2(_N2)
{
    h1 = 1.0 / N1;
    h2 = 1.0 / N2;
    epsilon = 0.1;
}

bool ElepticalSolver::InitMesh() const
{
    try
    {
        mesh.resize(N1);
        for(auto &line : mesh)
            line.resize(N2);
    }
    catch(...)
    {
        return false;
    }

    for(int i = 0; i < N1; ++i)
    {
        mesh[i][0] = initial_condition_0_y(i * h1);
        mesh[i][N2 - 1] = initial_condition_1_y(i * h1);
    }

    for(int j = 0; j < N2; ++j)
    {
        mesh[0][j] = initial_condition_x_0(j * h2);
        mesh[N2 - 1][j] = initial_condition_x_1(j * h2);
    }
    return true;
}

void ElepticalSolver::Solve()
{
    double u_k_max_prev = 0; // Initial value
    for(int i = 1; i < N1 - 1; ++i)
    {
        for(int j = 1; j < N2 - 1; ++j)
        {
            mesh[i][j] = interpolate(mesh[i][0], mesh[i][N2 - 1], j * h2);
        }
        u_k_max_prev = std::max(u_k_max_prev, *std::max_element(mesh[i].begin(), mesh[i].end()));
    }
    double u_k_max = 0;
    while(abs(u_k_max - u_k_max_prev) >= epsilon)
    {
        u_k_max_prev = u_k_max;
        for(int i = 1; i < N1 - 1; ++i)
        {
            for(int j = 1; j < N2 - 1; ++j)
            {
                mesh[i][j] = (mesh[i + 1][j] * h2 *h2 - mesh[i - 1][j] * h2 * h2) +
                        (mesh[i][j - 1] * h1 * h1 + mesh[i][j + 1] * h1 * h1);
            }
            u_k_max = std::max(u_k_max, *std::max_element(mesh[i].begin(), mesh[i].end()));
        }
    }

}
