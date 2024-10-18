#include <stdio.h>
#include <string.h>

void es4_1() {
  char s1[20], s2[20], s[40];
  printf("String 1: ");
  gets(s1);
  printf("String 2: ");
  gets(s2);

  int size1 = 0, size2 = 0;

  for (size1 = 0; s1[size1] != '\0'; ++size1)
    ;
  for (size2 = 0; s2[size2] != '\0'; ++size2)
    ;

  strcpy(s, s1);
  for (int i = 0; i < size2; ++i) {
    s[i + size1] = s2[i];
  }

  printf("%s", s);
}

int main() {
  es4_1();
  return 0;
}