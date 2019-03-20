#pragma once

#include <cstdlib>
struct free_deleter {
  void operator()(void* x) { free(x); }
};
