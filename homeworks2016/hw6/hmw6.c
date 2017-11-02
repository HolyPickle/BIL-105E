#include <stdio.h>
#include <string.h>

struct filmbilgileri {
  char name[40];
  char year[4];
  char country[15];
  char rating[4];
  char book[3];
}film[100];

struct kitapbilgileri {
  char name[40];
  char author[30];
  char year[4];
}kitap[100];

int main(){
  int i,j,k;
  int selection=0;
  char input[100];
  char kontrol;
  char arama[5];

  printf("Welcome to film Database!\n");
  while(1){
    printf("Which action do you want:\n");
    printf("1-Insert a film\n");
    printf("2- Search a film\n");
    printf("3- Recommend top films\n");
    printf("4- Exit\n");

    scanf("%d", &selection);

    if(selection == 1){
          for(j=0;j<100;j++){
            printf("Insert a film with its details (for exit please enter -1):");
            for(i=0;i<40;i++){
              kontrol = getchar();
              if(kontrol == '-'){j=101;i=41;getchar();}
              if(kontrol != ',' && kontrol != '-'){film[j].name[i] = kontrol;}
              else break;
            }
            if(j == 101) break;
            for(i=0;i<4;i++){
              kontrol = getchar();
              if(kontrol != ',' && kontrol == '\n'){film[j].year[i] = kontrol;}
              else break;
            }
            for(i=0;i<15;i++){
              kontrol = getchar();
              if(kontrol != ',' && kontrol == '\n'){film[j].country[i] = kontrol;}
              else break;
            }
            for(i=0;i<4;i++){
              kontrol = getchar();
              if(kontrol != ',' && kontrol == '\n'){film[j].rating[i] = kontrol;}
              else break;
            }
            for(i=0;i<3;i++){
              kontrol = getchar();
              if(kontrol != ',' && kontrol == '\n'){film[j].book[i] = kontrol;}
              else break;
          }

          if(film[j].book[0] == 'y' || film[j].book[i] == 'Y'){
            for(i=0;i<40;i++){
              kontrol = getchar();
              if(kontrol != ',' && kontrol == '\n'){kitap[k].name[i] = kontrol;}
              else break;
          }
            for(i=0;i<30;i++){
              kontrol = getchar();
              if(kontrol != ',' && kontrol == '\n'){kitap[k].author[i] = kontrol;}
              else break;
            }
            for(i=0;i<4;i++){
              kontrol = getchar();
              if(kontrol != ',' && kontrol == '\n'){kitap[k].year[i] = kontrol;}
              else break;
            }
          }
          k++;
        }
      }
      if(selection == 2){
        printf("Please Enter at least 3 characters for searching the database:");
        for(i=0;i<5;i++){
          scanf("%c", &kontrol);
          if(kontrol != '\n'){arama[i] = kontrol;}

        }
        for(i=0;i<100;i++){
          for(j=0;j<40;j++){
            if(film[i].name[j] == arama[0] && film[i].name[j+1] == arama[1] && film[i].name[j+2] == arama[2]
                && film[i].name[j+3] == arama[3] && film[i].name[j+4] == arama[4])
                {printf("%s\n", film[i].name);}
          }
        }
        selection = 0;
      }
      if(selection == 3){

      }
      if(selection == 4){
        printf("Goodbye\n");
        break;
      }
    }


  return 0;
}
