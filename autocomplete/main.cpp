#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using std::binary_search;
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

bool Contains(const set<pair<string, size_t>> &word_frequencies,
              const string &prefix) {
  return binary_search(word_frequencies.begin(), word_frequencies.end(),
                       pair<string, size_t>{prefix, 0},
                       [](const auto &fw, const auto &query_pair) {
                         return fw.first.find(query_pair.first) == 0;
                       });
}

set<pair<string, size_t>>::iterator LowerBound(
    const set<pair<string, size_t>> &word_frequencies, const string &prefix) {
  return word_frequencies.lower_bound(pair<string, size_t>{prefix, 0});
}

set<pair<string, size_t>>::iterator UpperBound(
    const set<pair<string, size_t>> &word_frequencies, const string &prefix) {
  auto greater_equals_prefix = [](const pair<string, size_t> &user_input,
                                  const pair<string, size_t> &fw) {
    return user_input.first < fw.first and fw.first.find(user_input.first) != 0;
  };
  return upper_bound(word_frequencies.begin(), word_frequencies.end(),
                     pair<string, size_t>{prefix, 0}, greater_equals_prefix);
}

int main(int argc, char **argv) {
  ifstream database(argv[1]);

  set<pair<string, size_t>> frequencies_words;

  string line;

  getline(database, line);
  size_t lines_number = stoi(line);

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

  string query;

  while (getline(cin, query)) {
    transform(query.begin(), query.end(), query.begin(), toupper);

    pair<string, size_t> query_pair = {query, 0};

    if (not Contains(frequencies_words, query_pair.first)) continue;

    auto first = LowerBound(frequencies_words, query_pair.first);
    auto last = UpperBound(frequencies_words, query_pair.first);

    for_each(first, last, [](const auto &fw) { cout << fw.first << endl; });
  }
}
