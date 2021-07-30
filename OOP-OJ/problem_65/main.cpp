#include "card.h"
#include "king.h"
#include "soldier.h"
#include "beggar.h"
#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<Card*> king;
	vector<Card*> beggar;
	for (int i = 1; i < 6; ++i){
		string name;
		cin >> name;
		if (name == "king")
			king.push_back(new King());
		else
			king.push_back(new Soldier());
	}
	for (int i = 1; i < 6; ++i){
		string name;
		cin >> name;
		if (name == "beggar")
			beggar.push_back(new Beggar());
		else
			beggar.push_back(new Soldier());
	}
	int winnum{0};
	for (int i = 0; i < 5; ++i){
		winnum += king[i]->battle(beggar[i]);
	}

		
	if (winnum > 0)
		cout << "Winner is king!" << endl;
	else if (winnum < 0)
		cout << "Winner is beggar!" << endl;
	
	return 0;
}