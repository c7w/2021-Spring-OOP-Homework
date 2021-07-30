#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
int Example::memberCount = 0;

Example::Example(int data) {
	// (3)
    this->data = data;
    memberCount++;
    id = memberCount;
    cout << "Example #" << id << " is created" << endl;
}

void Example::getData() {
	// (4)
    cout << "The data of Example #" << id << " is " << data << endl;
}

Example::~Example() {
	// (5)
    cout << "Example #" << id << " is destroyed" << endl;
}