/*In here, we work on complex numbers and some arithmetic operations whose 
 * arguments are complex numbers. For, we will need to define a data type 
 *named struct complex. In this, any object of type struct complex will 
 *have a real and an imaginary parts Once such a data type is define, we
 *will write the arithemetic operations such as the multiplication of
 *two complex numbers, the square of a complex number, the addition of two
 *complex numbers, the juliamap, and to finally have a function that will
 *print a complex number as a tring in the form of a +ib.
 ** **********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct complex
{
	long double x_realpart;
	long double y_imagpart;

};

typedef struct complex COMPLEX;

COMPLEX mult2(const COMPLEX *a, const COMPLEX *b);
COMPLEX square(const COMPLEX *a);
COMPLEX add2(const COMPLEX *a, const COMPLEX *b);
COMPLEX juliamap(const COMPLEX *a, const COMPLEX *b);
void complex_print( const COMPLEX *acomplex);
void test();

int main()

{
	test();
	
	return 0;
}

COMPLEX mult2(const COMPLEX *a, const COMPLEX *b)
{
        /* Take two complex numbers and compute their multiplication */
	struct complex theProd;
	theProd.x_realpart = (a-> x_realpart)*(b-> x_realpart) - (a-> y_imagpart)*(b-> y_imagpart);
	theProd.y_imagpart = (a-> x_realpart)*(b-> y_imagpart) + (b-> x_realpart)*(a-> y_imagpart);
	
	return theProd; 

}

COMPLEX square(const COMPLEX *a)
{
        /* Take a complex number and compute its square */
	struct complex theSquare;
	theSquare.x_realpart =(a-> x_realpart)*(a-> x_realpart)-(a-> y_imagpart)*(a-> y_imagpart);
	theSquare.y_imagpart = 2*(a-> x_realpart)*(a-> y_imagpart);

	return theSquare;

}

COMPLEX add2(const COMPLEX *a, const COMPLEX *b)
{            /*constant structure*/
     
        /* Take two complex numbers and compute their addition */
	struct complex  theSum;
	theSum.x_realpart = (a-> x_realpart) + (b-> x_realpart);
	theSum.y_imagpart = (a-> y_imagpart) + (b-> y_imagpart);

	return theSum; 

}

COMPLEX  juliamap(const COMPLEX *z, const COMPLEX *c)
{                 /*constant structure*/

        /* Take two complex numbers, then square the first one and add the result of that to the second one*/
	struct complex amappedJulia;
	amappedJulia.x_realpart = (z-> x_realpart)*(z-> x_realpart) - (z-> y_imagpart)*(z-> y_imagpart) + (c-> x_realpart);
	amappedJulia.y_imagpart = 2*(z-> x_realpart)*(z-> y_imagpart) + (c-> y_imagpart);

	return amappedJulia;

}

void complex_print(const COMPLEX *acomplex)
{
 	/* print complex z info */

   	printf(" z = %Lf +  %Lfi \n", acomplex-> x_realpart, acomplex-> y_imagpart);

}

void test()
{
 	/* From now on, we will be using . right after an integer in order to be in full agreement with the definition of 
 *  	 my x_realpart and y_imagpart since they were defined as long double */

	COMPLEX compl1;
	compl1.x_realpart = 1.;
	compl1.y_imagpart = 2.;

	COMPLEX compl2;
	compl2.x_realpart = 3.;
	compl2.y_imagpart = 4.;

	/* let's test */
       /* let's compute the multipliction*/

	COMPLEX expected1;
	expected1.x_realpart = -5.; /* this is the real part of the complex number obtained by computing 1+2i and 3+4i*/
	expected1.y_imagpart = 10.; /* this is the imaginary part of the complex number obtained by computing 1+2i and 3+4i */
	
	COMPLEX result1;
	COMPLEX *cptr11, *cptr12;
	cptr11 = &compl1;
	cptr12 = &compl2;
	result1 = mult2(cptr11,cptr12);
	/*complex_print(result1)*/; /* print the result of the multiplication of two complex numbers*/
	assert (expected1.x_realpart == result1.x_realpart);
	assert (expected1.y_imagpart == result1.y_imagpart);

       /* let's compute the square of the first  complex given above */
	COMPLEX expected2;
	expected2.x_realpart = -3.; /* this is the real part of the complex number obtained by squaring 1+2i*/
	expected2.y_imagpart = 4.;  /* this is the imaginary part of the complex number obtained by squaring 1+2i*/

	COMPLEX result2;
	COMPLEX *cptr2;
	cptr2 = &compl1;
	result2 = square(cptr2);
	/*complex_print(result2)*/; /* print the result of the square of compl1*/
	assert (expected2.x_realpart == result2.x_realpart);
	assert (expected2.y_imagpart == result2.y_imagpart);

       /* let's compute the addition of two complex numbers */
	COMPLEX expected3; 
	expected3.x_realpart = 4.; /* this is the real part of the complex number obtained by adding 1+2i and 3+4i*/
	expected3.y_imagpart = 6.; /* this ia the imag part of the complex number obtained by adding 1+2i and 3+4i*/

	COMPLEX result3;
	COMPLEX *cptr31, *cptr32;
	cptr31 = &compl1;
	cptr32 = &compl2;
	result3 = add2(cptr31,cptr32);
	/*complex_print(result3)*/; /* print the result of the addition of compl1 and compl2*/
	assert (expected3.x_realpart == result3.x_realpart);
	assert (expected3.y_imagpart == result3.y_imagpart);

       /* let's compute the juliamap where z= compl1 is the first variable and c= compl2 is the second variable*/
	COMPLEX expected4;
	expected4.x_realpart = 0.; /* this is the real part of the complex number obtained by adding the square of compl1 to compl2*/
	expected4.y_imagpart = 8.; /* this is the imag part of the complex number obtained by adding the square of compl1 to compl2*/

	COMPLEX result4;
	COMPLEX *cptr41, *cptr42;
	cptr41 = &compl1;
	cptr42 = &compl2;
	result4 = juliamap(cptr41,cptr42); 
	/*complex_print(result4)*/; /* print the result of the juliamap*/
	assert (expected4.x_realpart == result4.x_realpart);
	assert (expected4.y_imagpart == result4.y_imagpart);

       /* let's compute the complex_return function with compl1 as the argument*/
	COMPLEX expected5;
	expected5.x_realpart = 1.;
	expected5.y_imagpart = 2.;

        COMPLEX *cptr5;
	cptr5 = &expected5;
        complex_print(cptr5);
	printf(" if the previous sentence is z = 1.000000+2.000000i, then the complex return is  working as expected \n" );

}
	
