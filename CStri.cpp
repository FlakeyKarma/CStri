#include "CStri.h"

void formatting::c_printf(char *s, bool n){
  bool STRING_READ = 0;
  for(char i = 0; i < 2; i++){
    for(char j = 0; j < (i?this->local_lr->r:this->local_lr->l); j++) std::printf(" ");
    if(!i) for(unsigned char j = 0; j < strlen(s); j++) std::printf("%c", s[j]);
    if(i && n) std::printf("\n");
  }
  this->vReset();
}

char *formatting::c_strf(char *in, bool n){
  //this->OUTPUT = (char *)calloc('\0', (strlen(in) + this->local_lr->l + this->local_lr->r  + n + 1));
  for(char i = 0; i < 2; i++){
    for(char j = 0; j < (i?this->local_lr->r:this->local_lr->l); j++) this->OUTPUT[strlen(this->OUTPUT)] = ' ';
    if(!i) for(unsigned char j = 0; j < strlen(in); j++) this->OUTPUT[strlen(this->OUTPUT)] = in[j];//std::printf("%c", s[j]);
    if(i && n) this->OUTPUT[strlen(this->OUTPUT)-1] = '\n';
  }
  this->vReset();
  return this->OUTPUT;
}

void formatting::lr_printf(char *s, char l, char r, bool n, bool j){
  this->set_lr(strlen(s), l, r, j);
  this->c_printf(s, n);
}

char *formatting::lr_strf(char *in, char l, char r, bool n, bool j){
  this->set_lr(strlen(in), l, r, j);
  return this->c_strf(in, n);
}

void formatting::set_lr(char s, char l, char r, bool j){
  //If primary comp side length is GE the length of the char array
  //  then take away from secondary comp
  if((j?r:l) < s) (j?l:r) -= (s-(j?r:l));
  //Regardless, subtract the length given to either side based on their
  (j?r:l) -= s;
  //Set values
  this->local_lr->l = (l >= 0?l:0);
  this->local_lr->r = (r >= 0?r:0);
}

void formatting::vReset(){
  this->local_lr->l = 0;
  this->local_lr->r = 0;
  for(unsigned int i = 0; i < strlen(this->OUTPUT); i++) this->OUTPUT[i] = '\0';
}
