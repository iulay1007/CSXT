#include <stdio.h>
#include <math.h>
int sqrt(int A, nit p, int e){
	if(abs(p*p-A)<e)
	return p;
	else return sqrt(A,(p+A/p)/2,e); 
}
