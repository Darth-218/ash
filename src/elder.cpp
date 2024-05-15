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
#define LF std::endl

auto main(int argc, char **argv) -> int {
  std::stringstream s;
  std::stringstream ss;
  s << ELDER_PATH << "/" << argv[1];
  if (access(s.str().c_str(), F_OK)) {
    TTY << "TODO: wait for afifi to finish `view-file'" << LF;
    ss << "less " << s.str() << ".elder";
    system(ss.str().c_str());
  }
  else
    return -1;                  /* ERROR */
  return 0;                     /* SUCCESS */
}

/* elder.cpp ends here */
