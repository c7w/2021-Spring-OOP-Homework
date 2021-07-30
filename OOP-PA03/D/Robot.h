#pragma once
#include "Part.h"
class Robot {
   protected:
    Part* array;
    int len;
    int partNum;

   public:
    Robot(int partNum);
    ~Robot();
    bool is_full();
    void add_part(Part&& part);
};