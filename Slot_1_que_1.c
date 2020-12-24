#include<stdio.h>
#include<stdlib.h>

int main() {
  int n[100];
  for(int i = 0; n[i] != -1; i++) {
    scanf("%d", &n[i]);
  }
  int count = 0;
  for(int i = 0; n[i] != -1; i++) {
    for(int j = 0; n[j] != -1; j++) {
      if(n[i] > n[j] && i < j) {
		count++;
      }
    }
  }
  printf("%d", count);
  return 0;
}