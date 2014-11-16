#ifndef STRUCTURED_H
#define STRUCTURED_H

#include <cstdlib>
#include <stdint.h>

struct Operation {
  virtual int64_t compute(const size_t c) = 0;
};

template<class T>
struct OperationImp : public Operation {
  OperationImp(T t) : t_(t) {}

  virtual int64_t compute(const size_t c) {
    return t_.compute(c);
  }

private:
  T t_;
};

class Executor {
public:
  template<class T>
  Executor(T& op) : op_(new OperationImp<T>(op)) {}

  ~Executor();

  int64_t run(const size_t c);

private:
  Operation* op_;
};

#endif // STRUCTURED_H
