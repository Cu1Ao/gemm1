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
	int p;
  	register double c_00_reg,   
  							c_01_reg,   
  							c_02_reg,   
  							c_03_reg,  
  							a_0p_reg;

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
	
	// GEMM-r	
	for(m=0; m<M; m++){
		for(n=0; n<N; n+=4){
			
  			c_00_reg = 0.0; 
  			c_01_reg = 0.0; 
  			c_02_reg = 0.0; 
  			c_03_reg = 0.0;				
			for(k=0; k<K; k++){
				a_0p_reg = A[m][k];

				c_00_reg += a_0p_reg * B[k][n + 0]; 
  				c_01_reg += a_0p_reg * B[k][n + 1]
  				c_02_reg += a_0p_reg * B[k][n + 2]
  				c_03_reg += a_0p_reg * B[k][n + 3]

				C[m][n + 0] += A[m][k] * B[k][n + 0];
				C[m][n + 1] += A[m][k] * B[k][n + 1];
				C[m][n + 2] += A[m][k] * B[k][n + 2];
				C[m][n + 3] += A[m][k] * B[k][n + 3];
			}
			C[m][n + 0] = c_00_reg; 
			C[m][n + 1] = c_01_reg; 
			C[m][n + 2] = c_02_reg; 
			C[m][n + 3] = c_03_reg;
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