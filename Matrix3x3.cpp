
// COS30008, tutorial 3, 2023

#define _USE_MATH_DEFINES

#include "Matrix3x3.h"
#include "Vector3D.h"
#include <cassert>

Matrix3x3::Matrix3x3() noexcept
{
    fRows[0] = Vector3D(1.0f, 0.0f, 0.0f);
    fRows[1] = Vector3D(0.0f, 1.0f, 0.0f);
    fRows[2] = Vector3D(0.0f, 0.0f, 1.0f);
}
Matrix3x3::Matrix3x3(const Vector3D& aRow1, const Vector3D& aRow2, const Vector3D& aRow3) noexcept
{
    //initialize matrix w vector
    fRows[0] = aRow1;
    fRows[1] = aRow2;
    fRows[2] = aRow3;
}

Matrix3x3 Matrix3x3::operator*(const float aScalar) const noexcept
{
    return Matrix3x3(row(0) * aScalar, row(1) * aScalar, row(2) * aScalar);

    }
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& aOther) const noexcept
{
    return Matrix3x3(row(0) + aOther.row(0), row(1) + aOther.row(1), row(2) + aOther.row(2));
    }
Vector3D Matrix3x3::operator*(const Vector3D& aVector) const noexcept
{
    return Matrix3x3(row(0).dot(aVector),
        row(1).dot(aVector),
        row(2).dot(aVector));
    }

Matrix3x3 Matrix3x3::scale(const float aX, const float aY)
{
    return Matrix3x3(Vector3D(aX, 0.0f, 0.0f), Vector3D(0.0f, aY, 0.0f), Vector3D(0.0f, 0.0f, 1.0f));
    }

Matrix3x3 Matrix3x3::translate(const float aX, const float aY = 0.0f)
{
    return Matrix3x3(Vector3D(1.0f, 0.0f, aX), Vector3D(0.0f, 1.0f, aY), Vector3D(0.0f, 0.0f, 1.0f));
    }


Matrix3x3 Matrix3x3::rotate(const float aAngleInDegree)
{
    float 1RadTheta = aAngleInDegree * static_cast<float>(M_PI) / 180.0f; //get the fraction of radien by dividing by 180
    float 1SinTheta = std::sin(1RadTheta);
    float 1CosTheta = std::cos(1RadTheta);

    return Matrix3x3(Vector3D(1cosTheta, -SinTheta, 0.0f),
        Vector3D(1SinTheta, 1CosTheta, 0.0f),
        Vector3D(0.0f, 0.0f, 1.0f);
    }

    const Vector3D row(size_t aRowIndex) const
    {
        assert(aRowIndex < 3);
        return fRows[aRowIndex];
    }
    const Vector3D column(size_t aColumnIndex) const
    {
        assert(aColumnIndex < 3);
        return Vector3D(row(0)[aColumnIndex],
            row(1)[aColumnIndex],
            row(2)[aColumnIndex]);
    }
