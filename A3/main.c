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


  FILE *file;
  int num = 0;
  int sum = 0;
  /* part1\
  char word[200];
  printf("Enter a word: ");
  scanf("%s", word);
  getWordStats(word, file, &sum, &num);
  fclose(file);
  printf("%s appeared %d times\n", word, num);
  double avg = (double)sum/(double)num;
  printf("The average score for reviews containing %s is %lf\n",word, avg);
  */
  printf("Enter a review\n");
  char review[1000];
  fgets(review, 1000, stdin);
  review[strlen(review)-1] = '\0';

  const char s[2] = " ";
   char *token;

   token = strtok(review, s);

   while( token != NULL ) {
     file = fopen("reviews.txt", "r");

      getWordStats(token, file, &sum, &num);
      int numTotal = 0;
      double avgTotal = 0;
      double avg = 0;
      if(sum > 0){
        avgTotal += (double)sum/(double)num;
        numTotal++;
        if(numTotal > 0){
         avg = avgTotal/numTotal;
      }

      }

      printf("%lf\n", avg);
      token = strtok(NULL, s);
      fclose(file);
   }

}
