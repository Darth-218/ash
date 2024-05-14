#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  string filePath = argv[1];
  try
  {
    fstream fileStream;
    fileStream.open(filePath, ios::out | ios::in);

    if (fileStream.fail())
    {
      // report an error and return.
    }

    while (!fileStream.eof())
    {
      string line;
      getline(fileStream, line);
      cout << line << endl;
    }

    fileStream.close();
  }
  catch (const std::exception &e)
  {
    cerr << e.what() << '\n';
  }

  return 0;
}