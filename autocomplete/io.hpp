#ifndef AUTOCOMPLETE_IO_HPP_
#define AUTOCOMPLETE_IO_HPP_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class IO {
 private:
  std::string user_input_;

 public:
  /**
   * \brief Write words matching user input
   *
   * \param matches
   */
  void WriteMatches(
      const std::vector<std::pair<std::string, std::size_t>> &matches) const;

  /**
   * \brief Write user prompt
   *
   */
  void WritePrompt() const;

  /**
   * \brief Load user input and transform it in uppercase
   *
   */
  void LoadUserInput();

  /**
   * \brief Check if there is user input
   *
   * \return true
   * \return false
   */
  bool NoUserInput() const;

  /**
   * \brief Get the user input object
   *
   * \return std::string
   */
  std::string get_user_input() const;
};

#endif
