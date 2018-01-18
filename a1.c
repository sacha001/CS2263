#include <stdio.h>

void markVertex(int uniqueVertices[], int edge, int len){
  for(int i = 0; i < len; i++){
    if(uniqueVertices[i] == edge){
      uniqueVertices[i] = -1;
    }
  }
}

int isHamiltonian(int uniqueVertices[], int len){
  int result = 1;
  for(int i = 0; i < len; i++){
    if(uniqueVertices[i] != -1){
      result = 0;
    }
  }
  return result;
}

int main(){
  int lenA;
  int lenB;
  int num;
  int edge;
  int lastEdge;
  int isPath = 1;

  scanf("%d", &lenA);
  int a[lenA + 1];

  scanf("%d", &lenB);
  int b[lenB];

  for(int i = 0; i <= lenA; i++){
    scanf("%d", &num);
    a[i] = num;
  }

  int uniqueVertices[lenA];
  for(int i = 0; i < lenA; i++){
    uniqueVertices[i] = i;
  }

  for(int i = 0; i < lenB; i++){
    scanf("%d", &num);
    b[i] = num;
  }

  scanf("%d", &lastEdge);
  markVertex(uniqueVertices, lastEdge, lenA);

  printf("%d ", lastEdge);
  while(scanf("%d", &edge) == 1){
    int numPaths;
    int tmp = 0;
    numPaths = a[lastEdge + 1] - a[lastEdge];
    for(int j = 0; j < numPaths; j++){
      if(b[a[lastEdge] + j] != lenB){
        if(b[a[lastEdge] + j] == edge){

          tmp = 1;
          markVertex(uniqueVertices, edge, lenA);
        }
      }
    }
    if(tmp == 0){
      isPath = 0;
    }
    lastEdge = edge;
    printf("%d ", lastEdge);

  }
  printf("is ");
  if(isPath == 0){
    printf("NOT ");
  }
  printf("a path\nand is ");
  if(isHamiltonian(uniqueVertices, lenA) == 0){
    printf("NOT ");
  }
  printf("a Hamiltonian path");

}
