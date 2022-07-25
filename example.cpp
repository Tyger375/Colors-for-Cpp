#include <iostream>
#include "Colors.h"

using namespace std;

int main()
{
  //Checking if the terminal can show colors
  cout << Codes::can_show_colors() << endl;

  /* Printing text
   *  Codes::background(Colors::AQUA) -> "\033[046m"
   *  Codes::red() -> "\033[031m"
   *  Codes::bold() -> "\033[1m"
   *  Codes::def() -> "\033[0m" resets everything
  */
  cout << Codes::background(Colors::AQUA) << Codes::red() << Codes::bold() << "hi" << Codes::def() << endl;

  /* Editing text's style using vectors
   *  Codes::make(
   *    {string Text},
   *    {vector<string> styles},
   *    {vector<string> reset_codes} <- if the parameter is not given, by default, at the end of the text, it resets everything
   *  )
  */
  cout << Codes::make("hi", {Codes::red(), Codes::background(Colors::AQUA), Codes::bold()}) << endl;
  //Returned value: "\033[031m\033[046m\033[1mhi\033[0m"
  return 0;
}