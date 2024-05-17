#include "ash.hpp"

#define MOVED_MESSAGE(from, to)                                                \
  cout << "Moved \"" << argv[from] << "\" to \"" << argv[to] << "\"\n";
#define FILE_NAME(file) "\"" << file << "\""

// TODO: Add a 'backup' option

using namespace std;

int move(string from, string to) {

  filesystem::copy(from, to);
  filesystem::remove_all(from);
  return 0;
}

int change_loc(int argc, char **argv) {

  if (argc > 3) {

    if (filesystem::is_directory(argv[argc - 1])) {

      for (int arg = 1; arg < (argc - 1); arg++) {

        if (!filesystem::exists(argv[arg])) {
          cout << FILE_NAME(argv[arg]) << " does not exist.\n";
          continue;
        }

        string destination =
            (argv[argc - 1][size((string)argv[argc - 1]) - 1] == '/')
                ? (string)argv[argc - 1] + (string)argv[arg]
                : (string)argv[argc - 1] + "/" + (string)argv[arg];

        if (filesystem::exists(destination)) {

          cout << FILE_NAME(destination)
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
      cout << FILE_NAME(argv[argc - 1]) << " is not a directory\n";
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
