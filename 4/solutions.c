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

void es4_2() {
  char string[100];
  gets(string);
  char *o = string, *s = string;

  // inline removing spaces
  while (*s) {
    if (*s != ' ' && (*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 120)) {
      *o++ = *s;
    }
    s++;
  }
  *o = '\0';

  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    if (string[i] >= 65 && string[i] <= 90) {
      string[i] += 32;
    }
  }

  int itIs = 1;
  for (int i = 0; i < len; i++) {
    if (string[i] != string[len - 1 - i]) {
      itIs = 0;
    }
  }

  printf("\nLa parola %s ", string);
  if (!itIs) {
    printf("non ");
  }
  printf("e' palindroma\n");
}

int main() {
  es4_2();
  return 0;
}