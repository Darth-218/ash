#include "ash.hpp"
#include "ash_builtins.cpp"
#include "history.hpp"
#include <csignal>
#include <readline/readline.h>
#include <sys/wait.h>

#define ARGS_DELIMITERS " \n\t\""

// FIX: Reallocate "args" size as the size increases
// FIX: Keyboard signals
// TODO: Better error handling
// TODO: Colored outputs
// TODO: Configuration file

using namespace std;

char *ash_readlines(void) {

  char *buffer = NULL;
  unsigned long buffer_size = 0;

  /* if (getline(&buffer, &buffer_size, stdin) == -1) { */
  if ((buffer = readline(NULL))) {
    if (feof(stdin))
      exit(EXIT_SUCCESS);
    else
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

int ash_start(char **args) {

  pid_t pid, cpid;
  int status;

  pid = fork();
  if (pid == 0) {

    int status = execvp(args[0], args);

    if (status == -1) {

      string newpath = (string)getenv("HOME") + "/" + (string)BIN_PATH + "/" +
                       (string)args[0];
      const char *cnewpath = newpath.c_str();
      status = execvp(cnewpath, args);

      if (status == -1) {
        cout << "Failed to excute \"" << args[0] << "\", does it exist?\n";
        exit(EXIT_FAILURE);
      }
    }
  } else if (pid < 0) {
    perror("Error forking");
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

  for (int i = 0; i < 2; i++) {
    if ((string)args[0] == builtins[i]) {
      return (*ash_functions[i])(args);
    }
  }

  return ash_start(args);
}

void handler(int signum) { ; }

string path() {
  string path = filesystem::current_path();
  string target = getenv("HOME");
  size_t pos = path.find(target);
  if (pos == std::string::npos)
    return path;
  path.replace(pos, target.length(), "~");
  return path;
}

void ash_loop(void) {

  char *command;
  char **args;
  int command_status = 0;

  do {
    signal(SIGINT, handler);
    cout << path() << "> ";
    command = ash_readlines();
    HistoryManager::init();
    HistoryManager::writeToHistory((string)command);
    args = ash_splitargs(command);
    command_status = ash_run(args);

    free(command);
    free(args);
  } while (command_status);
}
