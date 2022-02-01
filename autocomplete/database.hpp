#ifndef AUTOCOMPLETE_DATABASE_HPP_
#define AUTOCOMPLETE_DATABASE_HPP_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Database {
 private:
  std::set<std::pair<std::string, std::size_t>> words_frequencies_;

 public:
  /**
   * \brief Construct a new Database object
   *
   * \param filepath
   */
  Database(const std::string &filepath);

  /**
   * \brief Check if words_frequencies contains user_input
   *
   * \param user_input
   * \return true
   * \return false
   */
  bool Contains(const std::string &user_input);

  /**
   * \brief Returns the lower bound of the given query
   *
   * \param query
   * \return std::set<std::pair<std::string, std::size_t>>::iterator
   */
  std::set<std::pair<std::string, std::size_t>>::iterator LowerBound(
      const std::string &query) const;

  /**
   * \brief Returns the upper bound of the given query
   *
   * \param query
   * \return std::set<std::pair<std::string, std::size_t>>::iterator
   */
  std::set<std::pair<std::string, std::size_t>>::iterator UpperBound(
      const std::string &query) const;

  /**
   * \brief Load database with filepath content
   *
   * \param filepath
   */
  void LoadDatabase(const std::string &filepath);

  /**
   * \brief Find words matching word
   *
   * \param word
   * \return std::vector<std::pair<std::string, std::size_t>>
   */
  std::vector<std::pair<std::string, std::size_t>> FindMatches(
      const std::string &word) const;
};

#endif
