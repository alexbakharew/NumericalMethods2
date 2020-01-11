#ifndef HYPERBOLICSOLVER_H
#define HYPERBOLICSOLVER_H
#include "basic_solver.h"
class HyperbolicSolver : public BasicSolver
{
public:
    using BasicSolver::BasicSolver;
    virtual void AnalyticSolve() const override;
    virtual void ExplicitSolve() const override;
    virtual void ImplicitSolve() const override;
    void Crank_Nikolsn() = delete;
protected:
    virtual double AnalyticFunction(double x, double t) const override;
    virtual double initial_condition_t0(double x) const override;
    virtual double boundary_condition_x0(double t) const override;
    virtual double boundary_condition_xl(double t) const override;
private:
    void init_second_layer() const;
    double second_layer_condition(double x) const;
};

#endif // HYPERBOLICSOLVER_H
