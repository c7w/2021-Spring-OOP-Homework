#include <iostream>
#include "Container.h"
using namespace std;
int main(){
	int k1;
	double k2;
	cin >> k1;
	cin >> k2;

	Cube* cube = new Cube{k1};
	printVolume(cube);
	delete cube;

	Sphere* sphere = new Sphere{k2};
	printVolume(sphere);
	delete sphere;
}