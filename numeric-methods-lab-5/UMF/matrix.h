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

class Vector
{
public:
    Vector();
    Vector(uint32_t size);
    Vector(uint32_t size, double val);
    Vector(const std::vector<double>& other);
    Vector(const std::vector<int>& other);

    Vector operator + (const Vector& other);
    Vector operator - (const Vector& other);
    Vector operator * (long double num) const;
    std::variant<Matrix, double> operator * (const Vector& right);
    double& operator [] (uint32_t idx);
    const double& operator [] (uint32_t idx) const;
    friend std::ostream& operator << (std::ostream& os, const Vector& v);
    friend std::istream& operator >> (std::istream& is, Vector& v);

    inline size_t GetDim() const {return buffer.size();}
    long double Norm();
    Vector Transposed() const;
    bool IsTransposed();
    std::vector<double> GetBuffer() {return buffer;}
    friend class Matrix;
private:
    bool is_transposed;
    std::vector<double> buffer;
    uint32_t dim;
};

class UnitMatrix : public Matrix
{
public:
    UnitMatrix(){}
    UnitMatrix(uint32_t);
};

#endif // MATRIX_H
