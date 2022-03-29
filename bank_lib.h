#ifndef BANK_LIB_h
#define BANK_LIB_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank
{

    char Name[30];
    int Age;
    int Label;

} bnk[50];

void add_customer(struct bank *banking, int customer_number);
void process_customer(struct bank *banking, int customer_number, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2]);
void order_customer(struct bank *banking, int customer_number, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2]);
void print_current_sequence(struct bank *banking, int customer_number, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2]);
void fill_array(int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2]);
void order_struct(struct bank *banking, int customer_number, int menuInput_num, int row, int column, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2]);

#endif