#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <math.h>
template <class T>
class Container {
protected:
	T data;
public:
    Container(T data) : data{data} {}

    ~Container(){}

	virtual double volume()=0;            
};

//TODO : define and finish the subclass of Container Cube
class Cube : public Container<int>
{
public:
    Cube(int data) : Container<int>::Container(data) {}
    double volume()
    {
        return Container<int>::data * Container<int>::data * Container<int> ::data;
    }
};
//TODO : define and finish the subclass of Container Sphere
class Sphere : public Container<double>
{
public:
    Sphere(double data) : Container<double>::Container(data) {}
    double volume()
    {
        return 3.14 * Container<double>::data * Container<double>::data * Container<double>::data * 4 / 3;
    }
};
//TODO : define and finish the function printVolume
template <class T>
void printVolume(Container<T>* src)
{
    std::cout << (int)floor(src->volume()) << std::endl;
}
#endif // #ifndef CONTAINER_H