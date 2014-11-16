#ifndef TEMPLATE_H
#define TEMPLATE_H

template<class T>
class Executor {
public:
  Executor(T op) : op_(op) {}

  int64_t run(const size_t c) {
    return op_.compute(c);
  }

private:
  T op_;
};

#endif // TEMPLATE_H
