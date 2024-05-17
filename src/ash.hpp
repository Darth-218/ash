/* ash.hpp --- definitions needed by the whole project.
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Created: 13 May, 2024
 * Modified: 17 May, 2024
 * Homepage: https://github.com/darth-218/ash
 *
 * Code:
 */

#ifndef ASH_H_
#define ASH_H_

#ifdef __cplusplus

/* C++ headers */
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define TTY std::cout
#define ERR std::cerr
#define QUAD std::cin
#define LF std::endl

#endif /* __cplusplus */

/* C headers */
#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/* Paths */
#define BIN_PATH "ash/bin"
#define ELDER_PATH "ash/elder"

#endif /* ASH_H_ */

/* ash.hpp ends here */
