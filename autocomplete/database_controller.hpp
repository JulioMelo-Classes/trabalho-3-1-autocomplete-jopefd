#include <iostream>
#include <set>
#include <sstream>
#include <string>

#include "database.hpp"
#include "words_frequencies.hpp"

class DatabaseController {
 public:
  void ProcessDatabase(Database &database);

  WordsFrequencies get_words_frequencies() const;

  void set_words_frequencies(const WordsFrequencies &words_frequencies);

 private:
  WordsFrequencies words_frequencies_;
};
