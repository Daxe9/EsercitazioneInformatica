#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Scrivere un programma che riceve in ingresso un prezzo (numero razionale) ed uno sconto (intero tra 0 e 100) da applicare, e restituisce il prezzo scontato e il risparmio ottenuto.
void es1_3() {
    float price;
    int discount;
    float salePrice, savedMoney;

    printf("Enter the price: ");
    scanf("%f", &price);
    printf("Enter the discount(from 0 to 100): ");
    scanf("%d", &discount);

    salePrice = price * (100 - discount) / 100.0;
    savedMoney = price - salePrice;

    printf("Sale price is %.2f and you saved %.2f", salePrice, savedMoney);
}

// Scrivere un programma che prende in ingresso un tempo espresso in ore, minuti e secondi e ne restituisce l’equivalente in secondi.
void es1_4() {
    int hour, min, sec;
    int total;

    printf("Enter hours: ");
    scanf("%d", &hour);
    printf("Enter minutes: ");
    scanf("%d", &min);
    printf("Enter seconds: ");
    scanf("%d", &sec);

    total = sec + min * 60 + hour * 3600;

    printf("Your time in seconds is: %d", total);
}


// Scrivere un programma che prende in ingresso un tempo espresso in secondi e ne restituisce l’equivalente nel formato ore, minuti, secondi
void es1_5() {
    int sec, min;
    int hour;
    int input;

    printf("Enter time in seconds: ");
    scanf("%d", &input);

    min = input / 60; 
    sec = input - min * 60;
    hour = min / 60;
    min -= hour * 60; 

    printf("Hour: %d\nMinutes: %d\nSeconds: %d", hour, min, sec);
}

// Scrivere un programma che prende in ingresso un prezzo in euro e restituisce il numero minimo di banconote utilizzando solo pezzi da 50, 20 e 5 euro. Indicare anche la moneta rimanente
void es1_6() {
    // si assume che il valore di input e' un numero intero
    int input;
    int mIn50, mIn20, mIn5;

    printf("Enter money: ");
    scanf("%d", &input);

    mIn50 = input / 50;
    input -= mIn50 * 50;
    mIn20 = input / 20;
    input -= mIn20 * 20;
    mIn5 = input / 5;
    input -= mIn5 * 5;

    printf(
        "50: %d\n" 
        "20: %d\n" 
        "5: %d\n"
        "Remaning: %d",
        mIn50, mIn20, mIn5, input
    );
}

// Scrivere un programma che calcoli la distanza tra due punti, a e b, interi sulla retta y = 0
void es1_7() {
    int a, b;
    int diff;

    printf("Enter point a: ");
    scanf("%d", &a);
    printf("Enter point b: ");
    scanf("%d", &b);
    
    diff = a - b;

    if (diff < 0) {
        diff = -diff;
    }

    printf("The distance between a and b is %d", diff);
}

// Scrivere un programma che calcoli la distanza tra due punti, a e b, interi su un retta. Potete utilizzare la funzione abs() della libreria stdlib.h, che calcola il valore assoluto di un numero intero.
void es1_8() {
    int a, b;

    printf("Enter point a: ");
    scanf("%d", &a);
    printf("Enter point b: ");
    scanf("%d", &b);
    printf("The distance between a and b is %d", abs(a - b));
}

/*
    * Scrivere un programma che legga da input un numero intero e stampi su output:
    * a stringa basso se il numero è compreso tra 0 e 3;
    * la stringa MediO se il numero è compreso tra 4 e 8;
    * la stringa ALTO! se il numero è compreso tra 9 e 10; 
    * la stringa Numero non valido altrimenti
*/
void es1_9() {
    int input;

    printf("Input number: ");
    scanf("%d", &input);

    if (0 <= input && input <= 3) {
        printf("Basso!");
    } else if (4 <= input && input <= 8) {
        printf("Medio!");
    } else if (9 <= input && input <= 10) {
        printf("Alto!");
    } else {
        printf("Numero non valido!");
    }

}

void es1_10() {
    int a, b, c;
    int numbers[3];
    
    printf("Enter number a: ");
    scanf("%d", &a);
    printf("Enter number b: ");
    scanf("%d", &b);
    printf("Enter number c: ");
    scanf("%d", &c);

    numbers[0] = a;
    numbers[1] = b;
    numbers[2] = c;

    // controllo se ogni numero e' minore rispetto alla somma di altri due
    if (
        a >= b + c ||
        b >= a + c ||
        c >= a + b
    ) {
        printf("It is not a triangle!");
        return;
    }

    if (a == b && a == c) {
        printf("Equilateral!");
        return;
    }

    if (a == b || b == c || a == c) {
        printf("Isosceles!");
        return;
    }

    // OVERKILL BUT ALRIGHT
    // ordinare l'array --> selection sort
    for (int i = 0; i < 3; ++i) {
        int roundMaxNum = numbers[i];

        int _i = i;
        for (int j = i + 1; j < 3; ++j) {
            if (numbers[j] > numbers[_i]) {
                _i = j;
            }
        }
        if (_i != i) {
            int temp = numbers[i];
            numbers[i] = numbers[_i];
            numbers[_i] = temp;
        }

    }
    
    if (numbers[0]*numbers[0] == numbers[1]*numbers[1] + numbers[2]*numbers[2]) {
        printf("Right Triangle!");
        return;
    }

    printf("Scalene!");
}

/*
Scrivere un programma che legga da tastiera un numero intero che rappresenta un anno
(e.g., 2012) e che determini poi se tale anno è bisestile o meno. Si può assumere che il
numero intero letto da tastiera sia sempre valido (e.g., di 4 cifre, positivo).
Un anno è bisestile se è multiplo di 4 ma non di 100, oppure se è multiplo di 400.
*/
void es1_11() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    int isLeap = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;

    if (isLeap) {
        printf("It is a leap year!\n");
    } else {
        printf("It is not a leap year!\n");
    }

}

int main() {
    es1_10();
    return 0;
}
