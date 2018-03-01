#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char **stringToTokens(char *str, char *sep){
  char *token;
  char **strArr = (char **) malloc(sizeof(char*));
  token = strtok(str, sep);

  int i = 0;
  while( token != NULL ) {
     printf( " %s\n", token );
     strArr[i] = (char *) malloc(sizeof(char) + strlen(token));
     strcpy(strArr[i], token);
     strArr = (char **) realloc(strArr, sizeof(char*) + i + 1);
     token = strtok(NULL, sep);
     i++;
  }
  strArr[i] = NULL;
  return strArr;
}


int main(){
  char str[80] = "Hello, I'm Fred";
   char s[10] = ", ";
   char **strArr = stringToTokens(str, s);
   printf("%s\n", strArr[0]);
   printf("%s\n", strArr[1]);
   printf("%s\n", strArr[2]);



}
