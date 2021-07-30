#include "strategy.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<Message> stu_list;
	int n;
	string strategy_kind;
	cin >> n >> strategy_kind;
	for (int i = 0; i < n; ++i){
		string name;
		int id;
		int first_score;
		int second_score;
		int total_score;
		cin >> name >> id >> first_score >> second_score >> total_score;
		stu_list.push_back(Message(name, id, first_score, second_score, total_score));
	}

	Strategy* strategy;

	if (strategy_kind=="First")
		strategy = new FirstStrategy();
	else if (strategy_kind=="Second")
		strategy = new SecondStrategy();
	else if (strategy_kind=="Total")
		strategy = new TotalStrategy();
	else if (strategy_kind=="Studentid")
		strategy = new StudentidStrategy();
	
	strategy->sort(stu_list);
	for (int i = 0; i < n; ++i){
		cout << stu_list[i].name() << " " << stu_list[i].id() << " " << " " << 
			stu_list[i].first_score() << " " << stu_list[i].second_score() << " " << stu_list[i].total_score() << endl;
	}

	return 0;
}