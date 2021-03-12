//Feistel Network with roundfunction f(x)=S(x+k), where S(x)=(x+1)%16;


#include<stdio.h>

#define ull unsigned long long
#define ul unsigned long
#define mul 4294967296  //2^32
#define NBITS 32 


//Right rotate function


//This function will give R0
ul right(ull pl){
   ul temp;
   temp=(int)pl;
         
   return temp;
}

//This function will give L0
ul left(ull pl){
   ul temp;     
   temp=pl>>32;
   return temp;
}


//The round function

ul roundfunction(ul in){
   int i, k;
   ul t1, temp=(ul)0, t2, t3;
   t3=in;
   k=0;
   for(i=0; i<8;i++){
      t1=(in&15);
      t1=(t1+1)%16;
      t2=(t1 << k);
      temp=(temp | t2);
      in=in>>4;
      k=k+4;
   }
   return temp;

}


int main(){
    ull plain, cipher;
    ul key,l0,l1,r0,r1;
    printf("Enter 64-bit plaintext\n");
    scanf("%llu",&plain);
    printf("Enter 32-bit key\n");
    scanf("%lu",&key);
    printf("\nEncryption Starting\n");

//Finding L0 and R0

    l0=left(plain); r0=right(plain);
    printf("L0: %lu   R0:%lu\n",l0,r0);

//Checking R0+K    
    printf("R0+K: %lu\n",r0^key);


//Computing L1 and R1
    l1=r0; r1=l0^roundfunction(r0^key);
    printf("L1: %lu   R1: %lu\n",l1,r1);

//Generating final ciphertext
    cipher=(ull)0;
    cipher=cipher|l1;
    cipher=cipher<<32;
    cipher=cipher|r1;
    printf("Ciphertext\n");
    printf("%llu\n",cipher);
    
}