#ifndef ELEPTICAL_SOLVER_H
#define ELEPTICAL_SOLVER_H
#include <vector>
class SolutionSaver;
class ElepticalSolver
{
    friend class SolutionSaver;
public:
    ElepticalSolver(){}
    ElepticalSolver(int N, double _eps);
    bool InitMesh() const;
    void LibmanSolution() const;
    void ZeydelSolution() const;
    void AnalyticSolution() const;
    void RelaxationSolution() const;
private:
    double analytic_function(double x, double y) const;
    double initial_condition_x_0(double x) const;
    double initial_condition_x_1(double x) const;
    double initial_condition_0_y(double y) const;
    double initial_condition_1_y(double y) const;
    double interpolation_function(double y_left, double y_right, double x_curr) const;
    double make_interpolation() const;
private:
        mutable std::vector<std::vector<double>> mesh;
        double N, h, epsilon;
};

#endif // ELEPTICAL_SOLVER_H
