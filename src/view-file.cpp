#include "ash.hpp"
#include <ncurses.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  if (argv[1] == NULL)
    return EXT_INP;

  string filePath = argv[1];
  vector<string> fileContents;
  try
  {
    if (!(filesystem::exists(filePath)))
    {
      endwin();
      return EXT_NFOUND;
    }
    else
    {
      initscr();
    }

    fstream fileStream;
    fileStream.open(filePath, ios::out | ios::in);

    if (fileStream.fail())
    {
      // report an error and return.
      return EXT_FAIL;
    }

    while (!fileStream.eof())
    {
      string line;
      getline(fileStream, line);
      fileContents.push_back(line);
      // printw("%s\n", line.c_str());
    }
    fileStream.close();

    char command = '\0';
    int currentLine = 0;
    while (command != 'q')
    {
      clear();
      for (int i = currentLine; i < LINES + currentLine && i < fileContents.size(); i++)
      {
        printw("%s\n", fileContents[i].c_str());
      }

      // command = getch();
      sleep(5);
      switch (command)
      {
      case 'j':
        // scroll contents up.
        if (currentLine < fileContents.size() - LINES - 1)
        {
          currentLine++;
        }
        break;

      case 'k':
        // scroll contents down.
        if (currentLine > 0)
        {
          currentLine--;
        }

        break;

      default:
        break;
      }
    }

    endwin();

    return EXT_SUCC;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}