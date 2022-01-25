#include <iostream>

#include "database.hpp"

class IOController {
 public:
  static Database OpenDatabase(const int &argc, const char **argv);
  static std::string ReadUserInput();
};
