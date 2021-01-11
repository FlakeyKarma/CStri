#include "CStri.h"

int main(int argc, char **argv){
  formatting *F = new formatting;
  char *WORD = (char *)calloc('\0', 5);
  WORD = (char *)"WuRdZ";


  //Exhibit 0
  //This is the base of printing character by character to STDOUT
  F->c_printf(WORD, 5, 4, 1);

  //Exhibit 1
  //This is the base of putting characters to an array and returning them
  std::printf("%s", F->c_strf(WORD, 5, 4, 1));

  //Exhibit 2
  //This is the extension of c_printf to aid in justification and focusing array
  //  to one side or the other
  std::printf("START=>");
  F->lr_printf(WORD, 8, 7, NO_NEWLINE, LEFT_JUSTIFIED);
  std::printf("<=END\n");

  //Exhibit 3
  //This is the extension of c_strf, similar in fashion to lr_printf but returns
  //  char array
  std::printf("START=>%s<=END\n", F->lr_strf(WORD, 4, 8, NO_NEWLINE, RIGHT_JUSTIFIED));

  return 0;
}
