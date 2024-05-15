#include <cstdio>
#include <filesystem>
#include <iostream>

using namespace std;

/* NOTE: It is better to write things like the `does not exist' messages to
 *       stderr (std::cerr) instead of stdout/std::cout, in case the output is
 *       being piped/redirected somewhere, to make sure that the user sees it.
 *       --- Fedora Enthusiast.
 */

/* NOTE: I don't see why anyone would like to redirect the output of
 * 	 a command that deletes?
 */

// TODO: Add a force parameter

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
