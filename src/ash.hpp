/* ash.hpp --- definitions needed by the whole project.
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: alchemistsGestalt
 * Created: 13 May, 2024
 * Modified: 20 May, 2024
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
#include <readline/readline.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* Paths */
#define BIN_PATH "ash/bin"
#define ELDER_PATH "ash/elder"

/* Functions used by the main loop */
#ifdef MAIN
char *ash_readlines();
char **ash_splitargs(char *line);
int ash_start(char **args);
int ash_run(char **args);
void ash_loop();
int change_dir(std::string directory);
#endif  /* MAIN */

/* Exit Codes */
enum exit_codes {
  EXT_SUCC,                     /* Success */
  EXT_FAIL,                     /* Failure */
  EXT_NFOUND,                   /* Not Found */
  EXT_ARG,                      /* Invalid Argument */
  EXT_INP,                      /* Improper Input */
  EXT_OS,                       /* Problem out of our control */
};

#endif /* ASH_H_ */

/* ash.hpp ends here */
