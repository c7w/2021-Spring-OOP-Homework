#include "MyTree.h"
#include <string>
#include <iostream>
using namespace std;
int main(){
	MyTree mytree;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		string order;
		int x,t;
		cin>> order >> x >> t;
		if (order == "ADD")
			mytree.add(x,t);
		else if (order == "SUB")
			mytree.sub(x,t);
		else if (order == "MUL")
			mytree.mul(x,t);
		else if (order == "SET")
			mytree.set(x,t);
		else if (order == "QUERY")
			mytree.query(x,t);
	}
}