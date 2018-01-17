#include <stdio.h>

int main(){
  int lenA;
  int lenB;
  int num;

  scanf("%d", &lenA);
  int a[lenA + 1];
  int a2[lenA + 1];

  scanf("%d", &lenB);
  int b[lenB];
  int b2[lenB];

  for(int i = 0; i <= lenA; i++){
    scanf("%d", &num);
    a[i] = num;
  }

  for(int i = 0; i < lenB; i++){
    scanf("%d", &num);
    b[i] = num;
  }

  a2[0] = 0;
  for(int i = 0; i < lenA; i++){
    int numPointers = 0;
    for(int j = 0; j < lenB; j++){
      if(b[j] == i){
        numPointers++;
      }
    }

    a2[i + 1] = a2[i] + numPointers;
    printf("%d ", a2[i]);
  }
}
