#include <functional>
#include <memory>
extern "C" {
#include "s7/s7.hpp"
}
#include "c_util.hpp"

int main(int, char**) {
  std::unique_ptr<s7_scheme, free_deleter> scheme(s7_init());
}
