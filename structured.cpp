#include <cstdio>
#include <cstdlib>
#include <stdint.h>

#include "libstructured.h"

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
