#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

void concatenate(char *string_1, char *string_2, char * dest){

  int size_string_1 = 0;
  for(int i = 0; string_1[i] != '\0' ; ++i){
    dest[i] = string_1[i];
    ++size_string_1;
  }

  int k = 0;
  for(int i = size_string_1; string_2[k] != '\0' ; ++i){
    dest[i] = string_2[k];
    ++k;
  }
}