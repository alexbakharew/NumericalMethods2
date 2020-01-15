#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>
#include <variant>
#include "matrix.h"
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
    double& operator [] (uint32_t idx);
    const double& operator [] (uint32_t idx) const;
    friend std::ostream& operator << (std::ostream& os, const Vector& v);
    friend std::istream& operator >> (std::istream& is, Vector& v);

    inline size_t GetDim() const {return buffer.size();}
    double Norm();
    Vector Transposed() const;
    bool IsTransposed();
    std::vector<double> GetBuffer() const;
    std::variant<Matrix, double> operator * (const Vector& right);
private:
    bool is_transposed;
    std::vector<double> buffer;
    uint32_t dim;
};

#endif // VECTOR_H
