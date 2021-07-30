#pragma once

#include <string>
using std::string;
class Message{
private:
	string name_;
	int id_;
	int first_score_;
	int second_score_;
	int total_score_;
public:
	Message(string name, int id, int first_score, int second_score, int total_score):
		name_(name),  id_(id), first_score_(first_score), second_score_(second_score), total_score_(total_score) {}
	string name() { return name_; }
	int id() { return id_; }
	int first_score() { return first_score_; }
	int second_score() { return second_score_; }
	int total_score() { return total_score_; }
};