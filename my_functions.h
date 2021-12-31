//
// Created by hp on 24/11/2021.
//

#ifndef MY_FUNCTIONS_C_MY_FUNCTIONS_H
#define MY_FUNCTIONS_C_MY_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define NL() printf("\n")
#define CLOCKS_PER_MILL CLOCKS_PER_SEC/1000


int lenght(char *str);
void lower(char str[]);
void upper(char str[]);
void clear_string(char *str);
void binary_code(int n, char str[]);
_Bool all_equals(int n[], int size);
void delay(clock_t mill);
char* i_to_str(long int n, char buff[], int b);
long int str_to_i(char* str, int b, int size);

#endif //MY_FUNCTIONS_C_MY_FUNCTIONS_H
