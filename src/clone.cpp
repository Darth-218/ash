/* clone.cpp --- recreate the plot of the second star wars movie
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: Mazen Ahmed Refaei
 * Maintainer: Mazen Ahmed Refaei
 * Created: 18 May, 2024
 * Modified: 20 May, 2024
 *
 * Code:
 */

#include "ash.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  string original = argv[1];
  string cpfile = argv[2];
  fstream file1;
  string line;
  string content = "";
  file1.open(original); // file should be existed
  if (!file1.is_open()) {
    cout << "file not exist\n";
  } else {
    while (file1.good()) {
      getline(file1, line);
      content += line + "\n";
    }
  }
  file1.close();
  ofstream file2(cpfile);
  file2 << content << endl;
  file2.close();
  return 0;
}

/* clone.cpp ends here */
