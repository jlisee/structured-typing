#include "libvirtual.h"

Executor::Executor(Operation& op) :
  op_(op)
{
}

int64_t Executor::run(const size_t c) {
  return op_.compute(c);
}
