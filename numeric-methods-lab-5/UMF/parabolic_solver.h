#ifndef ParabolicSolver_H
#define ParabolicSolver_H
#include <vector>
#include <string>
#include "methods.h"
class SolutionSaver;
enum ApproximationType
{
    Zero = 0,
    First = 1,
    Second = 2,
    Third = 3
};

class ParabolicSolver
{
    friend class SolutionSaver;
public:
    ParabolicSolver() {}
    ParabolicSolver(int N, int K, double l, int T, double a, MethodName(method));
    void InitMesh();
    void AnalyticSolve() const;
    void ExplicitSolve() const;
    void ImplicitSolve() const;
    void Crank_Nikolsn() const;
private:
    double AnalyticFunction(double x, double t) const;
    double initial_condition_t0(double x) const;
    double boundary_condition_x0(double t) const;
    double boundary_condition_xl(double t) const;

private:
    mutable std::vector<std::vector<double>> mesh;
    int N, K, T;
    double h, tau, l, a, sigma, teta;
    MethodName MethName;
    ApproximationType ApprType;
};

class SolutionSaver
{
public:
    SolutionSaver(){}
    static bool SaveResults(const std::string &path, const ParabolicSolver& slv);
};

#endif // ParabolicSolver_H
