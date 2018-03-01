#include <string.h>
#include <stdio.h>
#include "tokenhelper.h"

int main(){
  printf("enter a sentence:\n");
   char line[256];
   fgets(line, 256, stdin);
   line[strlen(line)-1] = '\0';
   char s[3] = ", ";
   char **strArr = stringToTokens(line, s);
   int i = 0;

   while(strArr[i] != NULL){
     reverse(strArr[i]);
     printf("%s ", strArr[i]);
     i++;
   }
   destroyTokens(strArr);

}
