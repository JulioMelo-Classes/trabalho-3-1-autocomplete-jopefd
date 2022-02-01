#include "query.hpp"

using std::pair;
using std::string;
using std::vector;

Query::Query(const string &user_input) : word_(user_input) {}

vector<pair<string, size_t>> Query::FindMatches(
    const Database &database) const {
  auto matches = database.FindMatches(word_);
  sort(matches.begin(), matches.end(),
       [](const auto &m1, const auto &m2) { return m1.second < m2.second; });
  return matches;
}

string Query::get_word() const { return word_; }
