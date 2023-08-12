#include <math.h>

class Vec
{
private:

    float x;
    float y;

public:

    Vec(float x, float y);
    ~Vec();

    void SetX(float x) { this->x = x; }
    void SetY(float y) { this->y = y; }

    float GetX() { return this->x; }
    float GetY() { return this->y; }
    float Length() { return (float) sqrt(this->x * this->x + this->y * this->y); };

    Vec Normalized() { return Vec(this->x / this->Length(), this->y / this->Length()); };
    Vec Perpendicular() { return Vec(-this->y, this->x); };

    float Dot(Vec& vec) { return this->x * vec.GetX() + this->y * vec.GetY(); };

    Vec operator+(Vec& vec);
    Vec operator-(Vec& vec);
    Vec operator*(float scalar);
    Vec operator/(float scalar);

    Vec operator*(Vec& vec);
    Vec operator/(Vec& vec);

    Vec& operator+=(Vec& vec);
    Vec& operator-=(Vec& vec);
    Vec& operator*=(float scalar);
    Vec& operator/=(float scalar);

    Vec& operator*=(Vec& vec);
    Vec& operator/=(Vec& vec);

    Vec& operator=(Vec& vec);

};
