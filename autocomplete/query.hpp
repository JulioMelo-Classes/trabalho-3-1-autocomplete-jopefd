#ifndef QUERY_DATABASE_HPP_
#define QUERY_DATABASE_HPP_

#include <string>
#include <vector>

#include "database.hpp"

class Query {
 private:
  std::string word_;

 public:
  /**
   * \brief Construct a new Query object
   *
   * \param user_input
   */
  Query(const std::string &user_input);

  /**
   * \brief Find words matching word_ in database
   *
   * \param database
   * \return std::vector<std::string>
   */
  std::vector<std::pair<std::string, std::size_t>> FindMatches(
      const Database &database) const;

  /**
   * \brief Get the word object
   *
   * \return std::string
   */
  std::string get_word() const;
};

#endif
