#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::for_each;
using std::ifstream;
using std::pair;
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::ws;

int main(int argc, char **argv) {
  ifstream database(argv[1]);
  string line;

  getline(database, line);
  size_t lines_number = stoi(line);

  set<pair<size_t, string>> frequencies_words;

  while (lines_number--) {
    stringstream aux;
    pair<size_t, string> frequency_word;

    getline(database, line);

    aux << line;
    aux >> frequency_word.first;
    getline(aux >> ws, frequency_word.second);

    frequencies_words.insert(frequency_word);
  }

  for_each(frequencies_words.begin(), frequencies_words.end(),
           [](auto &p) { cout << p.first << " " << p.second << endl; });
}
