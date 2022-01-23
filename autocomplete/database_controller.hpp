#include <iostream>
#include <set>

class DatabaseController {
 public:
  void ProcessDatabase(const std::ifstream &database);

  std::set<std::pair<std::string, std::size_t>> get_words_frequencies() const;

  void set_words_frequencies(const std::set<std::pair<std::string, std::size_t>>
                                 &words_frequencies) const;

 private:
  std::set<std::pair<std::string, std::size_t>> words_frequencies;
};
