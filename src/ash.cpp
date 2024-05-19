#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

#define ARGS_DELIMITERS " \n\t"

// TODO: Better error handling
// FIX: Program termination
// FIX: Reallocate "args" size as the size increases
// FIX: Keyboard signals
// TODO: Create an array of built-in functions to excute (war crime)
// TODO: Colored outputs

using namespace std;

char *ash_readlines(void) {

  char *buffer = NULL;
  unsigned long buffer_size = 0;

  if (getline(&buffer, &buffer_size, stdin) == -1) {

    cout << "Error reading command" << "\n";
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

int ash_start(char **args) {

  pid_t pid, cpid;
  int status;

  pid = fork();
  if (pid == 0 && execvp(args[0], args) == -1) {
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    cout << "Error Forking" << "\n";
  } else {
    do {
      cpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int ash_run(char **args) {

  int status;

  if (args[0] == NULL) {
    return 1;
  }

  /* for (int i = 0; i < (sizeof(args) / sizeof(char *)); i++) { */
  /* } */

  return ash_start(args);
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
