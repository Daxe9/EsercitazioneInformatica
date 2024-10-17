#include <stdio.h>
#include <math.h>

void es3_1() {
    int array1[10], array2[10];
    int result[20];


    for (int i = 0; i < 10; i++) {
        array1[i]  = i;
        array2[i]  = 2 * i;
    }

    int p1 = 0, p2 = 0;
    for(int i = 0; i < 20; ++i) {
        // pari
        if (i % 2 == 0) {
            result[i] = array1[p1];
            p1++;
        } else {
            result[i] = array2[p2];
            p2++;
        }
    }

    for (int i = 0; i < 20; ++i) {
        printf("%d \n", result[i]);
    }

}

void es3_2() {
    int max = 10;
    int input;
    int evenVec[10], ep = 0; 
    int oddVec[10], op = 0; 

    
    do {
        printf("Enter positive integer: ");
        scanf("%d", &input);
        if (input % 2 == 0) {
            evenVec[ep] = input;
            ep++;
        } else {
            oddVec[op] = input;
            op++;
        }

        max--;
    } while (input > 0 && max >= 0);

    printf("Even vector: \n");
    for(int i = 0; i < ep; ++i) {
        printf("%d ", evenVec[i]); 
    }
    
    printf("\nOdd vector: \n");
    for(int i = 0; i < op; ++i) {
        printf("%d ", oddVec[i]); 
    }
}


void es3_3() {
    int max = 20;
    int input;
    int voti[max];
    int vp = 0;
    
    do {
        printf("Inserisci un voto intero: ");
        scanf("%d", &input);
        if (input > 30 || input < 18) {
            printf("Il voto deve essere compreso tra 18 e 30!\n");
            max++;
        } else {
            voti[vp] = input;
            vp++;
        }


        max--;
    } while (input > 0 && max >= 0);


    // sort
    for (int i = 0; i < vp; ++i) {
        int _i = i;
        for (int j = i + 1; j < vp; ++j) {
            if (voti[j] > voti[_i]) {
                _i = j;
            }
        }
        if (_i != i) {
            int temp = voti[i];
            voti[i] = voti[_i];
            voti[_i] = temp;
        }
    }

    float average1 = 0, average2=0; 
    for (int i = 0; i < vp; i++) {
        average1 += voti[i];
    }    
    average1 /= vp;

    for (int i = 1; i < vp - 1; i++) {
        average2 += voti[i];
    }    
    average2 /= vp > 2 ? vp - 2 : 1;

    // varianza
    float num = 0;

    for (int i = 0; i < vp; ++i) {
        int diff = voti[i] - average1;
        num += diff * diff;
    }

    float var = num / (vp - 1);
    float standardDev = sqrt(var);

    printf("STATISTICHE: \n\n");
    printf("Numero di esami sostenuti: %d \n", vp);
    printf("Media: %f \n", average1);
    printf("Media Troncata: %f \n", average2);
    printf("Varianza: %f\n", var);
    printf("Deviazione Standard: %f", standardDev);
}

