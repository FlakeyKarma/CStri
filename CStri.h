#include <iostream>
#include "string.h"

#define FAL 0
#define TRU 1
#define LEFT_JUSTIFIED FAL
#define RIGHT_JUSTIFIED TRU
#define NO_NEWLINE FAL
#define AD_NEWLINE TRU

class formatting{
private:
  struct LR_CONTAINER {
    char l;
    char r;
  }lrc;
  char *OUTPUT = (char *)calloc('\0', 256);
  void set_lr(char word_length, char left_distance, char right_distance, bool justification);
  formatting::LR_CONTAINER *local_lr = new formatting::LR_CONTAINER;
  //Directly print the char array that has a specific number of white space added to both sides
  void c_printf(char *char_array_to_print, bool newline);
  //Return new char array
  char *c_strf(char *char_array_to_format, bool newline);
  //Reset values
  void vReset();
public:
  //Print the char array with desired number of characters to right/left of it,
  //  with one of the values compensating for the length of the char array
  //  primarily and the other as the static or secondary length compensation
  void lr_printf(char *char_array_to_print, char left_distance, char right_distance, bool newline, bool justification);
  //Return new char array with desired number of white space to each side
  char *lr_strf(char *char_array_to_format, char left_distance, char right_distance, bool newline, bool justification);
};
