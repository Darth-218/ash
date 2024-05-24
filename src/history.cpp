#include "ash.hpp"
#include <vector>

using namespace std;

class HistoryManager
{
private:
  static string historyFilePath;

  static vector<string> getHistoryLines()
  {
    fstream fileStream(HistoryManager::historyFilePath == "\0" ? "./../command-history" : HistoryManager::historyFilePath, ios::out);
    vector<string> lines;

    if (fileStream.fail() || !fileStream.is_open())
      return lines;

    while (!fileStream.eof())
    {
      string line;
      getline(fileStream, line);
      lines.push_back(line);
    }

    return lines;
  }

public:
  static void init()
  {
    HistoryManager::historyFilePath = "./../command-history";
  }

  static int writeToHistory(string command)
  {
    try
    {
      fstream fileStream(HistoryManager::historyFilePath == "\0" ? "./../command-history" : HistoryManager::historyFilePath, ios::app);

      if (fileStream.fail() || !fileStream.is_open())
        return -1;

      fileStream << command << '\n';
      fileStream.close();
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }

    return 0;
  }

  static string readFromHistory(int orderOfCommand)
  {
    try
    {
      vector<string> lines = HistoryManager::getHistoryLines();
      return lines[lines.size() - orderOfCommand];
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
  }
};
