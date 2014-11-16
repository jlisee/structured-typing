#ifndef VIRTUAL_H
#define VIRTUAL_H

#include <cstdlib>
#include <stdint.h>

struct Operation {
  virtual int64_t compute(const size_t c) = 0;
};

class Executor {
public:
  Executor(Operation& op);

  int64_t run(const size_t c);

private:
  Operation& op_;
};

#endif // VIRTUAL_H
