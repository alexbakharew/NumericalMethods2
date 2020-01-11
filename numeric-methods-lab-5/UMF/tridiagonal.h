#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H
#include "matrix.h"

class Tridiagonal
{
public:
    Tridiagonal(){}
    Tridiagonal(const Matrix& m);
    Vector SolveEqutation(const std::vector<double>& b);
    Vector SolveEqutation(const Vector& b);
    friend class Logger;
private:
    std::vector<std::vector<double>> coeffs;// tridiagonal matrix
    uint32_t dim;
};

#endif // TRIDIAGONAL_H
