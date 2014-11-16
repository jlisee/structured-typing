#include <cstdio>
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


struct Sum {
  int64_t compute(const size_t c) {
    int64_t res = c;

    for (int i = 1; i < c; ++i) {
      res += c;
    }

    return res;
  }
};

struct Prod {
  int64_t compute(const size_t c) {
    int64_t res = c;

    for (int i = 1; i < c; ++i) {
      res *= c;
    }

    return res;
  }
};

class Executor {
public:
  template<class T>
  Executor(T& op) : op_(new OperationImp<T>(op)) {}

  ~Executor() {
    delete op_;
  }

  int64_t run(const size_t c) {
    return op_->compute(c);
  }

private:
  Operation* op_;
};

size_t get_count(int argc, char** argv)
{
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <count>\n", argv[0]);
    exit(1);
  }

  return atoi(argv[1]);
}

int main(int argc, char** argv)
{
  Sum s;
  Prod p;

  Executor sum(s);
  Executor prod(p);

  size_t count = get_count(argc, argv);

  int summation = sum.run(count);
  int product = prod.run(count);

  printf("sum(%zu): %d\n", count, summation);
  printf("prod(%zu): %d\n", count, product);
}
