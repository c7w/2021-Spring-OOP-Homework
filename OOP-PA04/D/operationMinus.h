#include "operation.h"
#pragma once

class OperationMinus : public OperationNodeTwo {
   public:
    using OperationNodeTwo::OperationNodeTwo;
    void UpdateValue();
};