#pragma once

class Part {
   private:
    int val;
   public:
    Part(int v=0) : val(v) {}
    int getVal() { return val; }
};

