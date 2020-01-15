#ifndef ELEPTICAL_SOLVER_H
#define ELEPTICAL_SOLVER_H
#include <vector>
class SolutionSaver;
class ElepticalSolver
{
    friend class SolutionSaver;
public:
    ElepticalSolver(){}
    ElepticalSolver(double _N1, double _N2);
    bool InitMesh() const;
    void LibmanSolution() const;
    void SLAESolution(bool is_zeydel) const;
    void AnalyticSolution() const;
    //void SimpleIterationSolution() const;
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
        double N1, N2, h1, h2, epsilon;
};

#endif // ELEPTICAL_SOLVER_H
