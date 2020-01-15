#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <cassert>
class Vector;
class Matrix
{
public:
    Matrix(){}
    Matrix(const Matrix& copy);
    Matrix(uint32_t size);
    Matrix(uint32_t size, double val);
    Matrix(const std::vector<Vector>, size_t dim);
    Matrix(const std::vector<std::vector<double>>& m);

    ~Matrix(){}

    friend std::ostream& operator << (std::ostream& os, const Matrix& m);
    friend std::istream& operator >> (std::istream& is, Matrix& m);
    void operator = (const Matrix& other);
    Matrix operator + (const Matrix& other) const;
    void operator += (const Matrix& other);
    Matrix operator - (const Matrix& other) const;
    Matrix operator * (const Matrix& other) const;
    Matrix operator * (double val) const;
    Vector operator * (const Vector& other) const;
    Matrix operator / (double val) const;
    const std::vector<double>& operator[] (uint32_t idx) const;
    std::vector<double>& operator[] (uint32_t idx);

    inline uint32_t GetDim() const {return dim;}
    void Permutation(Vector P);
    long double Norm();
    Matrix Transposing() const;
    friend class Logger;
//    friend class Vector;
protected:
    std::vector<std::vector<double>> matrix;
    uint32_t dim;
};
#endif // MATRIX_H
