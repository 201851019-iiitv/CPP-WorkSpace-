#include<stdio.h>
#include <stdint.h>

uint8_t plaintext[16]={0};



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




//taking xor of MACB = (MB ⊕ KB).

void MB_KB(uint8_t *keyV)
{

uint8_t MACB[16];
for(int i=0;i<16;i++)
{

MACB[i]=plaintext[i]^keyV[i];


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
        *(plaintext+i) = *(ciphertext+i) ^ *(roundkeys+i);
    }
    roundkeys -= 16;
    inv_shift_rows(plaintext);
    for (i = 0; i < 16; ++i) {
        *(plaintext+i) = Inv_sbox[*(plaintext+i)];
    }

    for (j = 1; j < 10; ++j) {
        
        // Inverse AddRoundKey
        for ( i = 0; i < 16; ++i ) {
            *(tmp+i) = *(plaintext+i) ^ *(roundkeys+i);
        }
        
        for (i = 0; i < 16; i+=4) {
            t = tmp[i] ^ tmp[i+1] ^ tmp[i+2] ^ tmp[i+3];
            plaintext[i]   = t ^ tmp[i]   ^ multiply_x(tmp[i]   ^ tmp[i+1]);
            plaintext[i+1] = t ^ tmp[i+1] ^ multiply_x(tmp[i+1] ^ tmp[i+2]);
            plaintext[i+2] = t ^ tmp[i+2] ^ multiply_x(tmp[i+2] ^ tmp[i+3]);
            plaintext[i+3] = t ^ tmp[i+3] ^ multiply_x(tmp[i+3] ^ tmp[i]);
            u = multiply_x(multiply_x(tmp[i]   ^ tmp[i+2]));
            v = multiply_x(multiply_x(tmp[i+1] ^ tmp[i+3]));
            t = multiply_x(u ^ v);
            plaintext[i]   ^= t ^ u;
            plaintext[i+1] ^= t ^ v;
            plaintext[i+2] ^= t ^ u;
            plaintext[i+3] ^= t ^ v;
        }
        
        // Inverse ShiftRows
        inv_shift_rows(plaintext);
        
        // Inverse SubBytes
        for (i = 0; i < 16; ++i) {
            *(plaintext+i) = Inv_sbox[*(plaintext+i)];
        }

        roundkeys -= 16;

    }

    // last AddRoundKey
    for ( i = 0; i < 16; ++i ) {
        *(plaintext+i) ^= *(roundkeys+i);
    }



printf("Decrypted text from bob  :");
  for (int i = 0; i < 16; i++)
    printf("%x ", plaintext[i]);
  printf("\n");



}