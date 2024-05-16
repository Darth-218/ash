#include "ash.hpp"

#define MOVED_MESSAGE(from, to)                                                \
  cout << "Moved " << argv[from] << " to " << argv[to] << "\n";

// FIX: Auto move the files into folders without specifying filenames

using namespace std;

int change_loc(int argc, char **argv) {

  if (argc > 3) {

    if (filesystem::is_directory(argv[argc - 1])) {

      for (int arg = 1; arg < (argc - 1); arg++) {

        filesystem::copy(argv[arg], argv[argc - 1]);
        filesystem::remove_all(argv[arg]);
        MOVED_MESSAGE(arg, argc - 1)
      }
    } else
      cout << "\"" << argv[argc - 1] << "\" is not a directory\n";
  } else {
    filesystem::copy(argv[1], argv[argc - 1]);
    filesystem::remove_all(argv[1]);
    MOVED_MESSAGE(1, argc - 1)
  }

  return 0;
}

int main(int argc, char **argv) {

  change_loc(argc, argv);
  return 0;
}
