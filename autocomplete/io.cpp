#include "io.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::getline;
using std::pair;
using std::string;
using std::transform;
using std::vector;

void IO::WriteMatches(const vector<pair<string, size_t>> &matches) const {
  cout << ">>> The matches are:" << endl;

  auto begin = matches.begin();
  auto end = matches.end();

  while (begin < end) {
    end--;
    cout << end->first << endl;
  }

  cout << "\n\n" << endl;
}

void IO::WritePrompt() const {
  cout << ">>> Type a word and hit ENTER or <ctrl>+d to quit: ";
}

void IO::LoadUserInput() {
  getline(cin, user_input_);
  transform(user_input_.begin(), user_input_.end(), user_input_.begin(),
            toupper);
}

bool IO::NoUserInput() const { return user_input_.empty(); }

string IO::get_user_input() const { return user_input_; }
