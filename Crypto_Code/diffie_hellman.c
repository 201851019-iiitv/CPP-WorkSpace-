/*

-----------------------------------------------------------

          Author:Ambesh Kumar
          Student ID:201851019

-----------------------------------------------------------

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdint.h>

// ModuloPow()

int ModuloPow(int a ,int b,int mod)
{

a %=mod;
   int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;


}



int main()
{

    int q,a,xa,xb;  // q is a prime number and a is primitive root of q
                   // xa is key of alice and xb key of bob
 printf("Enter the a ,q ,key of alice and bob\n");
 scanf("%d %d %d %d",&a,&q,&xa,&xb);
  printf("public key shared by alice is :");
  int ya=ModuloPow(a,xa,q);  //module power calculator
printf("%d\n",ya);

printf("public key shared by bob is :");
  int yb=ModuloPow(a,xb,q);  //module power calculator
printf("%d\n",yb);

int ka,kb;

printf("Secret key generate by alice is :");
  ka=ModuloPow(yb,xa,q);  //module power calculator
printf("%d\n",ka);


printf("Secret key generate by bob is :");
  kb=ModuloPow(ya,xb,q);  //module power calculator
printf("%d\n",kb);


}