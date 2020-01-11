#ifndef ParabolicSolver_H
#define ParabolicSolver_H
#include "basic_solver.h"
class ParabolicSolver : public BasicSolver
{

public:
    using BasicSolver::BasicSolver; // Explicitly inherit constructor from base class
    virtual void AnalyticSolve() const override; // we still need members definition even though we inherit them
    virtual void ExplicitSolve() const override;
    virtual void ImplicitSolve() const override;
    virtual void Crank_Nikolsn() const override;
protected:
    virtual double AnalyticFunction(double x, double t) const override;
    virtual double initial_condition_t0(double x) const override;
    virtual double boundary_condition_x0(double t) const override;
    virtual double boundary_condition_xl(double t) const override;

};
#endif // ParabolicSolver_H
