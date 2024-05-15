#include <filesystem>
#include <iostream>

// Check the number of args
// if argc > 2: Move all files to the final argv
// else if argc == 2: rename the first file to the second file

using namespace std;

int change_loc(int argc, char **argv) {

  if (argc > 3) {

    if (filesystem::is_directory(argv[argc - 1])) {

      for (int arg = 1; arg < (argc - 1); arg++) {

        filesystem::copy_file(argv[arg], argv[argc - 1]);
        filesystem::remove_all(argv[arg]);
      }
    } else
      cout << "\"" << argv[argc - 1] << "\" is not a directory";
  } else {
    filesystem::copy_file(argv[1], argv[argc - 1]);
    filesystem::remove_all(argv[1]);
  }

  return 0;
}

int main(int argc, char **argv) {

  change_loc(argc, argv);
  return 0;
}
