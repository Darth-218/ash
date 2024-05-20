#include "ash.hpp"

int change_dir(std::string directory) {
  if (!std::filesystem::is_directory(directory)) {
    return -1;
  }
  std::filesystem::current_path(directory);
  std::cout << "cd-ed\n";
  return 1;
}

int exit_ash(std::string) { return -1; }

std::string builtins[] = {"change-dir", "exit"};
int (*ash_functions[])(std::string) = {&change_dir, &exit_ash};
