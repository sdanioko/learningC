/* In here, let's work on matrix products */

#include <stdio.h>
#include <stdlib.h>

struct MATRIX 
{
	unsigned int rows;
	unsigned int cols;
	long double *mat;

};

typedef struct MATRIX aMatrix;

// Construct a matrix that allows us set and populate our dynamic array
void set(aMatrix *m, int i, int j, long double value){
	*(m-> mat + m->rows*i + j) = value;
}

// get the value at a location i,j

long double get(aMatrix *m, int i, int j){
	return *(m-> mat + m-> rows*i + j);
}

// Let's write a function that will us create a new matrix 
aMatrix new(unsigned int rows, unsigned int cols){

	aMatrix A;
	A.rows = rows;
	A.cols = cols;
	A.mat = (long double *) calloc(A.rows*A.cols, sizeof(long double));

	return A;
}

// Let's write a function that will allow us compute the product of two matrices

aMatrix  matprod(aMatrix firstmat, aMatrix secondmat){
	aMatrix C = new(firstmat.rows,secondmat.cols);
        if(firstmat.cols == secondmat.rows){
           	int i,j,k;
                for( i = 0; i < firstmat.rows ; i++){
                        for(j = 0; j < secondmat.cols; j++){
                                long double  thesum = 0;
                                for(k = 0; k < secondmat.rows ; k++){
                                        thesum = thesum + get(&firstmat,i,k)*get(&secondmat,k,j);
                                }
                                set(&C, i, j, thesum);
                        }
                }
			
        }
        else{ 
        printf( " the sizes of your matrices do not match " );
	C = new(0,0);
	}

	return C;
}

/* Let's write a function that will allow us  print a specific entry (i,j) of the matrix */

void print_me(aMatrix *m, int i,int j){
	printf("%Lf",get(m,i,j));
}

/* Let's write a function that will allow us print a given matrix */

void print_matrix(aMatrix *m){

	int i;
	int j;
	for(i = 0; i < m->rows; ++i){		
		for( j = 0; j < m->cols; ++j){
			print_me(m,i,j);
		}
		puts(" ");
	}
	puts(" ");
	printf("\n");
}


int main()
{
	unsigned int mat1_rows;
	printf(" Enter the number of rows of your first matrix : ");
	scanf("%u", &mat1_rows);
	unsigned int mat1_cols;
	printf("Enter the number of cols of your second matrix : ");
	scanf("%u", &mat1_cols);
	
	aMatrix A = new(mat1_rows,mat1_cols);
	
	int i;
	int j;
	for( i = 0; i < A.rows; i++){
		for(j = 0; j < A.cols; j++){
			long double anumber;
			printf("Please enter a number : ");
			scanf("%Lf",&anumber);
			set(&A, i, j,anumber); 
		}
	}

	print_matrix(&A);
	
	// Construct and populate the second matrix
	unsigned int mat2_rows;
        printf( " Enter the number of rows of your second matrix : ");
        scanf("%u", &mat2_rows);
        unsigned int mat2_cols;
        printf( " Enter the number of cols of your second matrix : ");
        scanf("%u", &mat2_cols);
        
	// create a new space for matrix 2
        aMatrix B = new(mat2_rows,mat2_cols);
      	
	int x;
	int y;
	for(x = 0; x < B.rows; ++x){
                for(y = 0; y < B.cols; ++y) {
                        long double anumber;
                        printf("Please enter a number : ");
                        scanf("%Lf",&anumber);
                        set(&B, i, j,anumber);
                }
        }

	// Print the second matrix to see whether or not our fucntion is operating as expected
	print_matrix(&B);

	// Let's compute the product of two matrices
	aMatrix the_product = new(A.rows,B.cols);
	the_product = matproduct(A,B);
	print_matrix(&the_product);

	return 0;
	
}
