#ifndef ELEPTICAL_SOLVER_H
#define ELEPTICAL_SOLVER_H
#include <vector>

class ElepticalSolver
{
public:
    ElepticalSolver(){}
    ElepticalSolver(double _N1, double _N2);
    bool InitMesh() const;
    void Solve();
private:
    double initial_condition_x_0(double x) const;
    double initial_condition_x_1(double x) const;
    double initial_condition_0_y(double y) const;
    double initial_condition_1_y(double y) const;
    double interpolate(double y_left, double y_right, double y_curr);
private:
        mutable std::vector<std::vector<double>> mesh;
        double N1, N2, h1, h2, epsilon;
};

#endif // ELEPTICAL_SOLVER_H
