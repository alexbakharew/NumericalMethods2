#include <iostream>
#include <cmath>
#include "matrix.h"
#include "vector.h"
#include "equtation_solver.h"
Vector SimpleIteration::SolveEqutation(const Matrix& A, const Vector& b, long double epsilon)
{
    if(A.GetDim() != b.GetDim())
        return Vector(0);
    int dimension = A.GetDim();
    Matrix Alpha(dimension, 0);
    Vector Beta(dimension, 0);
    for(int i = 0; i < dimension; ++i)
    {
        Beta[i] = b[i] / A[i][i];
        for(int j = 0; j < dimension; ++j)
        {
            if(i == j)
                continue;
            Alpha[i][j] = - (A[i][j] / A[i][i]);
        }
    }
    long double coeff;
    if(Alpha.Norm() == 1)
        coeff = 1;
    else
        coeff = Alpha.Norm()/ (1 - Alpha.Norm());

    Vector curr_x = Beta + Alpha * Beta;
    long double curr_epsilon = (curr_x - Beta).Norm() * coeff;
    while(fabs(curr_epsilon) > epsilon)
    {
        Vector next_x = Beta + Alpha * curr_x;
        curr_epsilon = (next_x - curr_x).Norm() * coeff;
        curr_x = next_x;
    }
    return curr_x;
}

Vector Zeydel::SolveEqutation(const Matrix &A, const Vector &b, long double epsilon)
{
    if(A.GetDim() != b.GetDim())
        return Vector(0);
    int dimension = A.GetDim();
    Matrix Alpha(dimension, 0);
    Vector Beta(dimension, 0);
    for(int i = 0; i < dimension; ++i)
    {
        Beta[i] = b[i] / A[i][i];
        for(int j = 0; j < dimension; ++j)
        {
            if(i == j)
                continue;
            Alpha[i][j] = - (A[i][j] / A[i][i]);
        }
    }
    long double coeff;
    if(Alpha.Norm() == 1)
        coeff = 1;
    else
        coeff = Alpha.Norm()/ (1 - Alpha.Norm());

    Vector curr_x = Beta;
    long double curr_epsilon;
    do
    {
        Vector next_x(curr_x.GetDim());
        for(int i = 0; i < next_x.GetDim(); ++i)
        {
            next_x[i] += Beta[i];
            for(int l = 0; l < i; ++l)
            {
                next_x[i] += Alpha[i][l] * next_x[l];
            }
            for(int m = i; m < next_x.GetDim(); ++m)
            {
                next_x[i] += Alpha[i][m] * curr_x[m];
            }
        }
        curr_epsilon = coeff * (next_x - curr_x).Norm();
        curr_x = next_x;
    }
    while(fabs(curr_epsilon) > epsilon);
    return curr_x;
}
