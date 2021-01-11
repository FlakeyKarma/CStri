#include "CStri.h"

void formatting::c_printf(char *s, char l, char r, bool n){
  bool STRING_READ = 0;
  for(char i = 0; i < 2; i++){
    for(char j = 0; j < (i?r:l); j++) std::printf(" ");
    if(!i) for(unsigned char j = 0; j < strlen(s); j++) std::printf("%c", s[j]);
    if(i && n) std::printf("\n");
  }
}

char *formatting::c_strf(char *in, char l, char r, bool n){
  char *OUT = (char *)calloc('\0', (strlen(in) + l + r + n));
  for(char i = 0; i < 2; i++){
    for(char j = 0; j < (i?r:l); j++) OUT[strlen(OUT)] = ' ';
    if(!i) for(unsigned char j = 0; j < strlen(in); j++) OUT[strlen(OUT)] = in[j];//std::printf("%c", s[j]);
    if(i && n) OUT[strlen(OUT)] = '\n';
  }
  return OUT;
}

void formatting::lr_printf(char *s, char l, char r, bool n, bool j){
  this->set_lr(strlen(s), l, r, j);
  this->c_printf(s, this->local_lr->l, this->local_lr->r, n);
}

char *formatting::lr_strf(char *in, char l, char r, bool n, bool j){
  this->set_lr(strlen(in), l, r, j);
  return this->c_strf(in, this->local_lr->l, this->local_lr->r, n);
}

void formatting::set_lr(char s, char l, char r, bool j){
  //If primary comp side length is GE the length of the char array
  //  then take away from secondary comp
  if((j?r:l) < s) (j?l:r) -= (s-(j?r:l));
  //Regardless, subtract the length given to either side based on their
  (j?r:l) -= s;
  //Set values
  this->local_lr->l = l;
  this->local_lr->r = r;
}
