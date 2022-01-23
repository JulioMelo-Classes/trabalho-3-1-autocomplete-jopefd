#include <iostream>

class UserInterface {
 public:
  static std::ifstream OpenDatabase(const int &argc, const char **argv);
  static std::string ReadUserInput();
};
