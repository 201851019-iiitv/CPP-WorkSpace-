/*

-----------------------------------------------------------

          Author:Ambesh Kumar
          Student ID:201851019

-----------------------------------------------------------

*/

#include <stdio.h>
#include <stdint.h>
#define ul unsigned long

int powMod(int a, int x,  int p)
{
  unsigned long long result = 1;
  int iter = 0;
  while(x)
  {
    result = (x&1) ? (result * a) % p : result;
    x = x >> 1; 
    a = (a * a) % p;
  }
  return result;
}


int main()
{
  
  int a,b;

  scanf("%d",&a,&b);




    return 0;
}