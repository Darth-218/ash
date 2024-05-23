#include "ash.hpp"

int change_dir(char **directory) {
  std::string target;
  if (directory[1] == NULL)
    target = getenv("HOME");
  else target = directory[1];
  size_t home_pos = target.find("~");
  if (home_pos != std::string::npos)
    target.replace(home_pos, 1, getenv("HOME"));
  if (!std::filesystem::is_directory(target))
    return -1;

  std::filesystem::current_path(target);
  std::cout << "cd-ed to \"" << target << "\"\n";
  return 1;
}

int exit_ash(char **) { return 0; }

std::string builtins[] = {"change-dir", "exit"};
int (*ash_functions[])(char **) = {&change_dir, &exit_ash};
