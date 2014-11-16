#include "libstructured.h"

int64_t Executor::run(const size_t c) {
  return op_->compute(c);
}

Executor::~Executor()
{
  delete op_;
}
