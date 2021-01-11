#include "formatC.h"

void formatting::c_printf(char *s, char l, char r, bool n){
  bool STRING_READ = 0;
  for(char i = 0; i < 2; i++){
    for(char j = 0; j < (i?l:r); j++) std::printf(" ");
    if(!i) for(unsigned char j = 0; j < strlen(s); j++) std::printf("%c", s[j]);
    if(i && n) std::printf("\n");
  }
}

char *formatting::c_strf(char *in, char l, char r, bool n){
  char *OUT = (char *)calloc('\0', (strlen(in) + l + r + n));
  for(char i = 0; i < 2; i++){
    for(char j = 0; j < (i?l:r); j++) OUT[strlen(OUT)] = ' ';
    if(!i) for(unsigned char j = 0; j < strlen(in); j++) OUT[strlen(OUT)] = in[j];//std::printf("%c", s[j]);
    if(i && n) OUT[strlen(OUT)] = '\n';
  }
  return OUT;
}
