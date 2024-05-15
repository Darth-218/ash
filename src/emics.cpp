/* emics.cpp --- editor micros
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Maintainer: alchemistsGestalt
 * Created: 14 May, 2024
 * Modified: 14 May, 2024
 * Homepage: https://github.com/darth-218/ash
 *
 * Code:
 */

#include "ash.hpp"

auto main(int argc, char **argv) -> int {
  std::ofstream fout(/* file */ argv[1]);
  while (1) {
    char *input = readline(NULL);
    if (!input)
      break;
    fout << input;
    free(input);
  }
  return 0;
}

/* emics.cpp ends here */
