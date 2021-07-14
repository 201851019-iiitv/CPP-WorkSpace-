/*

-----------------------------------------------------------

          Name:Ambesh Kumar
          Student ID:201851019

-----------------------------------------------------------

*/



#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#define ull unsigned long 


// ------------** AES Decryption 128-bit**---------------
uint8_t resulttext[16]={0};



 uint8_t Inv_sbox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};





uint8_t multiply_x(uint8_t n)
{

  if ((n & (1 << 7)) == 0)
  {

    return n << 1;
  }

  return ((n << 1) ^ 0x1b);
}

//taking xor of MACB = (MB ⊕ KB).

void MB_KB(uint8_t *keyV)
{

uint8_t MACB[16];
for(int i=0;i<16;i++)
{

MACB[i]=resulttext[i]^keyV[i];


}

printf("MAC of bob  :");
  for (int i = 0; i < 16; i++)
    printf("%x ", MACB[i]);
  printf("\n");




}


 void inv_shift_rows(uint8_t *plainText) {

  
  uint8_t temp[16];

  temp[0] = plainText[0];
  temp[5] = plainText[1];
  temp[10] = plainText[2];
  temp[15] = plainText[3];
  temp[4] = plainText[4];
  temp[9] = plainText[5];
  temp[14] = plainText[6];
  temp[3] = plainText[7];
  temp[8] = plainText[8];
  temp[13] = plainText[9];
  temp[2] = plainText[10];
  temp[7] = plainText[11];
  temp[12] = plainText[12];
  temp[1] = plainText[13];
  temp[6] = plainText[14];
  temp[11] = plainText[15];

  for (int i = 0; i < 16; i++)
  {
    plainText[i] = temp[i];
  }

}


void AES_Decryption(const uint8_t *roundkeys, const uint8_t *ciphertext) {

    uint8_t tmp[16];
    uint8_t t, u, v;
    uint8_t i, j;

    roundkeys += 160;

    // first round
    for ( i = 0; i < 16; ++i ) {
        *(resulttext+i) = *(ciphertext+i) ^ *(roundkeys+i);
    }
    roundkeys -= 16;
    inv_shift_rows(resulttext);
    for (i = 0; i < 16; ++i) {
        *(resulttext+i) = Inv_sbox[*(resulttext+i)];
    }

    for (j = 1; j < 10; ++j) {
        
        // Inverse AddRoundKey
        for ( i = 0; i < 16; ++i ) {
            *(tmp+i) = *(resulttext+i) ^ *(roundkeys+i);
        }
        
        for (i = 0; i < 16; i+=4) {
            t = tmp[i] ^ tmp[i+1] ^ tmp[i+2] ^ tmp[i+3];
            resulttext[i]   = t ^ tmp[i]   ^ multiply_x(tmp[i]   ^ tmp[i+1]);
            resulttext[i+1] = t ^ tmp[i+1] ^ multiply_x(tmp[i+1] ^ tmp[i+2]);
            resulttext[i+2] = t ^ tmp[i+2] ^ multiply_x(tmp[i+2] ^ tmp[i+3]);
           resulttext[i+3] = t ^ tmp[i+3] ^ multiply_x(tmp[i+3] ^ tmp[i]);
            u = multiply_x(multiply_x(tmp[i]   ^ tmp[i+2]));
            v = multiply_x(multiply_x(tmp[i+1] ^ tmp[i+3]));
            t = multiply_x(u ^ v);
            resulttext[i]   ^= t ^ u;
            resulttext[i+1] ^= t ^ v;
            resulttext[i+2] ^= t ^ u;
            resulttext[i+3] ^= t ^ v;
        }
        
        // Inverse ShiftRows
        inv_shift_rows(resulttext);
        
        // Inverse SubBytes
        for (i = 0; i < 16; ++i) {
            *(resulttext+i) = Inv_sbox[*(resulttext+i)];
        }

        roundkeys -= 16;

    }

    // last AddRoundKey
    for ( i = 0; i < 16; ++i ) {
        *(resulttext+i) ^= *(roundkeys+i);
    }



printf("Decrypted text from bob  :");
  for (int i = 0; i < 16; i++)
    printf("%x ", resulttext[i]);
  printf("\n");



}

