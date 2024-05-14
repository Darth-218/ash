#include <filesystem>

using namespace std;

int main(int args, char **argv) {

  for (int arg = 1; arg < args; arg++) {

    filesystem::remove(argv[arg]);
  }
}
