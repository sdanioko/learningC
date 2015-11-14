/********************************************************************************
 * In here, we are defining the arithmetic operations that operates on complex  *
 * structures. The takes pointers as arguments and return a complex.            *
 ** *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "newcomplex3.h" 


/* One should be aware of the use of constant here. In here, const struct complex or
 * const COMPLEX  means that you can you can edit the field of the structure after 
 * declaration and initialization of the structure. However, you can just retrieve
 * the data from the structure */


COMPLEX mult2(const COMPLEX *a, const COMPLEX *b)
{             /* const struct to read only*/

        /* Take two complex numbers and compute their multiplication */
	COMPLEX theProd;
	theProd.x_realpart = (a-> x_realpart)*(b-> x_realpart) - (a-> y_imagpart)*(b-> y_imagpart); /* set the real part of theProd */
	theProd.y_imagpart = (a-> x_realpart)*(b-> y_imagpart) + (b-> x_realpart)*(a-> y_imagpart); /* set the imag part of theProd */
	
	return theProd; /* Note : we only return a complex here */

}

COMPLEX square(const COMPLEX *a)
{              /*const struct to read only*/

        /* Take a complex number and compute its square */
	COMPLEX theSquare;
	theSquare.x_realpart =(a-> x_realpart)*(a-> x_realpart)-(a-> y_imagpart)*(a-> y_imagpart); /* set the real part of theSquare */
	theSquare.y_imagpart = 2*(a-> x_realpart)*(a-> y_imagpart); /* set the imag part of the Square*/

	return theSquare; /* Note : we only return a complex here */

}

COMPLEX add2(const COMPLEX *a, const COMPLEX *b)
{            /*const struct to read only*/

        /* Take two complex numbers and compute their addition */
	COMPLEX theSum;
	theSum.x_realpart = (a-> x_realpart) + (b-> x_realpart); /* set the real part of theSum*/
	theSum.y_imagpart = (a-> y_imagpart) + (b-> y_imagpart); /* set the imag part of theSum*/

	return theSum; /* Note : we only return a complex here */

}

COMPLEX  juliamap(const COMPLEX *z, const COMPLEX *c)
{                 /*const struct to read only*/

        /* Take two complex numbers, then square the first one and add the result of that to the second one*/
	COMPLEX  amappedJulia;
	amappedJulia.x_realpart = (z-> x_realpart)*(z-> x_realpart) - (z-> y_imagpart)*(z-> y_imagpart) + (c-> x_realpart); /*set the real part of amappedJulia*/
	amappedJulia.y_imagpart = 2*(z-> x_realpart)*(z-> y_imagpart) + (c-> y_imagpart); /* set the imag part of the amappedJulia*/

	return amappedJulia; /* Note : we only return a complex here */

}

void complex_print(const COMPLEX *acomplex)
{                  /*const struct to read only*/

   	printf(" z = %Lf +  %Lfi \n", acomplex-> x_realpart, acomplex-> y_imagpart); /* print the info in complex z */

}

	
