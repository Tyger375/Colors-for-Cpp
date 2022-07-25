# Colors for C++

A module for printing easily coloured texts in C++

# How to use

Colors, styles and functions are divided by different namespaces

## Colors namespace
```cpp
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
```

This namespace contains all the codes for every color

## Styles namespace
```cpp
namespace Styles
{
  int BOLD = 1;
  int ITALIC = 3;
  int UNDERLINED = 4;
  int BLINK = 5;
  int REVERSE = 7; //Background -> forground; forground -> background
  int TRANSPARENT = 8;
};
```

This namespace contains all the codes for every style a text can have<br>
You can add multiple styles for a single text

## Codes namespace

This namespace contains all the function for make your code easy to write and read<br>

Not all terminals can show colors<br>
You can check if the user's terminal can by calling the function "can_show_colors"<br>
```cpp
bool can_show_colors();
```

This function watches the environment variable "TERM", and checks if the value is in the vector "validTerminals"

```cpp
vector<string> validTerminals = {
  "xterm",
  "xterm-256color",
};
```

If your terminal supports colors but it's not in the array, please, make a pull request and add the terminal's name<br>
(You can see the name by debugging the variable "term")

