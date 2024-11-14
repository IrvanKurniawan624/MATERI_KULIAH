#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// FUNCTION
int pjgstr(char[]);
void balikstr(char[]);
void copystr(char[], char[]);

int main()
{
    const int MAKS = 50;
   /// TUGAS 1
       /// TUGAS 1 NO. 2
    //   int panjang_string = 0;
    //   char InputString[MAKS];
    //
    //   printf("Masukkan Input String : ");
    //   fgets(InputString, sizeof(InputString), stdin);
    //   panjang_string = pjgstr(InputString);
    //   printf("\nPanjang String : %d", panjang_string);

       /// TUGAS 1 NO. 3
    //   int panjang_string = 0;
    //   char InputString[MAKS], ReverseInputString[MAKS];
    //
    //   printf("Masukkan Input String : ");
    //   fgets(InputString, sizeof(InputString), stdin);
    //   balikstr(InputString);
    //   printf("\nPembalikkan String : %s", InputString);

       /// TUGAS 1 NO. 4
    //   int panjang_string = 0;
    //   char InputString[MAKS], StringTujuan[MAKS];
    //
    //   printf("Masukkan Input String : ");
    //   fgets(InputString, sizeof(InputString), stdin);
    //   copystr(InputString, StringTujuan);
    //   printf("\nString Asal : %s\nString Tujuan : %s", InputString, StringTujuan);
   /// =======END=======

   /// TUGAS 2
//   char String_1[MAKS], String_2[MAKS];
//   printf("Masukkan String 1 : ");
//   fgets(String_1, sizeof(String_1), stdin);
//   printf("Masukkan String 2 : ");
//   fgets(String_2, sizeof(String_2), stdin);
//   if(strcmp(String_1, String_2) == 0){
//    printf("\nKedua String Sama");
//   } else {
//    printf("\nKedua String Berbeda");
//   }
   /// =======END=======

   /// TUGAS 3
//   char String_1[MAKS], String_2[MAKS];
//   printf("Masukkan String 1 : ");
//   fgets(String_1, sizeof(String_1), stdin);
//   printf("Masukkan String 2 : ");
//   fgets(String_2, sizeof(String_2), stdin);
//   if(strcmpi(String_1, String_2) == 0){
//    printf("\nKedua String Sama");
//   } else {
//    printf("\nKedua String Berbeda");
//   }
   /// =======END=======

   /// TUGAS 4
   char String_1[MAKS], String_2[MAKS];
   printf("Masukkan String 1 : ");
   fgets(String_1, sizeof(String_1), stdin);
   printf("Masukkan String 2 : ");
   fgets(String_2, sizeof(String_2), stdin);
   if(strcmp(String_1, String_2) == 0){
    printf("\nCase Sensitive : Kedua String Sama");
   } else {
    printf("\nCase Sensitive : Kedua String Berbeda");
   }
   if(strcmpi(String_1, String_2) == 0){
    printf("\nNon Case Sensitive : Kedua String Sama");
   } else {
    printf("\nNon Case Sensitive : Kedua String Berbeda");
   }
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


