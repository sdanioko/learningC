/**********************************************************************************************************************
 * From the previous homework, we have noticed that our fib function had produced some negative numbers.
 * Such an unexpected result from a novice point of view is mainly due to the limited range of an int.
 * This is called overflow or rollover, which works like the odometer of a car. Once you go past the
 * maximum number that can be represented, it rolls over and starts from the beginning .
 *
 * In this project, we aim at finding a better data type that will avoid us a weird situation as seen with
 * integer. For, the best data type will be long double. 
 * ********************************************************************************************************************/
 

#include <stdlib.h>
#include <stdio.h>

void fib(int n);                               /* declare the prototype of the fib function */


int main()
{
        int  number; /* declare an integer variable  that will hold the number that will be punch in by the user.
	 In our case n should be 100*/ 
	printf(" Please enter a number : ");   /* prompt the user to enter a number. To respond to the given problem
	one should just enter 100. But, in a general case, they can just enter any integer they will like to */
        scanf("%d", &number);

        fib(number);                           /* calling the fibonacci function that was defined below*/

	return 0;

}


void fib (int n)
{

	long double container[n];              /* declaring an array of size n */
	int  index_int = 2;                    /* decalring index_int as an integer that will allow me to go through the element of 
                                        	above defined array*/
     
	/* as requested by the given problem*/
	container[0] = 1;                      /* setting the first element of the container to 1 as requested*/
	container[1] = 1;                      /* setting the second element of the container to 1* as requested*/
        printf("%Lf\n", container[0]);         /* printing the first element of the container*/
	printf("%Lf\n", container[1]);         /* printing the second element of the container*/

	while(index_int < n)
	{
		/* starting from the third entry, the current entry is the sum of the two previous entries of the array*/
		container[index_int] = container[index_int-1] + container[index_int-2];
		printf("%Lf",container[index_int]); /* printing the content of the container at the location index_int */

		index_int = index_int + 1;     /* updating the index*/
		printf("\n");                  /* allowing me to go to the next line*/
	}

}



