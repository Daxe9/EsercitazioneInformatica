#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void es2_1() {
    int input;

    printf("enter a number: ");
    scanf("%d", &input);

    int found = 0;
    for (int i = 1; i < input && !found; i++) {
        if (i*i >= input) {
            printf("%d", i);
            found = 1;
        }
    }

}

// Scrivere un programma che richiede all’utente un intero positivo e ne stampa a schermo tutti i divisori.
void es2_3() {
    int input;

    printf("Enter a number: ");
    scanf("%d", &input);
    
    for(int i = 2; i <= (input / 2); ++i) {
        if (input % i == 0) {
            printf("%d\n", i);
        }
    }
}

void es2_4() {
    int input;

    printf("enter a number: ");
    scanf("%d", &input);

    int isPrime = 1;    

    for(int i = 2; i < input; ++i) {
        if (input % i == 0) {
            isPrime = 0;
        }
    }

    if (isPrime) {
        printf("E' un numero primo\n");
    } else{
        printf("Non e' un numero primo\n");
    }

}


void es2_5() {
    int input;
    int primeNumberCounter = 0;
    int startNumber = 2;
    int isPrime = 0;

    printf("Enter a number: ");
    scanf("%d", &input);

    while (primeNumberCounter < input) {
        isPrime = 1;
        for (int i = 2; i < startNumber; ++i) {
            if (startNumber % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d\n", startNumber);
            primeNumberCounter++;
        }
        startNumber++;
    } 
}

void es2_6() {
    int randomNumber = rand() % 11;
    int input = 0;
    int min = 0, max = 10;
    int attempts = 0;

    do {
        printf("Enter a number between %d and %d: ", min, max);
        scanf("%d", &input);
        if (input > randomNumber) {
            printf("Input number is bigger!\n");
            max = input - 1;
        } else if (input < randomNumber) {
            min = input + 1; 
            printf("Input number is smaller!\n");
        } 
        if (max == min) {
            printf("C'mon brother...\n");
        }
        attempts++;
    } while(input != randomNumber);

    printf("You've guessed the number in %d attempt/s", attempts);
    
}

void es2_7() {
    int input1, input2;
    int sum1 = 0, sum2 = 0;
    printf("Enter the first number: ");
    scanf("%d", &input1);
    fflush(stdin);
    printf("Enter the second number: ");
    scanf("%d", &input2);

    for (int i = 1; i <= input1 / 2; ++i) {
        if (input1 % i == 0) {
            sum1 += i;
        }
    }

    for (int i = 1; i <= input2 / 2; ++i) {
        if (input2 % i == 0) {
            sum2 += i;
        }
    }

    if (sum1 == input2 && sum2 == input1) {
        printf("1");
    } else {
        printf("0");
    }
}

void es2_8() {
    double real;
    int pos;
    double result = 0.0;
    printf("Enter a real number in radiant: ");
    scanf("%lf", &real);
    printf("Enter a positive integer: ");
    scanf("%d", &pos);

    printf("\ti\tSign\t\t\tDenom\t\tRealPart\tRound\t\tResult\n\n");

    for (int i = 0; i <= pos; ++i) {
        // segno
        int sign = i % 2 ? -1 : 1;

        // denominatore
        unsigned long long denom = 1;
        for (int j = 1; j <= 2 * i + 1; j++) {
            denom *= j;
        }

        // x^{2i}
        double temp = real;
        for (int j = 1; j < (2*i) + 1; j++) {
            temp *= real; 
        }

        // parte reale
        double realPart =  temp;
        // sommatoria
        result += sign * realPart / denom;
        printf("%8d\t%8d\t\t%8ld\t%8f\t%8f\t%8f\n", i, sign, denom, realPart, sign * realPart / denom, result);

    }

    printf("%lf", result);

}

int main() {
    srand(time(NULL));
    es2_8();
    return 0;
}