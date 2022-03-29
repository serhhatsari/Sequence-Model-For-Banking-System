#include "bank_lib.h"

/**
 * It takes the customer number and the struct as parameters. It asks the user to enter the name, age
 * and label of the customer. It then assigns the values to the struct
 *
 * @param banking the array of structs
 * @param customer_number The customer number
 */
void add_customer(struct bank *banking, int customer_number)
{

    char name[30]; /* it will hold the name */
    int age;       /* it will hold the age */
    int label;     /* it will hold the label */

    printf("\n\t\tADD CUSTOMER \n");
    printf("Please enter the name of the customer: ");
    scanf("%s", name); /* taking the name */

    printf("Please enter the age of the customer: ");
    scanf("%d", &age); /* taking the age */

    while (age < 1 || age > 160)
    { /* i put 160 because longest human ever lived has lived 160 years who is Zaro Aga :)) */

        printf("\n There is no human with that age \n");
        printf("Please enter the age of the customer: ");
        scanf("%d", &age); /* taking the age */
    }

    printf("\nLABELS: \n");
    printf("0: EMPLOYEE\n");
    printf("1: RETIRED\n");
    printf("2: STUDENT\n");
    printf("3: UNEMPLOYED\n");
    printf("4: OTHER\n");
    printf("Please enter the label of the customer(0-4): ");
    scanf("%d", &label); /*taking the label */

    while (label < 0 || label > 4)
    { /* conditions */
        printf("\n Label can be 0,1,2,3,4 \n");
        printf("Please enter the label of the customer: ");
        scanf("%d", &label); /* taking the label */
    }

    strcpy(banking[customer_number].Name, name); /* assigning to struct */
    banking[customer_number].Age = age;          /* assigning to struct */
    banking[customer_number].Label = label;      /* assigning to struct */

    printf("\n");
}

/**
 * It will delete the first customer from the array if its label is zero, one, two, three or four
 *
 * @param banking the array of structs
 * @param customer_number The number of the customer that is being processed.
 * @param zero an array of 12 arrays of 5 integers.
 * @param one an array of structs of type customer_type
 * @param two the array that holds the two-digit numbers
 * @param three an array of 25 integers, each of which is either -5 or a customer number.
 * @param four an array of 25 ints, each of which is either -5 or a customer number.
 *
 * @return Nothing.
 */
void process_customer(struct bank *banking, int customer_number, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2])
{

    int i, k, number;
    number = banking[0].Label;

    for (i = 0; i < 49; i++)
    { /* it will process the first customer, i mean it will delete the first struct. */
        banking[i] = banking[i + 1];
    }

    if (number == 0)
    { /* it will delete the first customers label in the zero array  if its zero  */
        for (k = 0; k < 12; k++)
        {

            if (zero[k][0] != -5)
            {

                for (i = 0; i < 4; i++)
                {
                    zero[k][i] = zero[k][i + 1];
                }
                zero[k][4] = -5;
                return;
            }
        }
    }
    else if (number == 1)
    { /* it will delete the first customers label in the one array  if its one  */
        for (k = 0; k < 17; k++)
        {

            if (one[k][0] != -5)
            {

                for (i = 0; i < 2; i++)
                {
                    one[k][i] = one[k][i + 1];
                }
                one[k][2] = -5;
                return;
            }
        }
    }
    else if (number == 2)
    { /* it will delete the first customers label in the two array  if its two  */
        for (k = 0; k < 17; k++)
        {

            if (two[k][0] != -5)
            {
                for (i = 0; i < 2; i++)
                {
                    two[k][i] = two[k][i + 1];
                }
                two[k][2] = -5;
                return;
            }
        }
    }
    else if (number == 3)
    { /* it will delete the first customers label in the three array  if its three  */
        for (k = 0; k < 25; k++)
        {

            if (three[k][0] != -5)
            {
                three[k][0] = three[k][1];
                three[k][1] = -5;
                return;
            }
        }
    }
    else if (number == 4)
    { /* it will delete the first customers label in the four array  if its four  */
        for (k = 0; k < 25; k++)
        {
            if (four[k][0] != -5)
            {
                four[k][0] = four[k][1];
                four[k][1] = -5;
                return;
            }
        }
    }
}

