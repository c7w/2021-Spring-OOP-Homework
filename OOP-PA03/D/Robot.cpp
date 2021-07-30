#include "Robot.h"

Robot::Robot(int partNum){
    array = new Part[partNum];
    len = 0;
    this->partNum = partNum;
}

Robot::~Robot(){
    delete[] array;
}

bool Robot::is_full(){
    if (len == partNum) return true;
    else
        return false;
}

void Robot::add_part(Part&& part){
    array[len] = part;
    len++;
}