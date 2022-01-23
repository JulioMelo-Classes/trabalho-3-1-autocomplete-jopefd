#include "database_controller.hpp"

using std::getline;
using std::size_t;
using std::string;
using std::stringstream;
using std::ws;

void DatabaseController::ProcessDatabase(Database &database) {
  string line;

  getline(database, line);
  size_t lines_number = stoi(line);

  WordsFrequencies words_frequencies;

  while (lines_number--) {
    size_t frequency;
    string word;
    stringstream aux;

    getline(database, line);

    aux << line;
    aux >> frequency;
    getline(aux >> ws, word);

    transform(word.begin(), word.end(), word.begin(), toupper);

    words_frequencies.insert({word, frequency});
  }
}

WordsFrequencies DatabaseController::get_words_frequencies() const {
  return words_frequencies_;
}

void DatabaseController::set_words_frequencies(
    const WordsFrequencies &words_frequencies) {
  words_frequencies_ = words_frequencies;
}
