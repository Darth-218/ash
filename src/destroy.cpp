#include <cstdio>
#include <filesystem>
#include <iostream>

using namespace std;

// TODO: Add a verbose parameter
// TODO: Add a force parameter

int main(int args, char **argv) {

  for (int arg = 1; arg < args; arg++) {

    if (!(filesystem::is_directory(argv[arg])))
      filesystem::remove(argv[arg]);
    else {
      cout << "Deleting a directory, do you want to proceed? [y/N] ";
      char confirmation = getchar();
      if (tolower(confirmation) == 'y')
        filesystem::remove_all(argv[arg]);
      else
        continue;
    }
  }
}