/**
 * It prints the current sequence of numbers in the array
 *
 * @param banking the bank structure
 * @param customer_number The customer number
 * @param zero the array that holds the numbers that are in the 0th position of the sequence
 * @param one the array that holds the first number of each sequence
 * @param two the array that holds the numbers that are in the second row of the bank
 * @param three the array that holds the numbers that are in the third row of the bank
 * @param four the array that holds the numbers that are in the fourth column of the bank
 */
void print_current_sequence(struct bank *banking, int customer_number, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2])
{

    int i = 0, j;
    for (i = 0; i < 25; i++)
    { /* it will print the numbers in array */

        if (i < 12)
        {
            for (j = 0; j < 5; j++)
            { /* it will print the numbers in zero array */
                if (zero[i][j] != -5)
                {
                    printf("%d ", zero[i][j]);
                }
            }
        }
        if (i < 17)
        {

            for (j = 0; j < 3; j++)
            { /* it will print the numbers in one array */
                if (one[i][j] != -5)
                {
                    printf("%d ", one[i][j]);
                }
            }
        }
        if (i < 17)
        {
            for (j = 0; j < 3; j++)
            { /* it will print the numbers in two array */
                if (two[i][j] != -5)
                {
                    printf("%d ", two[i][j]);
                }
            }
        }

        for (j = 0; j < 2; j++)
        { /* it will print the numbers in three array */
            if (three[i][j] != -5)
            {
                printf("%d ", three[i][j]);
            }
        }
        for (j = 0; j < 2; j++)
        { /* it will print the numbers in four array */
            if (four[i][j] != -5)
            {
                printf("%d ", four[i][j]);
            }
        }
    }
    printf("\n \n");
}

/**
 * Fill an array with -5's
 *
 * @param zero an array of 12 arrays of 5 integers
 * @param one the array that will hold the first set of numbers
 * @param two the array that will hold the values of the second row of the matrix
 * @param three the array that will hold the values of the 3-digit numbers
 * @param four the array that will hold the final result
 */
void fill_array(int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2])
{

    int i, j;

    for (i = 0; i < 12; i++)
    { /* fill the array with -5's */
        for (j = 0; j < 5; j++)
        {
            zero[i][j] = -5;
        }
    }
    for (i = 0; i < 17; i++)
    { /* fill the array with -5's */
        for (j = 0; j < 3; j++)
        {
            one[i][j] = -5;
        }
    }
    for (i = 0; i < 17; i++)
    { /* fill the array with -5's */
        for (j = 0; j < 3; j++)
        {
            two[i][j] = -5;
        }
    }
    for (i = 0; i < 25; i++)
    { /* fill the array with -5's */
        for (j = 0; j < 2; j++)
        {
            three[i][j] = -5;
        }
    }
    for (i = 0; i < 25; i++)
    { /* fill the array with -5's */
        for (j = 0; j < 5; j++)
        {
            four[i][j] = -5;
        }
    }
}

/**
 * This function is used to order the customer in the struct
 *
 * @param banking the bank struct
 * @param customer_number The customer number of the customer that is being ordered.
 * @param zero the array that holds the customers with label 0
 * @param one the array of customers with label 1
 * @param two the array that holds the customers with label 2
 * @param three the array of customers with label 3
 * @param four the array that holds the customers with label 4
 *
 * @return Nothing.
 */
