#include <stdio.h>
#include <stdlib.h>

int power(int a, int b){
int res = a;
for(int i = 0; i < b; i++){
      res *= a;
}
     return res;
  }

//euclidean algorithm
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

 int getPublicKey(int p, int q){
     int t = (p-1) * (q-1);
     int e = 0;
     for(int i = 2; i <= t; i++){
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

 int main(){
     int p = 7;
     int q = 11;
     int n = p * q;
     int message = 44;
     int pub = getPublicKey(p, q);
     int priv = getPrivateKey(p, q, pub);
     int enc = encrypt(message, pub, n);
     printf("og: %d\nencrypted: %d\ndecrypted: %d\n", message, enc, decrypt(enc, priv, n));
 }
                                                 
