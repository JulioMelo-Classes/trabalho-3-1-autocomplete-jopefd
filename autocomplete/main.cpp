#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::string;

int main(int argc, char **argv) {
  ifstream database(argv[1]);
  string line;
  while (getline(database, line)) {
    cout << line;
  }
}
