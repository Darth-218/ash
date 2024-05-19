/* main.cpp --- main entry point for the `ash` shell
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Maintaner: Darth-218
 * Created: 13 May, 2024
 * Modified: 13 May, 2024
 * Homepage: https://github.com/darth-218/ash
 *
 * Code:
 */

#include "ash.cpp"
#include <iostream>

auto main(int argc, char *argv[]) -> int {
  ash_loop();
  return 0;
}

/* main.cpp ends here */
