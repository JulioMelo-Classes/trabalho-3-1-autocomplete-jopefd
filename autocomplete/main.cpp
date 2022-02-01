#include "database.hpp"
#include "io.hpp"
#include "query.hpp"

int main(int argc, char **argv) {
  Database database(argv[1]);
  IO io;

  while (true) {
    io.WritePrompt();

    io.LoadUserInput();
    if (io.NoUserInput()) {
      break;
    } else if (not database.Contains(io.get_user_input())) {
      continue;
    }

    Query query(io.get_user_input());
    auto matches = query.FindMatches(database);

    io.WriteMatches(matches);
  }
}
