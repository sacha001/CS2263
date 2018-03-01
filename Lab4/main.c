#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char **stringToTokens(char *str, char *sep){
  char *token;
  char **strArr = (char **) malloc(sizeof(char*));
  token = strtok(str, sep);

  int i = 0;
  while( token != NULL ) {
     strArr = (char **) realloc(strArr, sizeof(char*) * (i + 1));
     strArr[i] = (char *) malloc(sizeof(char) + strlen(token));
     strcpy(strArr[i], token);
     token = strtok(NULL, sep);
     i++;
  }
  strArr[i] = NULL;

  return strArr;
}

void destroyTokens(char **tokenArray){
  int i = 0;
  while(tokenArray[i] != NULL){
    free(tokenArray[i]);
    i++;
  }
  free(tokenArray);
}

void reverse(char *s){
  char *tmp = malloc(sizeof(char) * strlen(s));
  int j = 0;
  int len = strlen(s);

  for(int i = len - 1; i >= 0; i--){
    tmp[j] = s[i];
    j++;
  }
  for(int i = 0; i < len; i++){
    s[i] = tmp[i];
  }
  free(tmp);
}


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
