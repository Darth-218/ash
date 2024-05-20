/* punch.cpp --- touch more aggressively
 *
 * Copyright (C) 2024 First Time Compile
 *
 * Author: Mazen Ahmed Refaei
 * Maintainer: Mazen Ahmed Refaei
 * Created: 17 May, 2024
 * Modified: 20 May, 2024
 *
 * Code:
 */

#include "ash.hpp"

using namespace std;

int main(int argc , char* argv[]){
    string new_file;
    new_file= argv[1];
    fstream file;
    file.open(new_file,ios::in | ios::out |ios::app);
    file.close();
    return 0;
}

// another method
/*
    fstream file;
    file.open(argv[1],ios::in | ios::out | ios::trunc);
    file.close();
    */

/* punch.cpp ends here */
