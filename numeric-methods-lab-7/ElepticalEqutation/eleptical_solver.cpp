#include "eleptical_solver.h"
#include <algorithm>
#include <cmath>
#include "vector.h"
#include "solution_saver.h"
double ElepticalSolver::initial_condition_x_0(double x) const
{
    return std::cos(x);
}

double ElepticalSolver::initial_condition_x_1(double x) const
{
    return 0;
}

double ElepticalSolver::initial_condition_0_y(double y) const
{
    return std::cos(y);
}

double ElepticalSolver::initial_condition_1_y(double y) const
{
    return 0;
}

ElepticalSolver::ElepticalSolver(int _N, double _eps) :
    N(_N)
{
    h = M_PI / 2 / N;
    epsilon = _eps;
}

bool ElepticalSolver::InitMesh() const
{
    try
    {
        mesh.resize(N);
        for(auto &line : mesh)
            line.resize(N);
    }
    catch(...)
    {
        return false;
    }

    for(int i = 0; i < N; ++i)
    {
        mesh[i][0] = initial_condition_0_y(i * h);
        mesh[i][N - 1] = initial_condition_1_y(i * h);
    }

    for(int j = 0; j < N; ++j)
    {
        mesh[0][j] = initial_condition_x_0(j * h);
        mesh[N - 1][j] = initial_condition_x_1(j * h);
    }
    return true;
}

double ElepticalSolver::interpolation_function(double y_left, double y_right, double x_curr) const
{
    return ((y_right - y_left) * x_curr) + y_left;
}

double ElepticalSolver::make_interpolation() const
{
    double u_k_max = -1; // Initial value
    for(int i = 1; i < N - 1; ++i)
    {
        for(int j = 1; j < N - 1; ++j)
        {
            mesh[i][j] = interpolation_function(mesh[i][0], mesh[i][N - 1], j * h);
        }
        u_k_max = std::max(u_k_max, *std::max_element(mesh[i].begin(), mesh[i].end()));
    }
    SolutionSaver::SaveResults(*this, "interpolation.txt");
    return u_k_max;
}
double ElepticalSolver::analytic_function(double x, double y) const
{
    return std::cos(x) * std::cos(y);
}
void ElepticalSolver::AnalyticSolution() const
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            mesh[i][j] = analytic_function(i * h, j * h);
        }
    }
}

void ElepticalSolver::LibmanSolution() const
{
    double u_k_max_prev = make_interpolation();
    double u_k_max = -1;
    int iters = 0;
    do
    {
        decltype (mesh) curr_mesh = mesh;
        for(int i = 1; i < N - 1; ++i)
        {
            for(int j = 1; j < N - 1; ++j)
            {
                curr_mesh[i][j] = .25 * (mesh[i][j + 1] + mesh[i][j - 1] + mesh[i + 1][j] + mesh[i - 1][j] + (h * h * mesh[i][j]));
            }
            u_k_max = std::max(u_k_max, *std::max_element(curr_mesh[i].begin() + 1, curr_mesh[i].end() - 1));
        }
        mesh = curr_mesh;
        ++iters;
        if(fabs(u_k_max - u_k_max_prev) >= epsilon)
            u_k_max_prev = u_k_max;
        else
            break;
    }while(true);
    std::cout << "Iterations = " << iters << std::endl;
}

void ElepticalSolver::ZeydelSolution() const
{
    double u_k_max_prev = make_interpolation();
    double u_k_max = 0;
    int iters = 0;
    do
    {
        decltype(mesh) curr_mesh = mesh;
        u_k_max_prev = u_k_max;
        for(int i = 1; i < N - 1; ++i)
        {
            for(int j = 1; j < N - 1; ++j)
            {
                curr_mesh[i][j] = .25 * (curr_mesh[i][j - 1] + mesh[i][j + 1] + curr_mesh[i + 1][j] + mesh[i - 1][j]) + (h * h * 0.5 * mesh[i][j]);
            }
            u_k_max = std::max(u_k_max, *std::max_element(curr_mesh[i].begin() + 1, curr_mesh[i].end() - 1));
        }
        mesh = curr_mesh;
        ++iters;
        if(fabs(u_k_max - u_k_max_prev) >= epsilon)
            u_k_max_prev = u_k_max;
        else
            break;
    } while(true);
    std::cout << "Iterations = " << iters << std::endl;
}

void ElepticalSolver::RelaxationSolution() const
{
    double relax_param = 1.3;
    double u_k_max_prev = make_interpolation();
    double u_k_max = 0;
    int iters = 0;
    do
    {
        decltype(mesh) curr_mesh = mesh;
        u_k_max_prev = u_k_max;
        for(int i = 1; i < N - 1; ++i)
        {
            for(int j = 1; j < N - 1; ++j)
            {
                curr_mesh[i][j] = relax_param * 0.25 * (curr_mesh[i][j - 1] + curr_mesh[i + 1][j] + mesh[i][j + 1] + mesh[i - 1][j]) -
                        relax_param * (1 - (1 / relax_param)) * mesh[i][j] + (2 * mesh[i][j] * relax_param * h * h * 0.25);
            }
            u_k_max = std::max(u_k_max, *std::max_element(curr_mesh[i].begin() + 1, curr_mesh[i].end() - 1));
        }
        mesh = curr_mesh;
        ++iters;
        if(fabs(u_k_max - u_k_max_prev) >= epsilon)
            u_k_max_prev = u_k_max;
        else
            break;
    } while(true);
    std::cout << "Iterations = " << iters << std::endl;
}
