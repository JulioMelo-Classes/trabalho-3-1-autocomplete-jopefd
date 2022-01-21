#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::getline;
using std::ifstream;
using std::lower_bound;
using std::pair;
using std::search;
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::tolower;
using std::transform;
using std::upper_bound;
using std::ws;

int main(int argc, char **argv) {
  ifstream database(argv[1]);
  string line;

  getline(database, line);
  size_t lines_number = stoi(line);

  set<pair<string, size_t>> frequencies_words;

  while (lines_number--) {
    size_t frequency;
    string word;
    stringstream aux;

    getline(database, line);

    aux << line;
    aux >> frequency;
    getline(aux >> ws, word);

    transform(word.begin(), word.end(), word.begin(), toupper);

    frequencies_words.insert({word, frequency});
  }

  for (const auto &fw : frequencies_words) cout << fw.first << endl;

  string user_input;

  while (getline(cin, user_input)) {
    transform(user_input.begin(), user_input.end(), user_input.begin(),
              toupper);

    auto not_contains = [](const pair<string, size_t> &fw1,
                           const pair<string, size_t> &fw2) {
      return fw1.first.find(fw2.first) == string::npos;
    };

    auto contains = [](const pair<string, size_t> &fw1,
                       const pair<string, size_t> &fw2) {
      return fw1.first.find(fw2.first) != string::npos;
    };

    auto first = lower_bound(frequencies_words.begin(), frequencies_words.end(),
                             pair<string, size_t>{user_input, 0}, contains);
    auto last = upper_bound(frequencies_words.begin(), frequencies_words.end(),
                            pair<string, size_t>{user_input, -1}, contains);

    // for_each(first, last, [](const auto &fw) { cout << fw.first << endl; });
    cout << (first != frequencies_words.end() ? first->first : "no") << " F"
         << endl;
    cout << (last != frequencies_words.end() ? last->first : "no") << " L"
         << endl;
  }
}
