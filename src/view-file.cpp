#include "ash.hpp"
#include <ncurses.h>
#include <vector>

#define BOTTOM_WINDOW_HEIGHT 3
#define MAIN_WINDOW_HEIGHT (LINES - BOTTOM_WINDOW_HEIGHT)
#define SCROLL_CONTENTS_UP 'j'
#define SCROLL_CONTENTS_DOWN 'k'
#define LAST_LINE_ON_SCREEN (min((int)fileContents.size(), MAIN_WINDOW_HEIGHT) + scrollPosition - 1)
#define FIRST_LINE_ON_SCREEN (LAST_LINE_ON_SCREEN - MAIN_WINDOW_HEIGHT + 1)

using namespace std;

int main(int argc, char **argv)
{
  if (argv[1] == NULL)
    return EXT_INP;

  string filePath = argv[1];
  vector<string> fileContents;
  WINDOW *mainWindow;
  WINDOW *bottomWindow;
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
      mainWindow = newwin(MAIN_WINDOW_HEIGHT, COLS - 1, 0, 0);
      scrollok(mainWindow, TRUE);
      curs_set(0);
      bottomWindow = newwin(BOTTOM_WINDOW_HEIGHT, COLS - 1, MAIN_WINDOW_HEIGHT, 0);
      box(bottomWindow, 0, 0);
      mvwprintw(bottomWindow, 1, 1, "quit: q | scroll_up : j |scroll_down: k");
      refresh();
      wrefresh(bottomWindow);
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

    for (int i = 0; i < MAIN_WINDOW_HEIGHT && i < fileContents.size(); i++)
    {
      mvwprintw(mainWindow, i, 0, "%s", fileContents[i].c_str());
    }
    wrefresh(mainWindow);

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
          scrollPosition++;
          wscrl(mainWindow, 1);
          wmove(mainWindow, MAIN_WINDOW_HEIGHT - 1, 0);
          wprintw(mainWindow, "%s", fileContents[LAST_LINE_ON_SCREEN].c_str());
          wrefresh(mainWindow);
        }
        break;

      case SCROLL_CONTENTS_DOWN:
        // scroll contents down.
        if (scrollPosition > 0)
        {
          scrollPosition--;
          wscrl(mainWindow, -1);
          wmove(mainWindow, 0, 0);
          wprintw(mainWindow, "%s", fileContents[FIRST_LINE_ON_SCREEN].c_str());
          wrefresh(mainWindow);
        }

        break;

      default:
        break;
      }

      wrefresh(mainWindow);
      wrefresh(bottomWindow);
    }

    endwin();

    return EXT_SUCC;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}