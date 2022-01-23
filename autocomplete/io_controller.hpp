#include <iostream>

class IOController {
 public:
  static std::ifstream OpenDatabase(const int &argc, const char **argv);
  static std::string ReadUserInput();
};
