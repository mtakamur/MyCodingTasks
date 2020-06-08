#ifndef Formatter_H
#define Formatter_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Format
{
private:
    bool ARGLESS = false;
    bool HEADERLESS = false;
    bool PROGRAM_NAME_INPUT = false;
    bool NOSTD = false;

    vector<string> options;
    vector<ofstream *> ofiles;
    vector<char *> argv;
    string program_name; // To be generated
    int argc;

public:
    Format(int number_of_args, char *list_of_args[]);
    ~Format();

    void GenerateFormat();
    void ReadOptions();
    void ShowStatus(); // For debug
    void SwitchOptionFlags();
};
#endif