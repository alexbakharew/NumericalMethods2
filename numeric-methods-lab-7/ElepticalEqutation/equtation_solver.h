#ifndef SIMPLEITERATION_H
#define SIMPLEITERATION_H
#include <iostream>
#include "matrix.h"
class SimpleIteration
{
public:
    SimpleIteration(){}
    ~SimpleIteration(){}
    static Vector SolveEqutation(const Matrix& A, const Vector& b, long double epsilon);
};

class Zeydel
{
public:
    Zeydel(){}
    ~Zeydel(){}
    static Vector SolveEqutation(const Matrix& A, const Vector& b, long double epsilon);
};

#endif // SIMPLEITERATION_H
