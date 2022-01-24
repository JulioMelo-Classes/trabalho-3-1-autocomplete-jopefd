#include "io_controller.hpp"

static Database OpenDatabase(const int &argc, const char **argv) {
  return Database(argv[1]);
}
