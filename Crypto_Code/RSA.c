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
// Time Complexity -> O(log(n))
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




//Inverse Modular
//GCD Extended  
// Little Fermat's Algo
/*
* 

*/


int InverseModular(int e,int mod)
{

  return ModuloPow(e,mod-2,mod);


}





//GCD Function

// Time complexity --> O(log(n))  
// Euclidean Algo
int gcd(int x,int y)
{

  if(x==0)
  return y;


  return (y%x,y);

}






int main()
{

    int p,q; // both are large prime number.

    scanf("%d %d",&p,&q);

    int n=p*q;  

    int phi_n=(p-1)*(q-1);  //euclid totion function

    int e,d;

 // need to find  'e'  which is 1<e<phi_n() and gcd(e,phi_n)=1   

    for(int i=2;i<phi_n;i++)
    {
       if(gcd(i,phi_n)==1)
       {

           e=i;
           break;
       }



    }

/*
 *find 'd' such that  : e*d=1 mod phi_n
 *    i.e.    =>   (e*d)mod phi_n=1;
 *            =>    d=inverse(e)mod phi_n;  

*/

  d=InverseModular(e,phi_n)% phi_n;





}