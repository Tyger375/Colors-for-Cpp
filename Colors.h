#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

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
    //If your terminal supports colors and it isn't here, please, add its name and make a pull request
    //You can see your terminal's name by debugging the "term" variable
    vector<string> validTerminals = {
        "xterm",
        "xterm-256color"
    };

    bool can_show_colors()
    {
        char* term = getenv("TERM");
        if (term == NULL)
        {
            return false;
        }
        //cout << term << endl;
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
    string String(int code) { return can_show_colors() ? (prefix + to_string(code) + end) : ""; };

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
        if (!can_show_colors())
        {
            return String;
        }
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

class ProgressBar
{
public:
   float progress;
   int goal;
   string strinfos;
   char progress_char;
   string color;
   ProgressBar(char c=' ', int goal=10, string info="", string Color=Codes::background(Colors::GREEN))
   {
	this->progress = 0;
	this->goal = goal;
	progress_char = c;
	this->strinfos = info;
	this->color=Color;
   };
   int getPercentage() {
	float divided = (float)(progress / (float)this->goal);
	return (int)(divided*100);
   };
   void infos()
   {
	printf("%s: ", strinfos.c_str());
   }
   void debug()
   {
	printf("\033[0m");
	for (int i = 100; i > getPercentage(); i--)
	{
	   printf(" ");
	}
	printf("\t\t\t%d/%d - %d%%", (int)this->progress, this->goal, getPercentage());
   }
   void update(float increment)
   {
	printf("\r");
	this->infos();
	printf("%s", color.c_str());
	for (int j = 0; j < getPercentage(); j++)
	{
           printf("%c", this->progress_char);
	}
	this->debug();
	printf("\033[0m");
	this->progress += increment;
	fflush(stdout);
   };
};

