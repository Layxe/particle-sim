#include "Vec.h"

Vec::Vec(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vec::~Vec() {}

Vec Vec::operator+(Vec& vec)
{
    return Vec(this->x + vec.x, this->y + vec.y);
}

Vec Vec::operator-(Vec& vec)
{
    return Vec(this->x - vec.x, this->y - vec.y);
}

Vec Vec::operator*(float scalar)
{
    return Vec(this->x * scalar, this->y * scalar);
}

Vec Vec::operator/(float scalar)
{
    return Vec(this->x / scalar, this->y / scalar);
}

Vec& Vec::operator+=(Vec& vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

Vec& Vec::operator-=(Vec& vec)
{
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

Vec& Vec::operator*=(float scalar)
{
    this->x *= scalar;
    this->y *= scalar;

    return *this;
}

Vec& Vec::operator/=(float scalar)
{
    this->x /= scalar;
    this->y /= scalar;

    return *this;
}

Vec& Vec::operator*=(Vec& vec)
{
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

Vec& Vec::operator/=(Vec& vec)
{
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

Vec& Vec::operator=(Vec& vec)
{
    this->x = vec.x;
    this->y = vec.y;

    return *this;
}

Vec Vec::operator*(Vec& vec)
{
    return Vec(this->x * vec.x, this->y * vec.y);
}

Vec Vec::operator/(Vec& vec)
{
    return Vec(this->x / vec.x, this->y / vec.y);
}