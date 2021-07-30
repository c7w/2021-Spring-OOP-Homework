#include "operationMinus.h"

void OperationMinus::UpdateValue() {
    this->value_ = input1->value() - input2->value();
}