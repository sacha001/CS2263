#include <stdio.h>

int main(){
  int lenA;
  int lenB;
  int num;

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

  scanf("%d");
  for(int i = 0; i < 4; i++){
    int numPaths;
    int lastEdge = 0;
    int edge;
    scanf("%d", &edge);
    printf("%d", edge);

    numPaths = a[i + 1] - a[i];
    for(int j = 0; j < numPaths; j++){
      if(edge == a[])
    }
    a[lastEdge]
    //for(int j = 0; j < numPaths; j++){

  //  }
  }


}
