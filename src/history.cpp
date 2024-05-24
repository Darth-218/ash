#include "ash.hpp"
#include <vector>

using namespace std;

class HistoryManager
{
private:
  static string historyFilePath;

  static vector<string> getHistoryLines()
  {
    fstream fileStream(HistoryManager::historyFilePath == "" ? "./../command-history" : HistoryManager::historyFilePath, ios::out | ios::in);
    vector<string> lines;

    if (fileStream.fail() || !fileStream.is_open())
      return lines;

    while (!fileStream.eof())
    {
      string line;
      getline(fileStream, line);
      lines.push_back(line);
    }

    fileStream.close();
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
      fstream fileStream(HistoryManager::historyFilePath == "" ? "./../command-history" : HistoryManager::historyFilePath, ios::app);

      if (fileStream.fail() || !fileStream.is_open())
        return EXT_FAIL;

      fileStream << command << '\n';
      fileStream.close();
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }

    return EXT_SUCC;
  }

  static string readFromHistory(int orderOfCommand)
  {
    try
    {
      vector<string> lines = HistoryManager::getHistoryLines();
      return lines[lines.size() - orderOfCommand - 1];
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
    return "shit";
  }
};

std::string HistoryManager::historyFilePath = "./../command-history";
