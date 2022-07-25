# Colors for C++

A module for printing easily coloured texts in C++

- [How to use](#how-to-use)
  - [Colors namespace](#colors-namespace)
  - [Styles namespace](#styles-namespace)
  - [Codes namespace](#codes-namespace)
    - ["Can show colors" function](#can-show-colors-function)
    - [String function](#string-function)
    - [Color functions](#color-functions)
    - [Resetting style](#resetting-style)
    - [Editing text's style using vectors](#editing-texts-style-using-vectors)
    - [Backgrounds](#backgrounds)
- [Links and socials](#links-and-socials)

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

### Can show colors function
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

### String function
```cpp
string String(int code);
```
This function is used for making the final string to print.<br>
You don't have to call this function, it will be called when you need a color

### Color functions
```cpp
//Example of a function that returns a color
string red();
//Example of a function that returns a style
string bold();
```
These are the functions that you have to call when you need to style or color a text.<br>
You just have to call this function when printing before the text:<br>
```cpp
cout << Codes::red() << Codes::bold() << "this is a red bold text" << endl;
```

### Resetting style
If you want to reset the style after using it, you can choose between:
- Resetting everything by using the "def" function
```cpp
cout << Codes::red() << Codes::bold() << "this is a red bold text" << Codes::def() << endl; //Resetting every style added
```
- Resetting a single style (not a color or bold style) by using the "off" function, with the style code which you can find inside the "Styles" namespace
```cpp
cout << Codes::red() << Codes::bold() << "this is a red bold text" << Codes::off(Styles::BOLD) << endl; //Resetting only the bold style
```

### Editing text's style using vectors
If you don't want to add every single style everytime you need it, you can use vectors and the "make" function<br>
```cpp
string make(
  string String, //Text to style
  vector<string> styles, //Styles to add
  vector<string> ends={def()} //Styles to reset at the end, by default it resets everything
  );
```
For example:<br>
```cpp
vector<string> styles = {
  Codes::red(),
  Codes::underline()
};

vector<string> styles_to_remove = {
  Codes::off(Styles::UNDERLINED)
};

cout << Codes::make("Red and underlined text", styles, styles_to_remove);
cout << "Red text, because I only reset the underline style" << endl;
```

### Backgrounds
If you want to set a background color for your text, you use the "background" function.<br>
```cpp
string background(int code);
```
Available color codes are inside the "Colors" namespace.

# Links and socials

- Discord: `tyger 375#4141`<br>
- Web site: https://tyger375.tk/ <br>
- Twitter: https://twitter.com/375tyger <br>