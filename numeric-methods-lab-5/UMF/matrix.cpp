#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
Matrix::Matrix(const Matrix& m)
{
    dim = m.dim;
    matrix = m.matrix;
}

Matrix::Matrix(uint32_t size) : dim(size)
{
    matrix = std::vector<std::vector<double>> (dim, std::vector<double>(dim, 0));
}

Matrix::Matrix(uint32_t size, double val)
{
    dim = size;
    matrix = std::vector<std::vector<double>> (dim, std::vector<double>(dim, val));
}

Matrix::Matrix(const std::vector<Vector> v, size_t size) : dim(size)
{
    matrix.resize(dim);
    for(int i = 0; i < dim; ++i)
    {
        if(dim != v[i].GetDim())
        {
            matrix.resize(0);
            return;
        }
        matrix[i] = v[i].buffer;
    }
}

std::vector<double>& Matrix::operator [](uint32_t idx)
{
    return matrix[idx];
}

const std::vector<double>& Matrix::operator [] (uint32_t idx) const
{
    return matrix[idx];
}

void Matrix::operator = (const Matrix& rval)
{
    matrix = rval.matrix;
    dim = rval.dim;
}

std::ostream& operator << (std::ostream& os, const Matrix& m)
{
    auto size = m.matrix.size();
    for(uint32_t i = 0; i < size; ++i)
    {
        for(uint32_t j = 0; j < size; ++j)
        {
            os << std::setprecision(3) << m[i][j];
            os << "    ";
        }
        os << "\n";
    }
    return os;
}

std::istream& operator >> (std::istream& is, Matrix& m)
{
    is >> m.dim;
    m.matrix.assign(m.dim, std::vector<double>(m.dim, 0));
    for(uint32_t i = 0; i < m.dim; ++i)
    {
        for(uint32_t j = 0; j < m.dim; ++j)
        {
            is >> m[i][j];
        }
    }
    return is;
}
void Matrix::operator += (const Matrix& other) 
{
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            matrix[i][j] += other[i][j];
        }
    }
}
Matrix Matrix::operator + (const Matrix& other) const
{
    Matrix res(dim);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            res[i][j] = this->matrix[i][j] + other.matrix[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator - (const Matrix& other) const
{
    Matrix res(dim);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            res[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator * (const Matrix &other) const
{
    Matrix answer(dim);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            double res = 0;
            for(int k = 0; k < dim; ++k)
            {
                res += matrix[i][k] * other.matrix[k][j];
            }
            answer[i][j] = res;
        }
    }
    return answer;
}

Matrix Matrix::operator * (double val) const
{
    Matrix res(dim);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            res[i][j] = matrix[i][j] * val;
        }
    }
    return res;
}

Matrix Matrix::operator / (double val) const
{
    Matrix res(dim);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            res[i][j] = matrix[i][j] / val;
        }
    }
    return res;
}

Vector Matrix::operator * (const Vector &vec) const
{
    if(dim != vec.dim)
        return Vector(0);
    Vector res(dim, 0);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            res[i] += matrix[i][j] * vec.buffer[j];
        }
    }
    return res;
}
void Matrix::Permutation(Vector P)
{
    if(P.GetDim() != dim)
        return;
    for(int i = 0; i < dim; ++i)
    {
        if(P[i] != i)
        {
            std::swap(matrix[i], matrix[P[i]]);
            std::swap(P[P[i]], P[i]);
        }
    }
}

long double Matrix::Norm()
{
    long double res = matrix[0][0]; // initial value
    for(int i = 0; i < dim; ++i)
    {
        long double tmp = 0;
        for(int j = 0; j < dim; ++j)
        {
            tmp += fabs(matrix[j][i]);
        }
        if(tmp > res)
            res = tmp;
    }
    return res;
}

Matrix Matrix::Transposing() const
{
    Matrix res(dim, 0);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}

Vector::Vector()
{
    is_transposed = false;
}

Vector::Vector(uint32_t size) : dim(size)
{
    is_transposed = false;
    buffer = std::vector<double>(dim);
}

Vector::Vector(uint32_t size, double val) : dim(size)
{
    is_transposed = false;
    buffer = std::vector<double>(dim, val);
}

Vector::Vector(const std::vector<double>& other)
{
    is_transposed = false;
    dim = other.size();
    buffer.clear();
    std::copy(other.begin(), other.end(), std::back_inserter(buffer));
}

Vector Vector::operator + (const Vector& other)
{
    if(other.dim != dim)
        return Vector(0);

    Vector res(dim);
    for(int i = 0; i < dim; ++i)
    {
        res.buffer[i] = this->buffer[i] + other.buffer[i];
    }

    return res;
}

Vector Vector::operator - (const Vector& other)
{
    if(other.dim != dim)
        return Vector(0);

    Vector res(dim);
    for(int i = 0; i < dim; ++i)
    {
        res.buffer[i] = this->buffer[i] - other.buffer[i];
    }

    return res;
}

double& Vector::operator [] (uint32_t idx)
{
    return buffer[idx];
}

const double& Vector::operator [] (uint32_t idx) const
{
    return buffer[idx];
}

std::ostream& operator << (std::ostream& os, const Vector& v)
{
    for(int i = 0; i < v.dim; ++i)
    {
        os << v.buffer[i] << " ";
    }
    return os;
}

std::istream& operator >> (std::istream& is, Vector& v)
{
    v.buffer.clear();
    is >> v.dim;

    double val;
    int count = 0;
    while(count++ < v.dim)
    {
        is >> val;
        v.buffer.push_back(val);
    }
    return is;
}

long double Vector::Norm()
{
    long double res = 0;
    for(int i = 0; i < dim; ++i)
    {
        res += fabs(buffer[i]);
    }
    return res;
}

Vector Vector::operator * (long double num) const
{
    Vector res = (*this);
    for(int i = 0; i < dim; ++i)
    {
        res[i] *= num;
    }
    return res;
}

std::variant<Matrix, double> Vector::operator * (const Vector& right)
{
    std::variant<Matrix, double> res;
    if(dim != right.GetDim() || !(is_transposed ^ right.is_transposed))
    {
        res = Matrix(0);
        return res;
    }
    if(is_transposed && !right.is_transposed)// 1x3 * 3x1 => 1x1
    {
        double mult = 0;
        for(int i = 0; i < dim; ++ i)
        {
            mult += buffer[i] * right.buffer[i];
        }
        res = mult;
    }
    else
    {
        Matrix mult(dim);
        for(int i = 0; i < dim; ++i)
        {
            for(int j = 0; j < dim; ++j)
            {
                mult[i][j] = buffer[i] * right.buffer[j];
            }
        }
        res = mult;
    }
    return res;

}

Vector Vector::Transposed() const
{
    Vector res = *this;
    if(is_transposed)
        res.is_transposed = false;
    else
        res.is_transposed = true;

    return res;
}

UnitMatrix::UnitMatrix(uint32_t size)
{
    dim = size;
    matrix = std::vector<std::vector<double>>(dim, std::vector<double>(dim, 0));
    for(int i = 0; i < dim; ++i)
    {
        matrix[i][i] = 1;
    }
}







