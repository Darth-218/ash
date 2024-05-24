#include "ash.hpp"
#include <ncurses.h>
#include <vector>

#define SCROLL_CONTENTS_UP 'j'
#define SCROLL_CONTENTS_DOWN 'k'
#define LAST_LINE_ON_SCREEN (min((int)fileContents.size(), LINES) + scrollPosition - 1)

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
      cbreak();
      noecho();
      scrollok(stdscr, TRUE);
      curs_set(0);
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

    for (int i = 0; i < LINES && i < fileContents.size(); i++)
    {
      printw("%s\n", fileContents[i].c_str());
    }
    refresh();

    char command = '\0';
    int scrollPosition = 0;
    while (command != 'q')
    {
      // clear();

      command = getch();
      switch (command)
      {
      case SCROLL_CONTENTS_UP:
        // scroll contents up.
        if (LAST_LINE_ON_SCREEN < fileContents.size() - 1)
        {
          int x, y;
          scrollPosition++;
          printw("%s", fileContents[LAST_LINE_ON_SCREEN].c_str());
          scrl(1);
          getyx(stdscr, y, x);
          move(y, 0);
          refresh();
        }
        break;

      case SCROLL_CONTENTS_DOWN:
        // scroll contents down.
        if (scrollPosition > 0)
        {
          scrollPosition--;
          scrl(-1);
          refresh();
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