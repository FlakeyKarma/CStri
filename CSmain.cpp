#include "CStri.h"

int main(int argc, char **argv){
  formatting *F = new formatting;
  char *WORD = (char *)calloc('\0', 5), *OTHR;
  WORD = (char *)"wUrD";


  //Exhibit 0
  F->c_printf(WORD, 5, 4, 1);

  //Exhibit 1
  std::printf("%s", F->c_strf(WORD, 5, 4, 1));

  return 0;
}
