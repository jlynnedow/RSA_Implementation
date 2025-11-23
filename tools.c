#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"

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
	double p = power(a, d);
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

long power(int a, int b){
	long res = a;
	for(int i = 0; i < b-1; i++){
	res *= a;
	}
	return res;
}

int gcd(int a, int b){
	if(a < b){
		a = b ^ a;
		b = a ^ b;
		a = b ^ a;
	}
	int r = a % b;
	if(r == 0) return b;
	return gcd(b, r);
}
