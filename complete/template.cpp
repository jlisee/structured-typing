// Author: Joseph Lisee <jlisee@gmail.com>
// Copyright (C) Joseph Lisee 2014
// License: BSD (see LICENSE in root)

#include <cstdio>
#include <cstdlib>
#include <stdint.h>

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
  Executor<Sum> sum((Sum()));
  Executor<Prod> prod((Prod()));

  size_t count = get_count(argc, argv);

  int summation = sum.run(count);
  int product = prod.run(count);

  printf("sum(%zu): %d\n", count, summation);
  printf("prod(%zu): %d\n", count, product);
}
