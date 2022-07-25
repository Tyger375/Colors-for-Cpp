#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Colors
{
    int DEF = 0;
    int RED = 31;
    int GREEN = 32;
    int YELLOW = 33;
    int BLUE = 34;
    int PURPLE = 35;
    int AQUA = 36;
};

namespace Styles
{
    int BOLD = 1;
    int ITALIC = 3;
    int UNDERLINED = 4;
    int BLINK = 5;
    int REVERSE = 7; //Background -> forground; forground -> background
    int TRANSPARENT = 8;
};

namespace Codes
{
    vector<string> validTerminals = {
        "xterm"
    };

    bool can_show_colors()
    {
        cout << "toString" << endl;
        char* term = getenv("TERM");
        if (term == NULL)
        {
            return false;
        }
        string toString = term;
        bool found = false;
        for (auto validTerminal : validTerminals)
        {
            if (validTerminal == toString)
            {
                found = true;
                break;
            }
        }
        return found;
    };
    string prefix = "\033[";
    string end = "m";
    string String(int code) { return (prefix + to_string(code) + end); };

    //Colors
    string red() { return String(Colors::RED); };
    string green() { return String(Colors::GREEN); };
    string yellow() { return String(Colors::YELLOW); };
    string blue() { return String(Colors::BLUE); };
    string purple() { return String(Colors::PURPLE); };
    string aqua() { return String(Colors::AQUA); };
    string def() { return String(Colors::DEF); };

    //Styles
    string off(int code) { return String(stoi("2" + to_string(code))); };
    string bold() { return String(Styles::BOLD); };
    string italic() { return String(Styles::ITALIC); };
    string underline() { return String(Styles::UNDERLINED); };
    string blink() { return String(Styles::BLINK); };
    string reverse() { return String(Styles::REVERSE); };
    string transparent() { return String(Styles::TRANSPARENT); };

    string background(int code) { return String(code + 10); };
    string make(string String, vector<string> styles, vector<string> ends={def()}) {
        string final_str;
        for (auto style : styles)
        {
            final_str += style;
        }
        final_str += String;
        for (auto end : ends)
        {
            final_str += end;
        }
        return final_str;
    }
};
