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
  printf("Enter the phrase: ");
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

void es4_3() {
  char string[1000];
  int key;
  printf("Caesar says what do you say(max 160): ");
  gets(string);
  int size = strlen(string);

  printf("Caesar says what is the key: ");
  scanf("%d", &key);
  for (int i = 0; i < size; ++i) {
    string[i] = string[i] + key;
  }
  printf("%s", string);

  printf("\nEnter a crypted message: ");
  scanf("%s", string);
  printf("Decrypting...\n");
  for (int i = 0; i < size; ++i) {
    string[i] = string[i] - key;
  }
  printf("%s", string);
}

int _isVowel(char ch) { return (strchr("aeiouAEIOU", ch) != NULL); }

void es4_4() {
  char string[100];
  printf("Enter a word: ");
  gets(string);

  int i = 0;
  int len = strlen(string);
  int originalLen = strlen(string);
  int index = 0;

  while (string[i] != '\0') {
    if (_isVowel(string[i])) {
      for (int j = len; j > i; j--) {
        string[j + 2] = string[j];
      }
      string[i + 1] = 'f';
      string[i + 2] = string[i];
      i += 3;
      len += 2;

    } else {
      i++;
    }
  }
  puts(string);
}

// sarebbe meglio usare un hashmap ehh
void es4_5() {
  char string[256];
  printf("Inserisci una frase: ");
  gets(string);
  // initialize the array with 0 values
  int occurrences[52] = {0};

  for (size_t i = 0; i < strlen(string); i++) {
    int c = string[i];
    if (c >= 97 && c <= 122) {
      occurrences[string[i] - 97]++;
    }
    if (c >= 65 && c <= 90) {
      occurrences[string[i] - 39]++;
    }
  }

  for (int i = 0; i < 26; i++) {
    printf("%c | ", i + 97);
    for (int j = 0; j < occurrences[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
  for (int i = 26; i < 52; i++) {
    printf("%c | ", i + 39);
    for (int j = 0; j < occurrences[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void es4_6() {
  int letters[150] = {0};
  char word1[100], word2[100];
  printf("Enter the first word: ");
  gets(word1);
  printf("Enter the second word: ");
  gets(word2);

  for (int i = 0; i < strlen(word1); ++i) {
    letters[word1[i]]++;
  }
  for (int i = 0; i < strlen(word2); ++i) {
    letters[word2[i]]--;
  }
  int isAllZeros = 1;
  for (int i = 0; i < sizeof(letters) / sizeof(letters[0]) && isAllZeros; i++) {
    if (letters[i] != 0) {
      isAllZeros = 0;
    }
  }

  if (isAllZeros) {
    printf("Sono anagrammi!\n");
  } else {
    printf("Non sono anagrammi!\n");
  }
}

void es4_7() {
  int dim = 0;
  printf("Lunghezza dellal Matrix quadrata: ");
  scanf("%d", &dim);
  int matrix[dim][dim];
  int input;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      printf("Valore in %d, %d:", i, j);
      scanf("%d", &input);
      matrix[i][j] = input;
    }
  }

  // diagonale
  int isDiagonal = 1;
  for (int i = 0; i < dim && isDiagonal; i++) {
    if (matrix[i][i] == 0) {
      isDiagonal = 0;
    }
  }
  printf("La matrice ");
  if (!isDiagonal) {
    printf("non ");
  }
  printf("e' diagonale\n");

  int isSymmetric = 1;
  // simmetrica alla diagonale
  for (int i = 0; i < dim && isSymmetric; i++) {
    for (int j = i + 1; j < dim; j++) {
      if (matrix[i][j] != matrix[j][i]) {
        isSymmetric = 0;
      }
    }
  }

  printf("La matrice ");
  if (!isSymmetric) {
    printf("non ");
  }
  printf("e' simmetrica");
}

void es4_8() {
  int dim = 5;
  int matrix[dim][dim];
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      matrix[i][j] = i * dim + j + 1;
    }
  }

  // spirale
  // p1 puntatore riga, p2 puntatore colonna
  // p1p puntatore riga precedente, p2p puntatore colonna precedente
  int p1 = 0, p1p, p2 = dim - 1, p2p;
  while (p1 <= dim / 2 && p2 >= dim / 2) {
    for (int i = p1; i <= p2; i++) {
      printf("%d ", matrix[p1][i]);
    }

    for (int i = p1 + 1; i <= p2; i++) {
      printf("%d ", matrix[i][p2]);
    }

    for (int i = p2 - 1; i >= p1; i--) {
      printf("%d ", matrix[p2][i]);
    }

    for (int i = p2 - 1; i > p1; i--) {
      printf("%d ", matrix[i][p1]);
    }

    p1++;
    p2--;
  }
}

int main() {
  es4_8();
  return 0;
}