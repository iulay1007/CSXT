int g (int m,int n){
	if(m>0)
	return (g(m-1,2*n)+n);
	else return 0;
}
