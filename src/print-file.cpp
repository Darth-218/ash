#include "ash.hpp"

using namespace std;

int main(int argc, char **argv)
{
  if (argv[1] == NULL)
    return EXT_INP;

  string filePath = argv[1];
  try
  {
    if (!(filesystem::exists(filePath)))
    {
      return EXT_NFOUND;
    }

    fstream fileStream(filePath, ios::out | ios::in);

    if (fileStream.fail() || !fileStream.is_open())
      return EXT_FAIL;

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

  return EXT_SUCC;
}