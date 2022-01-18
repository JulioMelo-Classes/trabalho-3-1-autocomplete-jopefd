#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::pair;
using std::set;
using std::size_t;
using std::string;
using std::ws;
using std::stringstream;

int main(int argc, char **argv) {
  ifstream database(argv[1]);
  string line;

  getline(database, line);
  size_t lines_number = stoi(line);

  while (lines_number--) {
    stringstream aux;
    pair<size_t, string> frequency_word;

    getline(database, line);

    aux << line;
    aux >> frequency_word.first;
    getline(aux >> ws, frequency_word.second);

    cout << frequency_word.first << " " << frequency_word.second << endl;
  }
}
