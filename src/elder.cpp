/* elder.cpp --- consult the elder for advice on how to move forward
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Maintaner: alchemistsGestalt
 * Created: 13 May, 2024
 * Modified: 20 May, 2024
 * Homepage: https://github.com/darth-218/ash
 *
 * Code:
 */

#define MAIN
#include "ash.hpp"

auto main(int argc, char **argv) -> int {
  if (argc <= 1) {
    ERR << argv[0] << ": too few arguments: " << argc << LF;
    return -1;
  }
  std::stringstream s;
  s << getenv("HOME") << "/" << ELDER_PATH << "/" << argv[1] << ".elder";
  if (std::filesystem::exists(s.str())) {
    std::string args[] = {"view-file", s.str().c_str()};
    ash_run((char **) args);
  }
  else {
    ERR << argv[0] << ": invalid argument: " << argv[1] << LF;
    return -1;                  /* ERROR */
  }
  return 0;                     /* SUCCESS */
}

/* elder.cpp ends here */
