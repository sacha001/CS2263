#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getWordStats(char *word, FILE *f, int *sum, int *num){
  char buff[1000];
  while(fgets(buff, 1000, (FILE*)f)){
    int rating = buff[0] - '0';
    int len = strlen(buff);
    for(int i = 0; i < len; i++){
      char word2[200];
      int j = 0;
      while(buff[i+j] != ' ' && buff[i+j] != '\0'){
        word2[j] = tolower(buff[i+j]);
        j++;
      }
      word2[j] = '\0';
      if(strcmp(word, word2) == 0){
        (*sum) += rating;
        (*num)++;
        break;
      }
      i += j;
    }
  }
}

int main(){
  char *word = "organic";
  FILE *file;
  file = fopen("reviews.txt", "r");
  int num = 0;
  int sum = 0;
  getWordStats(word, file, &sum, &num);
  fclose(file);
  printf("%d %d\n", num, sum);
}
