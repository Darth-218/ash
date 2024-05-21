#include "ash.hpp"

int change_dir(char **directory) {
  if (directory[1] == NULL)
    return -1;
  std::string target = directory[1];
  if (!std::filesystem::is_directory(target))
    return -1;

  std::filesystem::current_path(target);
  std::cout << "cd-ed to \"" << target << "\"\n";
  return 1;
}

int exit_ash(char **) { return 0; }

std::string builtins[] = {"change-dir", "exit"};
int (*ash_functions[])(char **) = {&change_dir, &exit_ash};
