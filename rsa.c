#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

 int getPublicKey(int p, int q){
     int t = (p-1) * (q-1);
     int e = 0;
     for(int i = 2; i < t; i++){
         if(gcd(i, t) == 1){
             e = i;
             break;
         }
     }
     return e;
 }

 int getPrivateKey(int p, int q, int e){
     int t = (p-1) * (q-1);
     int j = 0;
     int d = 0;
     while(1){
        if((j * e) % t == 1){
             d = j;
             break;
         }
         j++;
     }
     return d;
 }

 int encrypt(int message, int e, int n){
	 return power(message, e) % n;
 }

 int decrypt(int encrypted, int d, int n){
     return power(encrypted, d) % n;
 }

 int main(int argc, char * argv[]){
     int p = atoi(argv[1]);
     int q = atoi(argv[2]);
     int n = p * q;
	 char buff[20];
     int message = fgets(buff, 20, stdin)
     int pub = getPublicKey(p, q);
     int priv = getPrivateKey(p, q, pub);
     int enc = encrypt(message, pub, n);
     printf("og: %d\nencrypted: %d\ndecrypted: %d\n", message, enc, decrypt(enc, priv, n));
 }
                                                 
