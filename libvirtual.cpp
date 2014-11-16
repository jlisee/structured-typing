// Author: Joseph Lisee <jlisee@gmail.com>
// Copyright (C) Joseph Lisee 2014
// License: BSD (see LICENSE in root)

#include "libvirtual.h"

Executor::Executor(Operation& op) :
  op_(op)
{
}

int64_t Executor::run(const size_t c) {
  return op_.compute(c);
}