void order_customer(struct bank *banking, int customer_number, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2])
{

    int i, j;
    if (banking[customer_number].Label == 0)
    { /* if the label of new coming customer is zero it will go here */
        for (i = 0; i < 12; i++)
        { /*it will check the customer with label zero */
            for (j = 0; j < 5; j++)
            {
                if (zero[i][j] == -5)
                {
                    zero[i][j] = 0;
                    order_struct(banking, customer_number, 0, i, j, zero, one, two, three, four); /* it will order the struct then return */
                    return;
                }
            }
        }
    }
    else if (banking[customer_number].Label == 1)
    { /* if the label of new coming customer is one it will go here */
        for (i = 0; i < 17; i++)
        { /*it will check the customer with label one */

            for (j = 0; j < 3; j++)
            {

                if (one[i][j] == -5)
                {
                    one[i][j] = 1;
                    order_struct(banking, customer_number, 1, i, j, zero, one, two, three, four); /* it will order the struct then return */
                    return;
                }
            }
        }
    }
    else if (banking[customer_number].Label == 2)
    { /* if the label of new coming customer is two it will go here */
        for (i = 0; i < 17; i++)
        { /*it will check the customer with label two */

            for (j = 0; j < 3; j++)
            {

                if (two[i][j] == -5)
                {
                    two[i][j] = 2;
                    order_struct(banking, customer_number, 2, i, j, zero, one, two, three, four); /* it will order the struct then return */
                    return;
                }
            }
        }
    }

    else if (banking[customer_number].Label == 3)
    { /* if the label of new coming customer is three it will go here */
        for (i = 0; i < 25; i++)
        { /*it will check the customer with label three */

            for (j = 0; j < 2; j++)
            {

                if (three[i][j] == -5)
                {
                    three[i][j] = 3;
                    order_struct(banking, customer_number, 3, i, j, zero, one, two, three, four); /* it will order the struct then return */
                    return;
                }
            }
        }
    }

    else if (banking[customer_number].Label == 4)
    { /* if the label of new coming customer is four it will go here */

        for (i = 0; i < 25; i++)
        { /*it will check the customer with label four */
            for (j = 0; j < 2; j++)
            {
                if (four[i][j] == -5)
                {
                    four[i][j] = 4;
                    order_struct(banking, customer_number, 4, i, j, zero, one, two, three, four); /* it will order the struct then return */
                    return;
                }
            }
        }
    }
}

/**
 * It will order the structs.
 *
 * @param banking the struct that holds all the customers
 * @param customer_number The index of the customer in the banking struct.
 * @param menuInput_num This is the label of the customer.
 * @param row the row of the customer you want to move
 * @param column the column of the array that you want to change
 * @param zero the first array of the struct
 * @param one the first customer
 * @param two the struct that is being ordered
 * @param three the array of structs
 * @param four the array of customers with label four
 */
