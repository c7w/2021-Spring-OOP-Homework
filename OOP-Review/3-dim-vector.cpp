#include <iostream>
class Vector3D
{
private:
    double _x;
    double _y;
    double _z;

public:
    Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}
    Vector3D(double m) 
    {
        _x = m;
        _y = m;
        _z = m;
    }
    Vector3D operator+(const Vector3D& another)
    {
        return Vector3D(_x + another._x, _y + another._y, _z + another._z);
    }
    Vector3D operator-(const Vector3D& another)
    {
        return Vector3D(_x - another._x, _y - another._y, _z - another._z);
    }
    friend Vector3D operator*(double lambda, const Vector3D& src)
    {
        return Vector3D(lambda * src._x, lambda * src._y, lambda * src._z);
    }

    Vector3D operator*(double lambda)
    {
        return Vector3D(lambda * _x, lambda * _y, lambda * _z);
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector3D& src)
    {
        out << "(" << src._x << ", " << src._y << ", " << src._z << ")";
        return out;
    }

    friend Vector3D operator+(double m, Vector3D b)
    {
        return b + m;
    }

    friend Vector3D operator-(double m, Vector3D b)
    {
        return  b * (-1) + m;
    }
    
};

int main(int argc, char** argv)
{
    Vector3D v1(1.1, 1.2, 1.3);
    Vector3D v2(0, -3.4, 2.5);
    Vector3D v3 = v1 + v2;
    std::cout << v3 << std::endl;
    Vector3D v4 = v3 + 2;
    Vector3D v5 = 3 * v4 + 5;
    std::cout << v5 << std::endl;
    Vector3D v6 = 1.4 - (3 * v2 - v1);
    std::cout << v6 << std::endl;
    return 0;
}