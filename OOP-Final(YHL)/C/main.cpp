#include <iostream>
#include "User.h"
using namespace std;
int main(){
	User* user = new User();
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i){
		int money, label;
		cin >> money >> label;
		user->addHouse(money, label);
	}
	cin >> m;
	for (int i = 0; i < m; ++i){
		int k;
		cin >> k;
		user->sellHouse(k);
	}
	delete user;
}