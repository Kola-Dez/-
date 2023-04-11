#include <iostream>

class MATRIXD 
{
	private:
		void dynamic_array_print(int** A, size_t N, size_t M) { //Matrix output
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					printf("%*d", 5, A[i][j]);
				}
				printf("\n");
			}
		}

	private:
		int** dynamic_array_alloc(size_t N, size_t M) { //Allocate space for the matrix

			int** A = (int**)malloc(N * sizeof(int*));
			if (A != NULL) {
				for (int i = 0; i < N; i++) {
					A[i] = (int*)malloc(M * sizeof(int));
				}
			}
			else if(A == NULL) {
				exit(1);
			}
			return A;
		}

	private:
		void dynamic_array_free(int** A, size_t N){ //Freeing Matrix Data
			for (int i = 0; i < N; i++) {
				free(A[i]);
			}
			free(A);
		}

	private:
		void dynamic_array_rand(int** A, size_t N, size_t M) { //Filling a Matrix with Random Values
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					A[i][j] = rand() % 60 - 20;
				}
			}
		}

	private:
		void dynamic_array_work1(int** A, size_t N, size_t M, int QuantityDiag) { //Exercise 1

			int CompletedDiag = 0;
			int numb1 = 1;
			int numb2 = 0;
			int numb3 = 0;

			int* StartDiagonal;
			StartDiagonal = (int*)malloc(QuantityDiag * sizeof(int));

			for (int i = 0; i < QuantityDiag; i++) {
				printf("StartDiagonal[%d] = ", i + 1);
				std::cin >> StartDiagonal[i];
			}

			printf("\n");

			int* SumDownDiag;
			SumDownDiag = (int*)malloc(QuantityDiag * sizeof(int));
			for (int i = 0; i < QuantityDiag; i++) {
				SumDownDiag[i] = 0;
			}

			while (QuantityDiag > CompletedDiag) {
				printf("Sum = ");
				for (int c = 0; c <= StartDiagonal[numb2] * 4; ++c) {
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < M; j++) {
							if (i + j == StartDiagonal[numb2] + 1 + c) {
								if (A[i][j] <= 0) {
									SumDownDiag[numb3] += A[i][j];
									SumDownDiag[numb3];
									printf("%d ", A[i][j]);
								}
							}
						}
					}
				}
				printf("\n");
				numb1 += 1;
				numb2 += 1;
				numb3 += 1;
				CompletedDiag += 1;
			}



			for (int i = 0; i < QuantityDiag; i++) {
				printf(" SumDownDiag%d = %d \n", i + 1, SumDownDiag[i]);
			}
			int Summ = 1;
			for (int i = 0; i < QuantityDiag; i++) {
				Summ *= SumDownDiag[i];
			}
			printf(" Summ = %d \n", Summ);
			free(StartDiagonal);
			free(SumDownDiag);


		}

	private:
		void dynamic_array_work2(int** A, size_t N, size_t M, int StartDiag) { //Exercise 2

			int SumDownDiag = 0;
			printf("Sum = ");
			for (int c = 0; c < StartDiag * 4; c++) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (i + j == StartDiag + 1 + c) {
							SumDownDiag += A[i][j];
							printf("%d ", A[i][j]);
						}
					}
				}
			}
			printf("\nSumDownDiag = %d\n", SumDownDiag);
		}

		
	public:
		void dynamic_array_test1(size_t N, size_t M, int QuantityDiag) { //Exercise 1
			int** A = dynamic_array_alloc(N, M);
			dynamic_array_rand(A, N, M);
			dynamic_array_work1(A, N, M, QuantityDiag);
			dynamic_array_print(A, N, M);
			dynamic_array_free(A, N);
		}

	public:
		void dynamic_array_test2(size_t N, size_t M, int  StartDiag) { //Exercise 2
			int** A = dynamic_array_alloc(N, M);
			dynamic_array_rand(A, N, M);
			dynamic_array_work2(A, N, M, StartDiag);
			dynamic_array_print(A, N, M);
			dynamic_array_free(A, N);
		}
	public:
		void Input() //MAIN
		{
			using namespace std;
			int flag = 1;

			cout << "\t\tWELCOME\n\n";

			while (flag == 1)
			{
				int type;
				cout << "Input type opiration (1,2) = ";
				cin >> type;
				if (type == 1)
				{
					int MATRIX_HEIGHT;
					int MATRIX_WIDTH;
					int QuantityDiag;


					cout << "\nMATRIX_HEIGHT = ";
					cin >> MATRIX_HEIGHT;
					cout << "\n";
					cout << "MATRIX_WIDTH = ";
					cin >> MATRIX_WIDTH;
					cout << "\n";
					cout << "Quantity Diagonal = ";
					cin >> QuantityDiag;

					dynamic_array_test1(MATRIX_HEIGHT, MATRIX_WIDTH, QuantityDiag);
				}

				else if (type == 2) {
					int MATRIX_HEIGHT;
					int MATRIX_WIDTH;
					int StartDiag;

					cout << "\nMATRIX_HEIGHT = ";
					cin >> MATRIX_HEIGHT;
					cout << "\n";
					cout << "MATRIX_WIDTH = ";
					cin >> MATRIX_WIDTH;
					cout << "\n";
					cout << "Start Diagonal = ";
					cin >> StartDiag;

					dynamic_array_test2(MATRIX_HEIGHT, MATRIX_WIDTH, StartDiag);
				}

				cout << "Do you want continue next operation? \n Yes = 1 \n No = 0 \n You input << ";
				cin >> flag;
			}
		}
};
