#ifndef BASICSOLVER_H
#define BASICSOLVER_H


class BasicSolver
{
public:
    BasicSolver(){};
    virtual ~BasicSolver() = 0;
    virtual void InitMesh() = 0;
    virtual void AnalyticSolve() const = 0;
};

#endif // BASICSOLVER_H
