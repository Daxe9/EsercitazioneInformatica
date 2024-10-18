#include <stdio.h>
#include <string.h>

// Scrivere un programma che chiede all’utente cinque numeri interi e che li
// stampa in ordine inverso.
void es1() {
  int max = 5;
  int input;
  int array[max];

  for (int i = 0; i < max; ++i) {
    printf("Inserisci il numero n.%d: ", i + 1);
    scanf("%d", &input);
    array[i] = input;
  }

  printf("Ordine Inverso: \n");
  for (int i = max - 1; i >= 0; i--) {
    printf("%d ", array[i]);
  }
}

void es2() {
  int max = 10;
  int input;
  int array[max];
  // maximum pointer, minimum pointer
  int mp = 0, mip = 0;
  float average = 0.0;

  for (int i = 0; i < max; ++i) {
    printf("N.%d: ", i + 1);
    scanf("%d", &input);
    array[i] = input;
    if (input > array[mp]) {
      mp = i;
    }
    if (input < array[mip]) {
      mip = i;
    }
    average += input;
  }

  printf("Maximum: %d\n", array[mp]);
  printf("Minimum: %d\n", array[mip]);
  printf("Average: %f\n", average / max);
}

void es3() {
  int input = 0;
  do {
    printf("Quanti numeri vuoi inserire(almeno 2): ");
    scanf("%d", &input);
    if (input < 2) {
      printf("Invalido!");
    }
  } while (input < 2);

  int max = input;
  int array[max];
  int sum = 0;

  for (int i = 0; i < max; ++i) {
    printf("Inserisci il numero n.%d(compreso tra 0 e 10): ", i + 1);
    scanf("%d", &input);
    if (input <= 10 && input >= 0) {
      if (input < sum) {
        printf(
            "Il numero inserito e' inferiore alla somma di tutti i numeri "
            "precedenti.\n");
      }
      array[i] = input;
      sum += input;
    } else {
      i--;
    }
  }

  for (int i = 0; i < max; i++) {
    if (array[i] & 1 && !(i & 0)) {
      printf("%d ", array[i]);
    }
  }
}

void es4() {
  int max = 10;
  int input;
  int array[max];

  for (int i = 0; i < max; ++i) {
    printf("Inserisci il numero n.%d: ", i + 1);
    scanf("%d", &input);
    array[i] = input;
  }

  for (int i = 0; i < max; i++) {
    int index = i;
    for (int j = i + 1; j < max; j++) {
      if (array[j] < array[index]) {
        index = j;
      }
    }
    // swap
    if (index != i) {
      int temp = array[index];
      array[index] = array[i];
      array[i] = temp;
    }
  }

  for (int i = 0; i < max; i++) {
    printf("%d ", array[i]);
  }
}

void esexarray() {
  int input = 0;
  do {
    printf("Quanti numeri vuoi inserire: ");
    scanf("%d", &input);
    if (input < 0) {
      printf("Invalido!");
    }
  } while (input < 0);
  int max = input;
  int array[max];

  for (int i = 0; i < max; ++i) {
    printf("Inserisci il numero n.%d: ", i + 1);
    scanf("%d", &input);

    if (input < array[i - 1]) {
      printf("Numero inferiore rispetto al precedente!\n");
      i--;
    } else {
      array[i] = input;
    }
  }

  float diff[max - 1];
  for (int i = 0; i < max - 1; i++) {
    float result = (array[i + 1] - array[i]) / (float)array[i] * 100;
    diff[i] = result;
  }

  printf("Inserisci una soglia(intera): ");
  scanf("%d", &input);

  for (int i = 0; i < max - 1; i++) {
    if (diff[i] > input) {
      printf("%d-%d\n", array[i], array[i + 1]);
    }
  }
}

void es5() {
  char string[100] = "stampami";
  for (int i = 0; string[i] != '\0'; ++i) {
    printf("%c\n", string[i]);
  }
}

void es6() {
  char string[100];
  printf("Inserisci una string: ");
  scanf("%s", string);
  printf("Inserisci un'altra: ");
  scanf("%s", &string[5]);

  printf("%s", string);
}

void es7() {
  // invert a string
  char string[100];
  printf("Enter a string of characters(max 100): ");
  gets(string);
  int size = strlen(string);

  for (int i = 0; i < size / 2; i++) {
    // swap
    char temp = string[i];
    string[i] = string[size - 1 - i];
    string[size - 1 - i] = temp;
  }

  printf("\n%s\n", string);
}

void es8() {
  char string[1000];
  int key;
  printf("Caesar says what do you say: ");
  gets(string);
  int size = strlen(string);

  printf("Caesar says what is the key: ");
  scanf("%d", &key);
  for (int i = 0; i < size; ++i) {
    string[i] = string[i] + key;
  }

  printf("%s", string);
}

int main() {
  es8();
  return 0;
}