#include <stdio.h>
#include <stdlib.h>
//Habib Bartu Gökalp
//150160121
//homework5
void decryptNumber(char *number){ //decrypting number
  int i, j;
  char *transNumber;
  transNumber = (char *) malloc(6);

  *transNumber     = *(number+3); //numaranın değişecek elemanlarını transpoz kümesine alır
  *(transNumber+1) = *(number+6);
  *(transNumber+2) = *(number+1);
  *(transNumber+3) = *(number+7);
  *(transNumber+4) = *(number+2);
  *(transNumber+5) = *(number+5);

  *(number+1) = *transNumber;    //transpoze edilmis elemanları tekrar numaraya aktarır
  *(number+2) = *(transNumber+1);
  *(number+3) = *(transNumber+2);
  *(number+5) = *(transNumber+3);
  *(number+6) = *(transNumber+4);
  *(number+7) = *(transNumber+5);

    printf("Number: ");

    for(i=0;i<9;i++){
      printf("%c", *(number+i));
    }
  }

void decryptName(char *name, int *modP, int *modifierP){   //mode göre ismi düzenler
  int i;
  char *newName;
  newName = (char *) malloc(10);


  if(*modP == 0){  //mod = 0 isim aynı kalır
    for(i=0;i<10;i++){
      *(newName+i) = *(name+i);
    }
  }
  if(*modP == 1){  //mod = 1 isimdeki harfler modifier kadar geri sarılır
    for(i=0;i<10;i++){
      *(newName+i) = *(name+i) - *modifierP;
      if(*(newName+i) < 97){
        *(newName+i) += 26;
      }
    }
  }
  if(*modP== 2){  //mod = 2 isimdeki harfler modifier kadar ileri sarılır
    for(i=0;i<10;i++){
      *(newName+i) = *(name+i) + *modifierP;
      if(*(newName+i) > 122){
        *(newName+i) -= 26;
      }
    }
  }
  if(*modP == 3){  //mod = 3 isim tersten yazılır
    int j=0;
    for(i=0;i<10;i++){
      *(newName+i) = *(name+9-j);
      j++;
    }
  }
  printf("Name: ");
  for(i=0;i<10;i++){
    printf("%c", *(newName+i));
  }
}
void decryptAuxliaries(char *name, char *ayar ,int *modP, int *modifierP){ //mod ve modifier alınır

  *modP = 2 * (*ayar-48) + (*(ayar+1)-48);
  *modifierP = 4 * (*(ayar+2)-48) + 2 * (*(ayar+3)-48) + (*(ayar+4)-48);

}

int checkCorruption(char *name, char *number, char *ayar){ //input kontrol edilir geçersiz eleman varsa çalışmaz
  int i;

  for(i=0;i<10;i++){
    if(*(name+i) > 'z' || *(name+i) < 'a'){return 1;} //isimde büyük harf, sayı ve özel karakter bulunmamalı
  }
  for(i=0;i<9;i++){
    if(*(number+i) > '9' || *(number+i) < '0'){return 1;} //numarada harf ve özel karakter bulunmamalı
  }
  for(i=0;i<5;i++){
    if(*(ayar+i) != '1' && *(ayar+i) != '0'){return 1;} //ayarda 1 ve 0 haricinde eleman bulunmamalı
  }

  return 0;
}

int main(){

  char *name;
  name = (char *) malloc(10);
  char *number;
  number = (char *) malloc(9);
  char *ayar;
  ayar = (char *) malloc(5);
  int i, mod, modifier;

  printf("Enter the line to decrypt:");

  for(i=0;i<10;i++){
    scanf("%c", (name+i));
  }
  for(i=0;i<9;i++){
    scanf("%c", (number+i));
  }
  for(i=0;i<5;i++){
    scanf("%c", (ayar+i));
  }
  if(checkCorruption(name, number, ayar) == 1){
    printf("Data is corrupted\n");
    return 0;
  }
  else{
    printf("Decrypted ---\n");
    decryptAuxliaries(name,ayar,&mod,&modifier);
    decryptName(name, &mod, &modifier);
    printf("\n");
    decryptNumber(number);
    printf("\n");
    printf("Mode: %d\n", mod);
    printf("Modifier: %d\n", modifier);
    return 0;
  }
}