// ------------** AES Encyption 128-bit **---------------

uint8_t s_box[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

void ShiftRows(uint8_t *plainText) // We have total 16 values in array(all are 8-bit);
{

  /*
  Shift Rows :
   *  Row0: s0  s4  s8  s12   << 0 byte
   *  Row1: s1  s5  s9  s13   << 1 byte
   *  Row2: s2  s6  s10 s14   << 2 bytes
   *  Row3: s3  s7  s11 s15   << 3 bytes
  [s0 s4 s8 s12 ]                 [s0 s4 s8 s12 ]
  [s1 s5  s9 s13]    ---->        [s5 s9 s13 s1 ]
  [s2 s6 s10 s14]                 [s10 s14 s2 s6]
  [s3 s7 s11 s15]                 [s15 s3 s7 s11]

   */

  uint8_t temp[16];

  temp[0] = plainText[0];
  temp[1] = plainText[5];
  temp[2] = plainText[10];
  temp[3] = plainText[15];
  temp[4] = plainText[4];
  temp[5] = plainText[9];
  temp[6] = plainText[14];
  temp[7] = plainText[3];
  temp[8] = plainText[8];
  temp[9] = plainText[13];
  temp[10] = plainText[2];
  temp[11] = plainText[7];
  temp[12] = plainText[12];
  temp[13] = plainText[1];
  temp[14] = plainText[6];
  temp[15] = plainText[11];

  for (int i = 0; i < 16; i++)
  {
    plainText[i] = temp[i];
  }
}

uint32_t rotward(uint32_t n)
{

  /// if n=b0b1b2b3;
  // then after rotward we should get =b1b2b3b0;

  return ((n << 8) | (n >> 24));
}

uint32_t subword(uint32_t n)
{
  uint32_t b0, b1, b2, b3;

  /// n=k3k2k1k0  (All ki is 8 bit)

  b0 = s_box[(n & 0xFF)]; //0xFF(Hexadecimal)=256 (Decimal)
  b1 = (s_box[((n >> 8) & 0xFF)] << 8);
  b2 = (s_box[((n >> 16) & 0xFF)] << 16);
  b3 = (s_box[((n >> 24) & 0xFF)] << 24);

  return (b3 | b2 | b1 | b0);
}

uint32_t R_Con[10] = {0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x1B000000, 0x36000000};
void Key_Schedule(uint8_t *key, uint8_t *roundkeys)
{

  uint32_t w[44]; /// all 32-bit words .

  for (int i = 0; i < 4; i++)
  {

    w[i] = ((key[4 * i] << 24) | (key[4 * i + 1] << 16) | (key[4 * i + 2] << 8) | (key[4 * i + 3]));
    //printf("%x\n",w[i]);
  }
  uint32_t temp = 0;
  for (int i = 4; i < 44; i++)
  {
    temp = w[i - 1];
    if (i % 4 == 0)
    {

      // temp=(rotward(temp));
      // printf("Rot %x\n",temp);
      //  temp=(subword(temp));
      // printf("sub %x\n",temp);

      temp = ((subword((rotward(temp)))) ^ R_Con[i / 4 - 1]);
      //printf("%x\n",temp);
    }

    w[i] = (w[i - 4] ^ temp);

    //printf("%x\n",w[i]);
  }

  // k0=w0w2w3w4   /// wi is 32 bits and ki=128-bit

  int j = 0, k = 0;
  for (int i = 1; i <= 11; i++)
  {
    while (j < i * 4)
    {
      uint32_t n = w[j];
      uint8_t b0, b1, b2, b3;
      b0 = (n & 0xFF);
      b1 = ((n >> 8) & 0xFF);
      b2 = ((n >> 16) & 0xFF);
      b3 = (n >> 24);

      roundkeys[k] = b3;
      roundkeys[k + 1] = b2;
      roundkeys[k + 2] = b1;
      roundkeys[k + 3] = b0;

      k += 4;

      j++;
    }
  }
}

void print(uint8_t c[])
{

  for (int i = 0; i < 16; i++)
  {
    printf("%x ", c[i]);
  }

  printf("\n");
}

void Aes(uint8_t *plain, uint8_t *key)
{

  uint8_t cipherText[16];
  int local = 0;

  /*

  First  Pass Key to Key Schedule Algo where we get total 11 key all are 128 bit.


  */

  uint8_t roundkeys[176];
  /// if k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10 are get after pass key schedule algo
  ///  k0 contain total 8-bit 16 value same as k1 ,k2 and so  on ...
  /// then we have total (11)*16=176  size array for store all 16 bit value of each 11 keys.

  Key_Schedule(key, roundkeys); /// this create all  11 keys(each keys contain 16 values 8 bits);

  //print(roundkeys);

  /*
  Add  for first Round Key :
    * s1(i, j) := s(i, j) ⊕ k0(i, j)

  */

  for (int i = 0; i < 16; i++, local++)
  {
    //printf("pl: %x roundkeys :%x  ss:%x \n", plain[i], roundkeys[i], ss);
    cipherText[i] = (plain[i] ^ roundkeys[local]);
  }


//**Remove comment for get round keys as well ** //
  // printf("Round 0 : ");
  // for (int i = 0; i < 16; i++)
  //   printf("%x ", cipherText[i]);
  // printf("\n");

  //-------------------------

  /*
    for All 9 rounds
    * subbytes
    * shiftrows
    * mix coloumn
    * Add Round Key

  */

  uint8_t temp[16];

  for (int round = 1; round < 10; round++)
  {

    // sub bytes

    for (int i = 0; i < 16; i++)
      temp[i] = s_box[cipherText[i]];

    // shift rows

    ShiftRows(temp);

    // Mix Column

    for (int i = 0; i < 16; i += 4)
    {

      cipherText[i] = (multiply_x(temp[i]) ^ multiply_x(temp[i + 1]) ^ temp[i + 1] ^ temp[i + 2] ^ temp[i + 3]);     //01123
      cipherText[i + 1] = (multiply_x(temp[i + 1]) ^ multiply_x(temp[i + 2]) ^ temp[i + 2] ^ temp[i + 3] ^ temp[i]); //12230
      cipherText[i + 2] = (multiply_x(temp[i + 2]) ^ multiply_x(temp[i + 3]) ^ temp[i + 3] ^ temp[i + 1] ^ temp[i]); //23301
      cipherText[i + 3] = (multiply_x(temp[i + 3]) ^ multiply_x(temp[i]) ^ temp[i] ^ temp[i + 1] ^ temp[i + 2]);     //30012
    }

    // Add round key

    for (int i = 0; i < 16; i++, local++)
      cipherText[i] ^= roundkeys[local];


//**Remove comment for get round keys as well ** //
    // printf("Round%d : ", round);
    // for (int i = 0; i < 16; i++)
    //   printf("%x ", cipherText[i]);
    // printf("\n");
  }

  /*
    For last round means 10th round
    * subbytes
    * shiftrows
    * Add Round Key

  */

  // subbyte
  for (int i = 0; i < 16; i++)
    cipherText[i] = s_box[cipherText[i]];

  //shiftrows
  ShiftRows(cipherText);

  // Add round key k10.
  for (int i = 0; i < 16; i++)
    cipherText[i] ^= roundkeys[local++];

printf("Encrypted Ciphertext from alice  :");
  for (int i = 0; i < 16; i++)
    printf("%x ", cipherText[i]);
  printf("\n");

 AES_Decryption(roundkeys,cipherText);



// *completed task till  point 12.

}



// ------------** Diffie-Hellman**---------------

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


    ull p=353,g=3,xa,xb;  // p is a prime number and g is primitive root of p
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



int main()
{

 diffie_hellman();  //1
 

}