void order_struct(struct bank *banking, int customer_number, int menuInput_num, int row, int column, int zero[][5], int one[][3], int two[][3], int three[][2], int four[][2])
{

    int counter = -1, out = 0;
    int i, j;
    char temp_name[30];       /* it will hold the first name */
    int temp_age, temp_label; /* they will hold the first value of age and lable */

    if (menuInput_num == 0)
    { /* if the new customers label is zero it will go here and order the struct */
        for (i = 0; i < 25; i++)
        { /*it will check the customer with label zero */

            if (i < 12)
            {
                for (j = 0; j < 5; j++)
                {
                    if (zero[i][j] != -5)
                    {

                        counter++;
                        if (i == row && j == column)
                        {

                            out = 1;
                            break;
                        }
                    }
                }
                if (out == 1)
                {
                    break;
                }
            }
            if (i < 17)
            { /*it will check the customer with label one */
                for (j = 0; j < 3; j++)
                {
                    if (one[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label two */
                for (j = 0; j < 3; j++)
                {
                    if (two[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }

            for (j = 0; j < 2; j++)
            { /*it will check the customer with label three */
                if (three[i][j] != -5)
                {
                    counter++;
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label four */
                if (four[i][j] != -5)
                {

                    counter++;
                }
            }
        }
    }

    if (menuInput_num == 1)
    { /* if the new customers label is one it will go here and order the struct */
        for (i = 0; i < 25; i++)
        { /*it will check the customer with label zero */
            if (i < 12)
            {
                for (j = 0; j < 5; j++)
                {
                    if (zero[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label one */
                for (j = 0; j < 3; j++)
                {
                    if (one[i][j] != -5)
                    {

                        counter++;

                        if (i == row && j == column)
                        {

                            out = 1;
                            break;
                        }
                    }
                }
                if (out == 1)
                {
                    break;
                }
            }
            if (i < 17)
            { /*it will check the customer with label two */
                for (j = 0; j < 3; j++)
                {

                    if (two[i][j] != -5)
                    {

                        counter++;
                    }
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label three */
                if (three[i][j] != -5)
                {
                    counter++;
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label four */
                if (four[i][j] != -5)
                {
                    counter++;
                }
            }
        }
    }
    if (menuInput_num == 2)
    { /* if the new customers label is two it will go here and order the struct */
        for (i = 0; i < 25; i++)
        { /*it will check the customer with label zero */
            if (i < 12)
            {
                for (j = 0; j < 5; j++)
                {
                    if (zero[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label one */
                for (j = 0; j < 3; j++)
                {
                    if (one[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label two */
                for (j = 0; j < 3; j++)
                {
                    if (two[i][j] != -5)
                    {
                        counter++;
                        if (i == row && j == column)
                        {

                            out = 1;
                            break;
                        }
                    }
                }
                if (out == 1)
                {
                    break;
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label three */
                if (three[i][j] != -5)
                {
                    counter++;
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label four */
                if (four[i][j] != -5)
                {
                    counter++;
                }
            }
        }
    }
    if (menuInput_num == 3)
    { /* if the new customers label is three it will go here and order the struct */
        for (i = 0; i < 25; i++)
        { /*it will check the customer with label zero */
            if (i < 12)
            {
                for (j = 0; j < 5; j++)
                {
                    if (zero[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label one */
                for (j = 0; j < 3; j++)
                {
                    if (one[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label two */
                for (j = 0; j < 3; j++)
                {
                    if (two[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label three */
                if (three[i][j] != -5)
                {
                    counter++;
                    if (i == row && j == column)
                    {

                        out = 1;
                        break;
                    }
                }
            }

            if (out == 1)
            {
                break;
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label four */
                if (four[i][j] != -5)
                {
                    counter++;
                }
            }
        }
    }
    if (menuInput_num == 4)
    { /* if the new customers label is four it will go here and order the struct */
        for (i = 0; i < 25; i++)
        { /*it will check the customer with label zero */
            if (i < 12)
            {
                for (j = 0; j < 5; j++)
                {
                    if (zero[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label one */
                for (j = 0; j < 3; j++)
                {
                    if (one[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            if (i < 17)
            { /*it will check the customer with label two */
                for (j = 0; j < 3; j++)
                {
                    if (two[i][j] != -5)
                    {
                        counter++;
                    }
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label three */
                if (three[i][j] != -5)
                {
                    counter++;
                }
            }
            for (j = 0; j < 2; j++)
            { /*it will check the customer with label four */
                if (four[i][j] != -5)
                {
                    counter++;
                    if (i == row && j == column)
                    {

                        out = 1;
                        break;
                    }
                }
            }
            if (out == 1)
            {
                break;
            }
        }
    }

    strcpy(temp_name, banking[customer_number].Name);
    temp_age = banking[customer_number].Age;
    temp_label = banking[customer_number].Label;

    for (i = customer_number; i > counter; i--)
    { /* it will order the structs */

        banking[i] = banking[i - 1];
    }

    strcpy(banking[counter].Name, temp_name);
    banking[counter].Age = temp_age;
    banking[counter].Label = temp_label;
}
