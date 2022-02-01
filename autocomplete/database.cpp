#include "database.hpp"

using std::getline;
using std::ifstream;
using std::pair;
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::transform;
using std::vector;
using std::ws;

Database::Database(const string &filepath) { LoadDatabase(filepath); }

bool Database::Contains(const string &user_input) {
  const pair<string, size_t> query = {user_input, 0};
  const auto is_prefix = [](const pair<string, size_t> &word_frequency,
                            const pair<string, size_t> &query_pair) {
    return word_frequency.first.find(query_pair.first) == 0;
  };

  return binary_search(words_frequencies_.begin(), words_frequencies_.end(),
                       query, is_prefix);
}

set<pair<string, size_t>>::iterator Database::LowerBound(
    const string &query) const {
  const pair<string, size_t> query_pair = {query, 0};

  return words_frequencies_.lower_bound(query_pair);
}

set<pair<string, size_t>>::iterator Database::UpperBound(
    const string &query) const {
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

void Database::LoadDatabase(const string &filepath) {
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

vector<pair<string, size_t>> Database::FindMatches(const string &word) const {
  auto first_match = LowerBound(word);
  auto last_match = UpperBound(word);

  size_t matches_size = distance(first_match, last_match) - 1;
  vector<pair<string, size_t>> matches(matches_size);
  for (size_t i = 0; i < matches_size; i++) matches[i] = *(++first_match);

  return matches;
}
