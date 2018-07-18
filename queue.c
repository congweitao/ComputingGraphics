#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Q 8
#define INIT -1000

int a[Q];


// initializing chessboard
void init() {
    int *p;
    for (p = a;p < a + Q;p++) {
        *p = INIT;
    }
}

// a[i] means quene's position on row i 
// to check wether quene i's position a[i] is valid.
int valid(int row, int col) {
    int i;
    for (i = 0; i < Q; i++) {
        if (a[i] == col || abs(a[i] - col) == abs(i - row)) {
             return 0;
        }
    }
    return 1;
}

void display(){
    int i, j;
    for (i = 0; i < Q; i++) {
        for (j = 0; j < Q; j++) {
            if (a[i] != j)
                printf("%c ",".");  
            else
                printf("%c ","#"); // Quene
	}
	printf("\n");
    }
    for (i = 0; i < Q; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("-------------------\n");
}

void queen() {
    int n = 0;
    int i = 0, j = 0;
    while (i < Q) {
        while (j < Q) {
            if (valid(i,j)) {
                a[i] = j;
                j = 0;
                break;
            }
            ++j;
        }
        if (a[i] == INIT) {
            if (i == 0) 
                break;
            else {
                --i;
                j = a[i] + 1;
                a[i] = INIT;
                continue;
            }
        }
       if (i == Q - 1) {
           printf("Answer %d : \n",++n);
           display();
           j = a[i] + 1;
           a[i] = INIT;
           continue;
       }
       ++i;
    }
}

int main() {
    init();
    queen();
    return 0;
}
