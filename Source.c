#include <stdio.h>
#include <stdlib.h>

void work(int** A,int MATRIX_HEIGHT,int MATRIX_WIDTH){
	int flag = 1, suma = 1;
	while(flag == 1){
		int StartDiag;
		printf("StartDiag = ");
		scanf("%d", &StartDiag);

	
		int SumDiag = 0;
		for (int c = 0; c < StartDiag * 4; c++) {
			for (int i = 0; i < MATRIX_HEIGHT; i++) {
				for (int j = 0; j < MATRIX_WIDTH; j++) {
					if (i + j == StartDiag + c) {
						if(A[i][j] <= 0){
							SumDiag += A[i][j];
							printf(" \n --------------\n A = %d,\n SumDiag = %d \n --------------\n",A[i][j], SumDiag);
						}
					}
				}
			}
		}
		printf("\nSumDiagNuw = %d\n", SumDiag);
		suma *= SumDiag;
		printf("\nsuma = %d\n", suma);
	
		for (int i = 0; i < MATRIX_HEIGHT; i++) {
			for (int j = 0; j < MATRIX_WIDTH; j++) {
				printf("%*d", 5, A[i][j]);
			}
			printf("\n");
		}


		printf("\nNext [Yes(1)/No(0)] = ");
		scanf("%d",&flag);
	}
}

int main() {
	int MATRIX_HEIGHT, MATRIX_WIDTH, Diag = 0;

	printf("\t\tWELCOME\n\n");

	printf("\nMATRIX_HEIGHT = ");
	scanf("%d", &MATRIX_HEIGHT);
	printf("\nMATRIX_WIDTH = ");
	scanf("%d", &MATRIX_WIDTH);
	printf("\n");

	//alloc
	int** A = (int**)malloc(MATRIX_HEIGHT * sizeof(int*));
	if (A != NULL) {
		for (int i = 0; i < MATRIX_HEIGHT; i++) {
			A[i] = (int*)malloc(MATRIX_WIDTH * sizeof(int));
		}
	}
	else if (A == NULL) {
		exit(1);
	}
	//rund
	for (int i = 0; i < MATRIX_HEIGHT; i++) {
		for (int j = 0; j < MATRIX_WIDTH; j++) {
			A[i][j] = rand() % 60 - 20;
		}
	}
	//work

	work(A ,MATRIX_HEIGHT, MATRIX_WIDTH);

	//free
	for (int i = 0; i < MATRIX_HEIGHT; i++) {
		free(A[i]);
	}
	free(A);
	return 0;
}
