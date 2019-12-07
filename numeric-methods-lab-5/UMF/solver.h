#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include <string>
class SolutionSaver;
class Solver
{
    friend class SolutionSaver;
public:
    Solver() {}
    Solver(int N, int K, double l, int T);
    void InitMesh();
    void ExplicitSolve();
    void ImplicitSolve();
private:
    double initial_condition_t0(double x);
    double boundary_condition_x0(double t);
    double boundary_condition_xl(double t0, double t1);

private:
    std::vector<std::vector<double>> mesh;
    int N, K, T, a;
    double h, tau, l;
};

class SolutionSaver
{
public:
    SolutionSaver(){}
    static bool SaveResults(const std::string &path, const Solver& slv);
};

#endif // SOLVER_H
