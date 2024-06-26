#include "ash.hpp"
#include <vector>

using namespace std;

class HistoryManager
{
private:
  static string historyFilePath;

  static vector<string> getHistoryLines()
  {
    fstream fileStream(HistoryManager::historyFilePath == "" ? "/home/ash/history" : HistoryManager::historyFilePath, ios::out | ios::in);
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
    HistoryManager::historyFilePath = "/home/ash/history";
  }

  static int writeToHistory(string command)
  {
    try
    {
      fstream fileStream(HistoryManager::historyFilePath == "" ? "/home/ash/history" : HistoryManager::historyFilePath, ios::app);

      if (fileStream.fail() || !fileStream.is_open())
        return EXT_FAIL;

      fileStream << command;
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
    return "";
  }
};

std::string HistoryManager::historyFilePath = "/home/ash/history";