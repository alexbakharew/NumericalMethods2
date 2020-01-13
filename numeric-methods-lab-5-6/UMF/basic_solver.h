#ifndef BASIC_SOLVER_H
#define BASIC_SOLVER_H
#include <vector>
#include <string>
#include "methods.h"
enum ApproximationType
{
    Zero = 0,
    First = 1,
    Second = 2,
    Third = 3
};

class BasicSolver// It is not a pure abstract class
{
    friend class SolutionSaver;
public:
    BasicSolver(){}
    explicit BasicSolver(int N, int K, double l, int T, double a, MethodName(method));
    virtual ~BasicSolver() {}
    void InitMesh();
    virtual void AnalyticSolve() const = 0;
    virtual void ExplicitSolve() const = 0;
    virtual void ImplicitSolve() const = 0;
    virtual void Crank_Nikolsn() const = 0;
protected:
    virtual double AnalyticFunction(double x, double t) const = 0;
    virtual double initial_condition_t0(double x) const = 0;
    virtual double boundary_condition_x0(double t) const = 0;
    virtual double boundary_condition_xl(double t) const = 0;

    mutable std::vector<std::vector<long double>> mesh;
    int N, K, T;
    double h, tau, l, a, sigma, teta;
    MethodName MethName;
    ApproximationType ApprType;

};

#endif // BASIC_SOLVER_H
