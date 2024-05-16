#include "ash.hpp"

using namespace std;

// TODO: Add a force parameter
// TODO: Better error handeling

int destroy(int args, char **argv) {

  for (int arg = 1; arg < args; arg++) {

    if (!(filesystem::exists(argv[arg])))
      cout << "File/directory \"" << argv[arg] << "\" does not exit\n";

    else if (filesystem::equivalent(argv[arg], argv[0]))
      cout << "The program can't delete itself, reconsider yourself.\n";

    else if (!(filesystem::is_directory(argv[arg])))
      filesystem::remove(argv[arg]);

    else if (filesystem::is_directory(argv[arg])) {
      cout << "Deleting a directory, do you want to proceed? [y/N] ";
      char confirmation = getchar();

      if (tolower(confirmation) == 'y')
        filesystem::remove_all(argv[arg]);
    }
  }
  return 0;
}

int main(int args, char **argv) {

  destroy(args, argv);
  return 0;
}
