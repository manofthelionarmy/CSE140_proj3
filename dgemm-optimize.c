
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
	for( int k = 0; k < n; k++ )
    	for( int j = 0; j < m; j++ ) 
      		for( int i = 0; i < m; ++i ) 
				C[i+j*m] += A[i+k*m] * A[j+k*m];

}
void unrolloing(int m, int n, float *A, float *C){
	
	int f = m % 8;
	int g = m % 4; 

	if(g < f){
		for( int k = 0; k < n; k++ ){
			for( int j = 0; j < m; j++ ) {
				for( int i = 0; i <= (m-g-4); i += 4 ) {

					C[i+j*m] += A[i+k*m] * A[j+k*m];
					C[(i+1)+j*m] += A[(i+1)+k*m] * A[j+k*m];
					C[(i+2)+j*m] += A[(i+2)+k*m] * A[j+k*m];
					C[(i+3)+j*m] += A[(i+3)+k*m] * A[j+k*m];
					
      			}
    		}
		}
		if(f == 0 && g == 0) {
			return; 
		}
		else{
			f  = g; 
			for(int k = 0; k < n; ++k){
				for(int j = 0; j < m; ++j){
					for(int i = (m - f); i < m; ++i){
						C[i+j*m] += A[i+k*m] * A[j+k*m];
					}
				}
			}
		}
	}
	else{


		for( int k = 0; k < n; k++ ){
			for( int j = 0; j < m; j++ ) {
				for( int i = 0; i <= (m-f-8); i += 8 ) {

					C[i+j*m] += A[i+k*m] * A[j+k*m];
					C[(i+1)+j*m] += A[(i+1)+k*m] * A[j+k*m];
					C[(i+2)+j*m] += A[(i+2)+k*m] * A[j+k*m];
					C[(i+3)+j*m] += A[(i+3)+k*m] * A[j+k*m];
					C[(i+4)+j*m] += A[(i+4)+k*m] * A[j+k*m];
					C[(i+5)+j*m] += A[(i+5)+k*m] * A[j+k*m];
					C[(i+6)+j*m] += A[(i+6)+k*m] * A[j+k*m];
					C[(i+7)+j*m] += A[(i+7)+k*m] * A[j+k*m];
	      		}
	    	}
		}
		if(f == 0 && g == 0) {
			return; 
		}
		for(int k = 0; k < n; ++k){
			for(int j = 0; j < m; ++j){
					for(int i = (m - f); i < m; ++i){
					C[i+j*m] += A[i+k*m] * A[j+k*m];
				}
			}
		}
 	}
	
	

      		
}
void dgemm( int m, int n, float *A, float *C )
{
// FILL-IN 

	//reordering(m, n, A, C); 
	unrolloing(m, n, A, C);
  
}
