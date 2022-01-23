#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

#include "database_controller.hpp"
#include "user_interface.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::getline;
using std::ifstream;
using std::lower_bound;
using std::pair;
using std::search;
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::tolower;
using std::transform;
using std::upper_bound;
using std::ws;

int main(int argc, char **argv) {
  Database database = UserInterface::OpenDatabase(argc, argv);
  ProcessDatabase(database);

  for (const auto &fw : frequencies_words) cout << fw.first << endl;

  string user_input;

  while (getline(cin, user_input)) {
    transform(user_input.begin(), user_input.end(), user_input.begin(),
              toupper);

    auto greater = [](const pair<string, size_t> &fw1,
                      const pair<string, size_t> &fw2) {
      return fw1.first < fw2.first;
    };

    auto less = [](const pair<string, size_t> &fw1,
                   const pair<string, size_t> &fw2) {
      return fw1.first >= fw2.first;
    };

    auto first = lower_bound(frequencies_words.begin(), frequencies_words.end(),
                             pair<string, size_t>{user_input, 0}, greater);
    auto last = upper_bound(frequencies_words.begin(), frequencies_words.end(),
                            pair<string, size_t>{user_input, -1}, less);

    // for_each(first, last, [](const auto &fw) { cout << fw.first << endl; });
    cout << (first != frequencies_words.end() ? first->first : "no") << " F"
         << endl;
    cout << (last != frequencies_words.end() ? last->first : "no") << " L"
         << endl;
  }
}
