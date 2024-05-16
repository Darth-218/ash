#include "ash.hpp"
#include <cstring>

#define MOVED_MESSAGE(from, to)                                                \
  cout << "Moved \"" << argv[from] << "\" to " << argv[to] << "\n";
#define PRINT_FILE(file) "\"" << file << "\""

// TODO: Add a 'backup' option
//
// FIX: Specifying the target path
//
// FIX: Moving from a directory to the current one without
// specifically naming the destination file
//
// FIX: Moving to a directory without adding "/" to the end
// of its name

using namespace std;

int move(string from, string to) {

  filesystem::copy(from, to);
  filesystem::remove_all(from);
  return 0;
}

int change_loc(int argc, char **argv) {

  if (argc > 3) {

    if (filesystem::is_directory(argv[argc - 1])) {

      char slash = argv[argc - 1][size((string)argv[argc - 1])];

      (string) argv[argc - 1] =
          (slash == '/') ? argv[argc - 1] : (string)argv[argc - 1] + '/';

      for (int arg = 1; arg < (argc - 1); arg++) {

        if (!filesystem::exists(argv[arg])) {
          cout << PRINT_FILE(argv[arg]) << " does not exist.\n";
          continue;
        }

        string destination = (string)argv[argc - 1] + (string)argv[arg];
        if (filesystem::exists(destination)) {

          cout << PRINT_FILE(destination)
               << " already exists, do you want to overwrite? [y/N] ";

          if (tolower(getchar()) == 'y') {
            filesystem::remove_all(destination);
            move(argv[arg], destination);
            MOVED_MESSAGE(arg, argc - 1)
          } else
            continue;
        } else {
          move(argv[arg], destination);
          MOVED_MESSAGE(arg, argc - 1)
        }
      }
    } else
      cout << PRINT_FILE(argv[argc - 1]) << " is not a directory\n";
  } else {
    move(argv[1], argv[argc - 1]);
    MOVED_MESSAGE(1, argc - 1)
  }

  return 0;
}

int main(int argc, char **argv) {

  change_loc(argc, argv);
  return 0;
}
