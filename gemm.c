#include<stdio.h>
#include<stdlib.h>

#define M 8 
#define N 8
#define K 2

int display(int M1, int N1, int C[M1][N1]){
	

	for(int m=0; m<M1; m++){
		for(int n=0; n<N1; n++){
			printf("%d ", C[m][n]);
			//if (n==N-1)
				
		}
		printf("\n");
	}

	return 0;	 
}


int main(){
	int m, n, k;
	int A[M][K] = {{1, 2},
				   {3, 4},
				   {5, 6},
				   {7, 8},
				   {1, 2},
				   {3, 4},
				   {5, 6},
				   {7, 8}},
		B[K][N] = {{1, 2, 3, 4, 1, 2, 3, 4},
				   {4, 5, 6, 7, 4, 5, 6, 7}},
		C[M][N];
	int ret;

	// GEMM	
	for(m=0; m<M; m++){
		for(n=0; n<N; n++){
			C[m][n] = 0;
			for(k=0; k<K; k++){
				C[m][n] += A[m][k] * B[k][n];
			}
		}
	}

	printf("A=\n");
	display(M, K, A);
	printf("\nB=\n");
	display(K, N, B);
	printf("\nC=\n");
	display(M, N, C);
	
	return 0;
}