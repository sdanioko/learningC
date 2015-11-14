/*************************************************************************************************************
 * In here, we work on complex numbers and some arithmetic operations whose  arguments are complex numbers.  * 
 * For, we will need to define a data type  named struct complex. In this, any object of type struct comp.   *

 * Furthermore, we will be testing the validity of the differengt functions we defined. In order to do that, *
 * we will be comparing some expected values some computed ones, where the computed  values are obtained by  *
 * doing the targeted operationby hands and the computed vales are obtained via the function we build in our *
 * code                                                                                                      *
 *************************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "newcomplex3.h"


int main()
{
	test();
	
	return 0;
}

void test()
{
     
	COMPLEX compl1;                /* declare a variable compl1 of type struct complex*/
	compl1.x_realpart = 1.;        /* set the real part of my complex1 to 1*/
	compl1.y_imagpart = 2.;        /* set the imag part of my complex1 to 2*/

	COMPLEX compl2;                /* declare a variable compl2 of type struct complex*/
	compl2.x_realpart = 3.;        /* set the real part compl2 to 3 */
	compl2.y_imagpart = 4.;        /* set the imag part of compl2 to 4*/

        /* lets define pointers to structures*/
	COMPLEX *cptr1;                /* declare a pointer of type struct complex */
	cptr1 = &compl1;               /* pointer cprt1 points compl1 and stores its memory address*/

	COMPLEX *cptr2;                /* declare a pointer of tyoe struct complex */
	cptr2 = &compl2;               /* pointer cprt2 points to compl2 and stores its memory address*/

       /* let's compute the multipliction*/

	COMPLEX expected1;             /* declaring a variable of type struct complex*/
	expected1.x_realpart = -5.;    /* this is the real part of the complex number obtained by computing 1+2i and 3+4i*/
	expected1.y_imagpart = 10.;    /* this is the imaginary part of the complex number obtained by computing 1+2i and 3+4i */	
	COMPLEX result1;               /* declaring a variable of type struct complex*/
	result1 = mult2(cptr1,cptr2);
	assert (expected1.x_realpart == result1.x_realpart);   /*To make sure the real part  */
	assert (expected1.y_imagpart == result1.y_imagpart);
	printf(" The function mult2 is working as expected\n ");

       /* let's compute the square of the first  complex given above */

	COMPLEX expected2;
	expected2.x_realpart = -3.;    /* this is the real part of the complex number obtained by squaring 1+2i*/
	expected2.y_imagpart = 4.;     /* this is the imaginary part of the complex number obtained by squaring 1+2i*/
	COMPLEX result2;               /* declare result2 as a variable of type struct complex */ 
	result2 = square(cptr1);
	assert (expected2.x_realpart == result2.x_realpart);
	assert (expected2.y_imagpart == result2.y_imagpart);
	printf(" The function square is working as expected\n ");

       /* let's compute the addition of two complex numbers */

	COMPLEX expected3; 
	expected3.x_realpart = 4.;     /* this is the real part of the complex number obtained by adding 1+2i and 3+4i*/
	expected3.y_imagpart = 6.;     /* this is the imag part of the complex number obtained by adding 1+2i and 3+4i*/
	COMPLEX result3;               /* decale variable result3 of type struct complex*/
	result3 = add2(cptr1,cptr2);
	assert (expected3.x_realpart == result3.x_realpart);
	assert (expected3.y_imagpart == result3.y_imagpart);
	printf("The function add2 is working as expected\n ");

       /* let's compute the juliamap where z= compl1 is the first variable and c= compl2 is the second variable*/

	COMPLEX expected4;
	expected4.x_realpart = 0.;     /* this is the real part of the complex number obtained by adding the square of compl1 to compl2*/
	expected4.y_imagpart = 8.;     /* this is the imag part of the complex number obtained by adding the square of compl1 to compl2*/
	COMPLEX result4;               /* declare a variable result4 of type struct complex*/
	result4 = juliamap(cptr1,cptr2); 
	assert (expected4.x_realpart == result4.x_realpart);
	assert (expected4.y_imagpart == result4.y_imagpart);
	printf("The function juliamap is working as expected\n");

       /* let's compute the complex_return function with compl1 as the argument*/

	COMPLEX expected5;
	expected5.x_realpart = 1.;
	expected5.y_imagpart = 2.; 
	
        complex_print(cptr1);
	printf(" if the previous sentence is z = 1.000000+2.000000i, then the complex return is  working as expected \n" );

}
	
