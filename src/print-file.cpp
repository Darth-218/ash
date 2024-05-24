#include "ash.hpp"

using namespace std;

int main(int argc, char **argv)
{
  if (argv[1] == '\0')
    return -1;
  string filePath = argv[1];
  try
  {
    if (!(filesystem::exists(filePath)))
    {
      return 2;
    }

    fstream fileStream(filePath, ios::out | ios::in);

    if (fileStream.fail() || !fileStream.is_open())
      return -1;

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