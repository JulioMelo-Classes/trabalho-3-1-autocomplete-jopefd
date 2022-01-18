#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::getline;
using std::ifstream;
using std::lower_bound;
using std::pair;
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::upper_bound;
using std::ws;

int main(int argc, char **argv) {
  ifstream database(argv[1]);
  string line;

  getline(database, line);
  size_t lines_number = stoi(line);

  set<pair<size_t, string>> frequencies_words;

  while (lines_number--) {
    stringstream aux;
    pair<size_t, string> frequency_word;

    getline(database, line);

    aux << line;
    aux >> frequency_word.first;
    getline(aux >> ws, frequency_word.second);

    frequencies_words.insert(frequency_word);
  }

  string user_input;

  while (getline(cin, user_input)) {
    // const auto contains_user_input =
    //     [](const pair<size_t, string> &frequency_word_1, const pair<size_t,
    //     string> &frequency_word_2) {
    //       return frequency_word_2.second.find(frequency_word_1.second) !=
    //       string::npos;
    //     };

    // const auto first =
    //     lower_bound(frequencies_words.begin(), frequencies_words.end(),
    //                 pair<size_t, string>{0, user_input},
    //                 contains_user_input);
    // const auto last =
    //     upper_bound(frequencies_words.begin(), frequencies_words.end(),
    //                 pair<size_t, string>{0, user_input},
    //                 contains_user_input);

    // cout << (first == frequencies_words.begin() ? first->second : "no") <<
    // endl;

    for_each(frequencies_words.begin(), frequencies_words.end(),
             [user_input](const auto &fw) {
               cout << (fw.second.find(user_input) != string::npos ? "sim" : "nao") << endl;
             });
  }
}
