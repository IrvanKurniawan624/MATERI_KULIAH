#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// FUNCTION
int pjgstr(char[]);
void balikstr(char[]);
void copystr(char[], char[]);

int main()
{
   /// TUGAS 1
//   char ContohString[15];
//   printf("Masukkan Input String : ");
//
//   //gets(ContohString);
//    // Tidak ada batasan panjang input, sehingga sangat mudah menyebabkan buffer overflow dan serangan keamanan (Tidak Direkomendasikan)
//
//   //scanf("%s", ContohString);
//    // Tidak dapat membaca spasi | Rentan buffer overflow (Conditional)
//
//   //fgets(ContohString, sizeof(ContohString), stdin);
//    // Rekomendasi
//   printf("\nOutput : %s", ContohString);
   /// =======END=======

   /// TUGAS 2
//   const int MAKS = 50;
//   int panjang_string = 0;
//   char InputString[MAKS];
//
//   printf("Masukkan Input String : ");
//   fgets(InputString, sizeof(InputString), stdin);
//   panjang_string = pjgstr(InputString);
//   printf("\nPanjang String : %d", panjang_string);
   /// =======END=======

   /// TUGAS 3
//   const int MAKS = 50;
//   int panjang_string = 0;
//   char InputString[MAKS], ReverseInputString[MAKS];
//
//   printf("Masukkan Input String : ");
//   fgets(InputString, sizeof(InputString), stdin);
//   balikstr(InputString);
//   printf("\nPembalikkan String : %s", InputString);
   /// =======END=======

   /// TUGAS 4
   const int MAKS = 50;
   int panjang_string = 0;
   char InputString[MAKS], StringTujuan[MAKS];

   printf("Masukkan Input String : ");
   fgets(InputString, sizeof(InputString), stdin);
   copystr(InputString, StringTujuan);
   printf("\nString Asal : %s\nString Tujuan : %s", InputString, StringTujuan);
   /// =======END=======

}

int pjgstr(char String[]){
    int length = strlen(String);
    // Menghilangkan \n pada newline
    length--;
    return length;
}

void balikstr(char String[]){
    strrev(String);
}

void copystr(char StringAsal[], char StringTujuan[]){
    strcpy(StringTujuan, StringAsal);
}


