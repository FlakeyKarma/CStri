#include <iostream>
#include "string.h"

class formatting{
public:
  void c_printf(char *char_array_to_print, char left_distance, char right_distance, bool end_with_newline);
  char *c_strf(char *char_array_to_format, char left_distance, char right_distance, bool end_with_newline);
};
