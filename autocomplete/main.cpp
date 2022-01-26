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
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::tolower;
using std::transform;
using std::upper_bound;
using std::ws;

class Database {
 public:
  Database() {}

  Database(const string &filepath) { LoadDatabase(filepath); }

  bool Contains(const string &query) {
    const pair<string, size_t> query_pair = {query, 0};
    const auto is_prefix = [](const pair<string, size_t> &word_frequency,
                              const pair<string, size_t> &query_pair) {
      return word_frequency.first.find(query_pair.first) == 0;
    };

    return binary_search(words_frequencies_.begin(), words_frequencies_.end(),
                         query_pair, is_prefix);
  }

  set<pair<string, size_t>>::iterator LowerBound(const string &query) {
    const pair<string, size_t> query_pair = {query, 0};

    return words_frequencies_.lower_bound(query_pair);
  }

  set<pair<string, size_t>>::iterator UpperBound(const string &query) {
    const pair<string, size_t> query_pair = {query, 0};
    const auto greater_has_not_prefix =
        [](const pair<string, size_t> &query_pair,
           const pair<string, size_t> &word_frequency) {
          return query_pair.first < word_frequency.first and
                 word_frequency.first.find(query_pair.first) != 0;
        };

    return upper_bound(words_frequencies_.begin(), words_frequencies_.end(),
                       query_pair, greater_has_not_prefix);
  }

  void LoadDatabase(const string &filepath) {
    ifstream database(filepath);

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

      words_frequencies_.insert({word, frequency});
    }
  }

 private:
  set<pair<string, size_t>> words_frequencies_;
};

int main(int argc, char **argv) {
  Database database(argv[1]);

  while (true) {
    cout << ">>> Type a word and hit ENTER or <ctrl>+d to quit: ";

    string query;
    if (not getline(cin, query)) break;
    transform(query.begin(), query.end(), query.begin(), toupper);

    pair<string, size_t> query_pair = {query, 0};

    if (not database.Contains(query_pair.first)) continue;

    const auto first_match = database.LowerBound(query_pair.first);
    const auto last_match = database.UpperBound(query_pair.first);

    cout << ">>> The matches are:" << endl;

    for_each(first_match, last_match,
             [](const auto &fw) { cout << fw.first << endl; });

    cout << "\n\n" << endl;
  }
}
