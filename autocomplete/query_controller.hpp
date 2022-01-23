#include <set>
#include <string>

class QueryController {
 public:
  void FindMatches() const;

  std::set<std::pair<std::string, std::size_t>> get_matches() const;

  void set_matches(
      const std::set<std::pair<std::string, std::size_t>> &matches);

  std::string get_query() const;

  void set_query(const std::string &query);

 private:
  std::set<std::pair<std::string, std::size_t>> matches_;
  std::string query_;
};
