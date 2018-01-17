#include <stdio.h>

int main(){
  int lenA;
  int lenB;
  int num;
  int edge;
  int lastEdge;
  int isPath = 1;

  scanf("%d", &lenA);
  int a[lenA];

  scanf("%d", &lenB);
  int b[lenB];

  for(int i = 0; i <= lenA; i++){
    scanf("%d", &num);
    a[i] = num;
  }

  for(int i = 0; i < lenB; i++){
    scanf("%d", &num);
    b[i] = num;
  }

  scanf("%d", &lastEdge);
  int i = 0;

  while(scanf("%d", &edge) == 1){
    int numPaths;
    int tmp = 0;
    numPaths = a[i + 1] - a[i];
    for(int j = 0; j < numPaths; j++){
      if(b[a[lastEdge] + j] != lenB){
        if(b[a[lastEdge] + j] == edge){
          tmp = 1;
        }
      }
    }
    if(tmp == 0){
      isPath = 0;
    }
    lastEdge = edge;
    i++;
  }
  printf("%d", isPath);


}
