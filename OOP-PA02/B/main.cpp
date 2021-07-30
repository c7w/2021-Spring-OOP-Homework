#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	// (6)
    static Example six = Example(2333);
    for (int i = 0; i < n; i++){
        e[i]->getData();
    }
    for (int i = 0; i < n; i++) {
        e[i]->~Example();
    }
    six.getData();
	

    cout << "--------create_example is over--------\n";
}

// (7)
static Example first(23);

int main() {

	cout << "--------main_function is ready--------\n";

	// (8)
    Example second(233);

    create_example(3);
	
	// (9)
    Example seventh(23333);
    first.getData();
    second.getData();
    seventh.getData();

    cout << "--------main_function is over---------\n";
    return 0;
}
