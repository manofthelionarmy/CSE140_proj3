
#include <stdio.h>
void peepholeOptimization(int m, int n, float *A, float *C){

}
void registerBlocking(int m, int n, float *A, float *C){

}
void blocking(int m, int n, float *A, float *C){
	

}
void copying(int m, int n, float *A, float *C){

}
void preComputeTranspose(int m, int n, float *A, float *C){

}
void SSEInstructions(int m, int n, float *A, float *C){

}
void reordering(int m, int n, float *A, float *C){
	//n x n matrix, strip size is m 
	for( int k = 0; k < n; k++ )
    	for( int j = 0; j < m; j++ ) 
      		for( int i = 0; i < m; ++i ) 
				C[i+j*m] += A[i+k*m] * A[j+k*m];

}
void unrolloing(int m, int n, float *A, float *C){
	int f = m % 4; 
	for(int k = 0; k < n; k++ ){
		for(int j = 0; j < m; j++  ){
			for( int i = 0; i <= (m-f-4); i+=4 ){
				C[i+j*m] += A[i+k*m] * A[j+k*m];
				C[(i+1)+(j)*m] += A[(i+1)+k*m] * A[(j)+k*m];
				C[(i+2)+(j)*m] += A[(i+2)+k*m] * A[(j)+k*m];
				C[(i+3)+(j)*m] += A[(i+3)+k*m] * A[(j)+k*m];
			}
		}
	}
	if( f == 3){
		for( int k = 0; k < n; k++){
			for(int j = 0; j < m; j++){
				for(int i = (m-f); i < m; i+=3 ){
					C[i+j*m] += A[i+k*m] * A[j+k*m];
					C[(i+1)+(j)*m] += A[(i+1)+k*m] * A[(j)+k*m];
					C[(i+2)+(j)*m] += A[(i+2)+k*m] * A[(j)+k*m];
				}
			}
		}
		return; 
	}
	if(f == 2){
		for( int k = 0; k < n; k++ ){
			for( int j = 0; j < m; j++ ){
				for( int i = (m-f); i < m; i+=2){
					C[i+j*m] += A[i+k*m] * A[j+k*m];
					C[(i+1)+(j)*m] += A[(i+1)+k*m] * A[(j)+k*m];
				}
			}
		}
		return; 
	}
	if( f == 1){
		for( int k = 0; k < n; k++  ){
			for( int j = 0; j < m; j++){
				for(  int i = (m-f); i < m; i++){
					C[i+j*m] += A[i+k*m] * A[j+k*m];
				}
			}
		}
		return; 
	}
    if(f == 0){
    	return;
    }

    
	
	
}
void dgemm( int m, int n, float *A, float *C )
{
// FILL-IN 

	//reordering(m, n, A, C); 
	unrolloing(m, n, A, C);
  
}
