#include <stdio.h>

int main() {
    int b[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}; // two dimensional array
    int (*p)[4];   // 4-width step, this is a Pointer to Array
    char *q[4] = {"hello","world","ni","hao"};  // this is an Array of Pointer

    p = b;

    printf("*q1,*q3,%s,%s\n",q[0],q[3]);  // print elements of array
    printf("(*p)[6],b[1][2] is %d,%d\n",(*p)[6],b[1][2]);    // print value of pointer
}
