#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isProbablyPrime();
int millerTest();

int main(){
	for(int i = 0; i < 30; i++){
		printf("%d: %d\n", i, isProbablyPrime(i, 4));
	}
	return 0;
}

int isProbablyPrime(int n, int k){
	 if(n == 1) return 0;
	 if(n == 2 || n == 3) return 1;
	 if(n % 2 == 0) return 0;
	 int d = n-1;
	 while(d/2 > 0){
		 d /= 2;
	 }
	 for(int i = 0; i < k; i++){
		 if(!millerTest(n, d)) return 0;
	 }
	 return 1;
}

int millerTest(int n, int d){
	int a = rand() % (n-1);
	double p = pow(a, d);
	int x = ((int) p) % n;
	if(x == 1 || x == (n-1)) return 1;
	while(d != n-1){
		x = (x*x) % n;
		d *= 2;
		if(x == 1) return 0;
		if(x == n-1) return 1;
	}
	return 0;
}
