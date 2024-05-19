#include <cstdlib>
#include <cstring>
#include <iostream>

#define ARGS_DELIMITERS " \n\t"
#define BUFFER_SIZE 1024

using namespace std;

char *ash_readlines(void) {

  char *buffer = NULL;
  unsigned long buffer_size = 0;

  if (getline(&buffer, &buffer_size, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    } else
      exit(EXIT_FAILURE);
  }
  return buffer;
}

char **ash_splitargs(char *line) {

  int position = 0;
  char **args = (char **)malloc(64 * sizeof(char *));
  char *arg;

  arg = strtok(line, ARGS_DELIMITERS);

  while (arg != NULL) {
    args[position] = arg;
    arg = strtok(NULL, ARGS_DELIMITERS);
    position++;
  }
  *(args + position) = NULL;

  return args;
}

int ash_run(char **args) {

  int status;

  if (args[0] == NULL) {
    return 1;
  }

  return status;
}

void ash_loop(void) {

  char *command;
  char **args;
  int command_status;

  do {
    cout << "[ash]:> ";
    command = ash_readlines();
    args = ash_splitargs(command);
    command_status = ash_run(args);
  } while (command_status);
}
