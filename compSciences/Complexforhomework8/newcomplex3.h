/********************************************************************************
 * Stucture Complex and some arithmetic operations                              *
 *---------------------------------------------------------------------------   *
struct complex : designates the data type complex that has a real and an        *
                 imaginary part                                                 *

mult2: designates the function that allows us  multiply two complex numbers     *

square: designates the function that allows us take the square of two complex   *
	 numbers                                                                *

add2 : designates the function that allows us add two complex numbers           *

juliamap : designates the function that allows us map two complex numbers       *

complex_print : designates the function that allows us print the information    *
		about a given comlex number                                     *

 ********************************************************************************/     

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


struct complex  /*declare a complex structure*/
{
	long double x_realpart;
	long double y_imagpart;

};

typedef struct complex COMPLEX; /* create an allias that can be used anywhere in place
of the complicated and long expression struct complex*/

COMPLEX mult2(const COMPLEX *a, const COMPLEX *b); 
COMPLEX square(const COMPLEX *a);
COMPLEX add2(const COMPLEX *a, const COMPLEX *b);
COMPLEX juliamap(const COMPLEX *a, const COMPLEX *b);
void complex_print( const COMPLEX *acomplex);
void test();