void es3_4() {
    int max, input;
    printf("Quanti numeri vuoi inserire: ");
    scanf("%d", &max);
    int vec[max];
    int topValue = 0;
    for(int i = 0; i < max; i++) {
        printf("Inserisci un numero intero tra 1 e 100: ");
        scanf("%d", &input);
        if (input > 100 || input < 1) {
            printf("Il voto deve essere compreso tra 18 e 30!\n");
            i--;
        } else {
            vec[i] = input;
            if (input  > topValue) {
                topValue = input;
            }
        }
    }

    int divisors[100];
    int dp = 0;
    for (int i = 2; i <= topValue/2; i++) {
        int counter = 0;
        for (int j = 0; j < max; ++j) {
            if (vec[j] % i == 0 && vec[j] != i) {
                counter++;
            }
        }
        divisors[i-2] = counter;
        dp++;
    }

    for (int i = 0; i < dp; ++i) {
        printf("%3d\t|", i+2);
        for(int j = 0; j< divisors[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
    
}

void es3_5() {
    int max;
    do {
        printf("Quanti numeri vuoi inserire(massimo 10): ");
        scanf("%d", &max);
        if (max > 10 || max < 1) {
            printf("Input invalido!\n");
        }
    } while (max > 10 || max < 1);
    int uselessmax = max;
    float numbers[max], input;
    int np = 0;
    // minimum pointer, maximum pointer
    int mip = 0, mp = 0;
    do {
        printf("Inserisci un numero(intero o decimale): ");
        scanf("%f", &input);

        numbers[np] = input;
        if (input < numbers[mip]) {
            // index
            mip = np;
        }
        if (input > numbers[mp]) {
            mp = np;
        }

        np++;
        uselessmax--;
    } while (uselessmax > 0);
    

    for (int i = 0; i < max; i++) {
        if (mp == i) {
            printf("max");
        }
        if (mip == i) {
            printf("min");
        } else {
            printf("   ");
        }
        
        printf("\t|");
        printf("%.2f\n", numbers[i]);

    }
}

void es3_6() {
    int max, input;
    printf("Quanti numeri vuoi inserire: ");
    scanf("%d", &max);
    int vec[max], order[max];

    for (int i = 0; i < max; i++) {
        printf("Inserisci il valore n. %d: ", i+1);
        scanf("%d", &input);
        vec[i] = input;
    }

    for (int i = 0; i < max; i++) {
        printf("Qual e' il %do valore che vuoi stampare: ", i+1);
        scanf("%d", &input);

        order[input - 1] = vec[i];
    }

    for(int i = 0; i < max; ++i) {
        printf("%d\n", order[i]);
    }
}

void es3_7() {
    int max = 100;
    int input;
    int numbers[max];
    int umax = 0;
    
    for (umax = 0; umax < max && input != 0; umax++)
    {
        printf("Inserisci un numero intero: ");
        scanf("%d", &input);
        if (input != 0) {
            numbers[umax] = input;
        }
    }
    umax--;

    // sort
    for (int i = 0; i < umax; ++i) {
        int _i = i;
        for (int j = i + 1; j < umax; ++j) {
            if (numbers[j] < numbers[_i]) {
                _i = j;
            }
        }
        if (_i != i) {
            int temp = numbers[i];
            numbers[i] = numbers[_i];
            numbers[_i] = temp;
        }
    }

    int set[umax];
    set[0] = numbers[0];
    int p1 = 1, p2 = 1;
    while (p1 < umax) {
        
        if (numbers[p1] != numbers[p1 - 1]) {
            set[p2] = numbers[p1];
            p2++;
        }

        p1++;
    }

    for (int i = 0; i < p2; i++) {
        printf("%d ", set[i]);
    }
    
}

void es3_8() {
    int choice = 0;
    int arr1[5], arr2[5];
    int input;
    for (int i = 0; i < 5; i++) {
        printf("Inserisci un numero al primo array: "); 
        scanf("%d", &input);
        arr1[i] = input;
    }
    for (int i = 0; i < 5; i++) {
        printf("Inserisci un numero al secondo array: "); 
        scanf("%d", &input);
        arr2[i] = input;
    }

    printf(" [1]: unione\n [2]: intersezione\n [3]: differenza(set 1 diff set 2)\n scelta: ");
    scanf("%d", &choice);
    
    int result[10];
    int rp = 0;
    switch (choice)
    {
        case 1:
            // copia il primo array
            for (int i = 0; i < 5; i++) {
                result[i] = arr1[i];
            }
            rp = 5;

            // itera il secondo array, inserisce solo se non e' presente
            for (int i = 0; i < 5; i++) {
                int number = arr2[i];
                int skip = 0;
                for (int j = 0; j < rp && !skip; j++) {
                    if (result[j] == number) {
                        skip = 1;
                    }
                }
                
                if (!skip) {
                    result[rp] = number;
                    rp++;
                }
            }
            
            break;
        
        case 2:
            for (int i = 0; i < 5; i++) {
                int number = arr1[i];
                int found = 0;

                for (int j = 0; j < 5 && !found; j++) {
                    if (arr2[j] == number) {
                        found = 1;
                    }
                }

                if (found) {
                    result[rp] = number;
                    rp++;
                } 
            }
            
            break;

        case 3: {
            // copia il primo array
            for (int i = 0; i < 5; i++) {
                result[i] = arr1[i];
            }
            rp = 5;

            for (int i = 0; i < 5; i++) {
                int number = arr2[i];
                for (int j = 0; j < rp; j++) {
                    if (result[j] == number) {
                        result[j] = 0;
                    }
                }
                
            }
            
            int sup[rp];
            for (int i = 0; i < rp; i++) {
                sup[i] = result[i];
            }
            int index = 0;
            for (int i = 0; i < rp; i++) {
                if (sup[i] != 0) {
                    result[index] = sup[i];
                    index++;
                }
            }
            
            rp = index;
             
        
            break;
        }
        default:
            printf("Invalido\n");
            break;
    }

    printf("\nResult: \n");
    for (int i = 0; i < rp; i++) {
        printf("%d ", result[i]);
    }
    

}

int main() {

    es3_8();
    return 0;
}