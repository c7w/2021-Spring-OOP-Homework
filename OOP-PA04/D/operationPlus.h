#include "operation.h"
#pragma once

class OperationPlus : public OperationNodeTwo {
   public:
    using OperationNodeTwo::OperationNodeTwo;
    void UpdateValue();
};