#pragma once

#include <string>
class Card {
private:
    std::string name_;
public:
    Card(const std::string &_name): name_(_name) {}

    //Cannot copy cards
    Card(const Card &other) = delete;

    //Cannot copy cards
    Card& operator=(const Card &other) = delete;

    std::string name() const { return name_; }

    virtual int battle(Card *other){return 0;}

    ~Card(){};
};