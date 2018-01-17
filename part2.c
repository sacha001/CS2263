#include <stdio.h>

void transposeOffsets(int b[], int a2[], int lenA, int lenB){
  for(int i = 0; i < lenA; i++){
    int numPointers = 0;
    for(int j = 0; j < lenB; j++){
      if(b[j] == i){
        numPointers++;
      }
    }

    a2[i + 1] = a2[i] + numPointers;
  }
}

void transposeEdges(int a[], int b[], int a2[], int b2[], int lenA){
  for(int i = 0; i < lenA; i++){
    int numPaths;
    numPaths = a[i + 1] - a[i];
      for(int j = 0; j < numPaths; j++){
        int offset = 0;
        while(b2[a2[b[a[i] + j]] + offset] != -1){
          offset++;
        }
        b2[a2[b[a[i] + j]] + offset] = i;
      }
  }
}

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
  transposeOffsets(b, a2, lenA, lenB);

  for(int i = 0; i < lenB; i++){
    b2[i] = -1;
  }

  transposeEdges(a, b, a2, b2, lenA);

  printf("%d %d\n", lenA, lenB);

  for(int i = 0; i <= lenA; i++){
    printf("%d ", a2[i]);
  }

  printf("\n");

  for(int i = 0; i < lenB; i++){
    printf("%d ", b2[i]);
  }
}
