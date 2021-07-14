
#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#define ull unsigned long 
// ModuloPow()

ull ModuloPow(ull a ,ull b,ull mod)
{

a %=mod;
   int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res%mod;


}

 // extneds key to 128-bit.
void extend_Key(ull ka,uint8_t *keyV)
{
  
  for(int i=15;i>=0;i--)
  {
    keyV[i]=(ka&0xFF);

    ka >>=8;

  }



}


//taking xor of MACA = (MA ⊕ KA).

void xorv(uint8_t *plain_text ,uint8_t *MAC,uint8_t *keyV)
{

for(int i=0;i<16;i++)
{

MAC[i]=plain_text[i]^keyV[i];


}



}



void  diffie_hellman()
{


    ull p=10007,g=5,xa,xb;  // p is a prime number and g is primitive root of p
                            // xa is key of alice and xb key of bob
 printf("key of alice and bob\n");
 scanf("%lu %lu",&xa,&xb);
  //printf("public key shared by alice is :");
  ull ya=ModuloPow(g,xa,p);  //module power calculator
//printf("%d\n",ya);

//printf("public key shared by bob is :");
  ull yb=ModuloPow(g,xb,p);  //module power calculator
//printf("%d\n",yb);

ull  ka,kb;

printf("Secret key generate by alice is :");
  ka=ModuloPow(yb,xa,p);  //module power calculator
printf("%lu\n",ka);


printf("Secret key generate by bob is :");
  kb=ModuloPow(ya,xb,p);  //module power calculator
printf("%lu\n",kb);



// *completed the project till now 6 point.


uint8_t keyV[16]={0};


// Ask for alice message.
 char plain[16];

  uint8_t plain_text[16] = {0};

  printf("Enter the plain text all are 8 bit 16 values :\n");

  for (int i = 0; i < 16; i++)
  {
    scanf("%x", &plain[i]);
  }

  // change hexadecimal input to 8-bit.
  for (int i = 0; i < 16; i++)
  {
    plain_text[i] = plain[i];
  }


extend_Key(ka,keyV); // extend ka to 8-bit  16 size arr .i.e 128-bit.

  Aes(plain_text, keyV);

// *completed task till  point 8.

// printf("key v of alice  :");
//   for (int i = 0; i < 16; i++)
//     printf("%x ", keyV[i]);
//   printf("\n");




 uint8_t MACa[16]={0} ;

 xorv(plain_text,MACa,keyV);

printf("MAC of alice  :");
  for (int i = 0; i < 16; i++)
    printf("%x ", MACa[i]);
  printf("\n");



// *completed task till  point 11.


/// -- For task 14 :


uint8_t keyB[16]={0};


extend_Key(kb,keyB);

MB_KB(keyB);



}