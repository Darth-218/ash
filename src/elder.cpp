/* elder.cpp --- consult the elder for advice on how to move forward
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Maintaner: alchemistsGestalt
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 * Homepage: https://github.com/darth-218/ash
 *
 * Code:
 */

#include "ash.hpp"

#define TTY std::cout
#define ERR std::cerr
#define LF std::endl

auto main(int argc, char **argv) -> int {
  if (argc <= 1) {
    ERR << argv[0] << ": too few arguments: " << argc << LF;
    return -1;
  }
  std::stringstream s;
  s << "/home/rosethorn/ash" << "/" << argv[1] << ".elder";
  if (access(s.str().c_str(), F_OK)) {
    TTY << "TODO: wait for afifi to finish `view-file'" << LF;
  }
  else {
    ERR << argv[0] << ": invalid argument: " << argv[1] << LF;
    return -1;                  /* ERROR */
  }
  return 0;                     /* SUCCESS */
}

/* elder.cpp ends here */
