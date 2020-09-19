#pragma once

// Thanks Ace, not only for this, but for so much help :)

#include <math.h>

struct Vector3
{
    float X, Y, Z;

    Vector3(float x = 0, float y = 0, float z = 0)
    {
        X = x;
        Y = y;
        Z = z;
    }
    float GetMagnitude()
    {
        return sqrtf(X * X + Y * Y + Z * Z);
    }

    float Distance2D(const Vector3& vec) const
    {
        float num = X - vec.X;
        float num2 = Y - vec.Y;
        return sqrtf(num * num + num2 * num2);
    }
    float Distance3D(const Vector3& vec) const
    {
        float num = X - vec.X;
        float num2 = Y - vec.Y;
        float num3 = Z - vec.Z;
        return sqrtf(num * num + num2 * num2 + num3 * num3);
    }
    //multiplY this vector bY a scalar
    Vector3 operator*(float num) const
    {
        return Vector3(X * num, Y * num, Z * num);
    }

    //pass in a vector, pass in a scalar, return the product
    friend Vector3 operator*(float num, Vector3 const& vec)
    {
        return Vector3(vec.X * num, vec.Y * num, vec.Z * num);
    }

    //add two vectors
    Vector3 operator+(const Vector3& vec) const
    {
        return Vector3(X + vec.X, Y + vec.Y, Z + vec.Z);
    }

    //subtract two vectors
    Vector3 operator-(const Vector3& vec) const
    {
        return Vector3(X - vec.X, Y - vec.Y, Z - vec.Z);
    }
    //subtract two vectors
    Vector3 operator==(const Vector3& vec) const
    {
        return (X == vec.X && Y == vec.Y && Z == vec.Z);
    }


    //normaliZe this vector
    void normaliZeVector3D()
    {
        float magnitude = sqrtf(X * X + Y * Y + Z * Z);
        X /= magnitude;
        Y /= magnitude;
        Z /= magnitude;
    }

    //calculate and return dot product
    float dotVector3D(const Vector3& vec) const
    {
        return X * vec.X + Y * vec.Y + Z * vec.Z;
    }
    //calculate and return dot product
    float equals(const Vector3& vec) const
    {
        return (X == vec.X && Y == vec.Y && Z == vec.Z);
    }

    //calculate and return cross product
    Vector3 crossVector3D(const Vector3& vec) const
    {
        return Vector3(Y * vec.Z - Z * vec.Y,
            Z * vec.X - X * vec.Z,
            X * vec.Y - Y * vec.X);
    }
    /*void Round()
    {
        roundf(X * 100) / 100;
        roundf(Y * 100) / 100;
        roundf(Z * 100) / 100;
    }*/

    Vector3 ToWoW()
    {
        return  Vector3(-Z, -X, Y);
    }

    Vector3 ToRecast()
    {
        return  Vector3(-Y, Z, -X);
    }

    void ToFloatArray(float* ret)
    {
        ret[0] = X;
        ret[1] = Y;
        ret[2] = Z;

    }
    bool isValid()
    {
        return X != 0 && Y != 0 && Z != 0;
    }
};