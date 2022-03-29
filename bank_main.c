#include "bank_lib.h"

int main()
{

	int zero[12][5];  /* it will hold the number of employees */
	int one[17][3];	  /* it will hold the number of retired people */
	int two[17][3];	  /* it will hold the number of students */
	int three[25][2]; /* it will hold the number of unemployeds */
	int four[25][2];  /* it will hold the number of others */

	int menuInput, customer_number = 0, j; /* menuInput will hold the number user entered */
	struct bank *banking;
	banking = bnk; /* assigning structure array to pointer struct */

	fill_array(zero, one, two, three, four); /* it will fill the array with -5's */

	while (1)
	{

		printf("\n***********Banking System*********** \n\n");

		printf("1-Add customer \n");
		printf("2-Process customer \n");
		printf("3-Exit the program \n \n");
		printf("Please enter your choose(1-3) : ");
		if (scanf("%d", &menuInput))
		{
			printf("\n");

			if (menuInput == 1)
			{ /* if user wants to add customer  */

				if (customer_number == 50)
				{ /* it will give error if we entered more than 50 customers */

					printf("Banking system keeps maximum 50 customer in same time. Please process customer... \n \n");
					continue;
				}

				add_customer(banking, customer_number); /* this function will assign the customers info to the structure */

				order_customer(banking, customer_number, zero, one, two, three, four); /* this funct will order customer and structs */

				printf("Current Sequence: ");

				print_current_sequence(banking, customer_number, zero, one, two, three, four); /* printing the current sequence */

				customer_number++;
			}

			else if (menuInput == 2)
			{ /* if user wants to process costumer */

				if (customer_number == 0)
				{ /* if there is not any customer it will give error */

					printf("There is no customer in bank system sequence. \n \n");

					printf("Current sequence : \n");

					continue;
				}
				printf("Proceed customer is %s \n", bnk[0].Name);

				process_customer(banking, customer_number, zero, one, two, three, four); /* it will process the first customer */

				printf("Current Sequence: ");

				print_current_sequence(banking, customer_number, zero, one, two, three, four); /* it will print the current sequence */

				customer_number--;
			}

			else if (menuInput == 3)
			{ /* if user enters 3 it will end the program */
				printf("Thank you for using my program. Have a nice day! \n ");
				return 0;
			}

			else
			{ /* if user enter wrong input it will give error and ask again */

				printf("PLEASE ENTER INPUT BETWEEN 1-3 \n \n");
				continue;
			}
		}
		else
		{
			/* warn user if he/she doesnt enter an integer */
			printf("\n\nPLEASE ENTER INPUT BETWEEN 1-3 \n \n");
			while (getchar() != '\n')
				;
		}

	} /* End of the while */

	return 0;
}
