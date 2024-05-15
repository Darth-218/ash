/* change-pos.cpp --- change your position in the directory tree
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Maintaner: alchemistsGestalt
 * Created: 13 May, 2024
 * Modified: 15 May, 2024
 * Homepage: https://github.com/darth-218/ash
 *
 * Code:
 */

#include "ash.hpp"

auto main(int argc, char **argv) -> int {
  if (argc <= 1) {
    ERR << argv[0] << ": too few arguments: " << argc << LF;
    return -1;
  } else if (!std::filesystem::is_directory(argv[1])) {
    ERR << argv[0] << ": no such file or directory: " << argv[1] << LF;
    return -1;
  }
  TTY << "entering " << argv[1] <<  LF;
  std::filesystem::current_path(argv[1]);
  return 0;
}

/* change-pos.cpp ends here */
