#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Format.h"
using namespace std;

Format::Format(int number_of_args, char *list_of_args[])
{
    argc = number_of_args;
    for (int iarg = 0; iarg < argc; iarg++)
    {
        argv.push_back(list_of_args[iarg]);
    }

    ReadOptions();
}

Format::~Format()
{
}

void Format::GenerateFormat()
{
    if (!PROGRAM_NAME_INPUT)
    {
        cout << "Program name must be input" << endl;
        return;
    }
    else
    {
        ofiles.resize(2);
        string header_name = program_name + ".h";
        string source_name = program_name + ".cxx";

        ofiles.at(0) = new ofstream(source_name);

        if (!HEADERLESS)
        {
            ofiles.at(1) = new ofstream(header_name);
            //////////////////////////////////
            // Edit source file information //
            //////////////////////////////////
            *ofiles.at(0) << "#include \"" << header_name << "\"" << endl;

            /////////////////////////////
            // Edit header information //
            /////////////////////////////
            *ofiles.at(1) << "#ifndef " << program_name << "_H" << endl;
            *ofiles.at(1) << "#define " << program_name << "_H" << endl;
            *ofiles.at(1) << endl;
            *ofiles.at(1) << "#endif" << endl;
            ofiles.at(1)->close();
        }
        //////////////////////////////////
        // Edit source file information //
        //////////////////////////////////
        *ofiles.at(0) << "#include <iostream>" << endl;
        if (!NOSTD)
        {
            *ofiles.at(0) << "using namespace std;" << endl;
        }
        *ofiles.at(0) << endl;

        if (!ARGLESS)
        {
            *ofiles.at(0) << "int main(int argc, char* argv[])" << endl;
            *ofiles.at(0) << "{" << endl;
            *ofiles.at(0) << endl;
            *ofiles.at(0) << "\treturn 0;" << endl;
            *ofiles.at(0) << "}" << endl;
            ofiles.at(0)->close();
        }
        else
        {
            *ofiles.at(0) << "int main()" << endl;
            *ofiles.at(0) << "{" << endl;
            *ofiles.at(0) << endl;
            *ofiles.at(0) << "\treturn 0;" << endl;
            *ofiles.at(0) << "}" << endl;
            ofiles.at(0)->close();
        }
    }
    ///////////////////////
    // Terminate message //
    ///////////////////////
    if(!HEADERLESS)
    {
        cout << program_name << ".h and " << program_name << ".cxx have been generated." << endl;
    }
    else
    {
        cout << program_name << ".cxx has been generated." << endl;
    }
    return;
}

void Format::Help()
{
    cout << "////////////////////////////////////////////////////////////" << endl;
    cout << "/////////////////////" << endl;
    cout << "// List of options //" << endl;
    cout << "/////////////////////" << endl;
    cout << "-argless" << endl;
    cout << "\tCall if you don't need argc and argv in main function." << endl;
    cout << endl;
    cout << "-headerless" << endl;
    cout << "\tGenerate source file without header." << endl;
    cout << endl;
    cout << "-nostd" << endl;
    cout << "\tCall to eliminate \"using namespace std;\" from SOURCE.cxx." << endl;
    cout << "////////////////////////////////////////////////////////////" << endl;
    return;
}

void Format::ReadOptions()
{
    for (int iarg = 1; iarg < argc; iarg++)
    {
        string arg = argv.at(iarg);
        if (arg.substr(0, 2) == "--")
        {
            options.push_back(arg.substr(2, arg.size() - 2));
        }
        else if (arg.substr(0, 1) == "-")
        {
            options.push_back(arg.substr(1, arg.size() - 1));
        }
        else
        {
            if (PROGRAM_NAME_INPUT == false)
            {
                program_name = arg;
                PROGRAM_NAME_INPUT = true;
            }
        }
    }

    SwitchOptionFlags();
    return;
}

void Format::ShowStatus()
{
    ////////////////
    // Show flags //
    ////////////////
    cout << "ARGLESS = " << ARGLESS << endl;
    cout << "HEADERLESS = " << HEADERLESS << endl;
    cout << "PROGRAM_NAME_INPUT = " << PROGRAM_NAME_INPUT << endl;

    cout << endl;
    cout << "Number of arguments = " << argc << endl;
    cout << "Program name = " << program_name << endl;

    for (int iopt = 0; iopt < options.size(); iopt++)
    { // Show options
        cout << options.at(iopt) << endl;
    }
    return;
}

void Format::SwitchOptionFlags()
{
    for(int iopt=0; iopt<options.size(); iopt++)
    {
        if(options.at(iopt) == "argless")
        {
            ARGLESS = true;
        }
        else if (options.at(iopt) == "headerless")
        {
            HEADERLESS = true;
        }
        else if (options.at(iopt) == "nostd")
        {
            NOSTD = true;
        }
        else if (options.at(iopt) == "help" || options.at(iopt) == "h")
        {
            Help();
            exit(0);
        }
        else
        {
            cout << "Invalid option input" << endl;
        }
    }
    return;
}