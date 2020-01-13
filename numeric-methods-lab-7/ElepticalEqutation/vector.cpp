#include "vector.h"
#include <cmath>
#include <algorithm>
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

double Vector::Norm()
{
    std::vector<double>::iterator max = std::max_element(buffer.begin(), buffer.end());
    return *max;
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

Vector Vector::Transposed() const
{
    Vector res = *this;
    if(is_transposed)
        res.is_transposed = false;
    else
        res.is_transposed = true;

    return res;
}

std::vector<double> Vector::GetBuffer() const
{
    return buffer;
}
