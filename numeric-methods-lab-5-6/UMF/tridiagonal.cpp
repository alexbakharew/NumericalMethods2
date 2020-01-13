#include "tridiagonal.h"
#include "matrix.h"
Tridiagonal::Tridiagonal(const Matrix &m) : dim(m.GetDim())
{
    coeffs.resize(dim);
    coeffs[0].push_back(m[0][0]);
    coeffs[0].push_back(m[0][1]);
    coeffs[0].push_back(m[0][2]);
    coeffs[dim - 1].push_back(m[dim - 1][dim - 3]);
    coeffs[dim - 1].push_back(m[dim - 1][dim - 2]);
    coeffs[dim - 1].push_back(m[dim - 1][dim - 1]);

    for(int i = 1; i < m.GetDim() - 1; ++i)
    {
        for(int j = i - 1; j < i + 2; ++j)
        {
            coeffs[i].push_back(m[i][j]);
        }
    }

}
Vector Tridiagonal::SolveEqutation(const Vector& d)
{
    return SolveEqutation(d.GetBuffer());
}

Vector Tridiagonal::SolveEqutation(const std::vector<double>& d)
{
//    coeffs[i][0] = a_i;
//    coeffs[i][1] = b_i;
//    coeffs[i][2] = c_i;
    std::vector<double> P(dim);
    std::vector<double> Q(dim);
//    std::cout << coeffs[0][1] << " " << coeffs[0][0] << " " << coeffs[0][1] / coeffs[0][0] << std::endl;
    P[0] = (coeffs[0][1] / coeffs[0][0]) * (- 1);
    Q[0] = d[0] / coeffs[0][0];

    for(int i = 1; i < dim; ++i)
    {
        if(i == dim - 1)
        {
            P[i] = 0;
            Q[i] = (d[i] - coeffs[i][1] * Q[i - 1]) / (coeffs[i][2] + coeffs[i][1] * P[i - 1]);

        }
        else
        {
            P[i] = - (coeffs[i][2] / (coeffs[i][1] + coeffs[i][0] * P[i - 1]));
            Q[i] = (d[i] - coeffs[i][0] * Q[i - 1]) / (coeffs[i][1] + coeffs[i][0] * P[i - 1]);
        }

    }

    std::vector<double> x(dim);
    x[dim - 1] = Q[dim - 1];
    for(int i = dim - 2; i > 0; --i)
    {
        x[i] = -(coeffs[i][2] / (coeffs[i][1] + coeffs[i][0] * P[i - 1])) * x[i + 1]
                + (d[i] - coeffs[i][0] * Q[i - 1]) / (coeffs[i][1] + coeffs[i][0] * P[i - 1]);
    }
    x[0] = P[0] * x[1] + Q[0];
    return Vector(x);
}
