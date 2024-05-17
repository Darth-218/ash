#include<iostream>
#include<fstream>
#include<string>
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