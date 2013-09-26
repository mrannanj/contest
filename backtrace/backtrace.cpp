#include <iostream>
#include <execinfo.h>

using namespace std;

void print_stack() {
  int size = 10;
  void *buf[10];
  int n = backtrace(buf, size);
  backtrace_symbols_fd(buf, n, 1);
}

void foo(int i) {
  if (i > 0) {
    foo(i-1);
    return;
  }
  print_stack();
}

int main() {
  foo(10);
}

