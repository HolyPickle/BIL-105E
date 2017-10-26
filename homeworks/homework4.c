#include <stdio.h>
#include <math.h>
#define PI 3.14159265
//Habib Bartu Gökalp
//150160121

float basis[2][2]={{1,0},{0,1}};
float coordinates[1][2]={{0},{0}};
float geciciKume[2][2];
float radyan;
int i,j;
char mod;
int move[1][2];
int basis1, basis2, basis3, basis4;
float derece;

void moveVector(){
  scanf("%d %d", &move[0][0], &move[0][1]);
  coordinates[0][0] += basis[0][0]*move[0][0] + basis[0][1]*move[0][1];  //matix multiplication
  coordinates[0][1] += basis[1][0]*move[0][0] + basis[1][1]*move[0][1];
}

void changeBasis(){
  scanf("%d %d %d %d", &basis1, &basis2, &basis3, &basis4);
  basis[0][0] = basis1;
  basis[0][1] = basis2;
  basis[1][0] = basis3;
  basis[1][1] = basis4;
}

void rotateL(){
  scanf("%f", &derece);
  radyan = (derece/180.0)*PI;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      geciciKume[i][j] = basis[i][j];
    }
  }
  basis[0][0] = geciciKume[0][0]*cos(radyan) + geciciKume[0][1]*sin(radyan);
  basis[0][1] = -geciciKume[0][0]*sin(radyan) + geciciKume[0][1]*cos(radyan);
  basis[1][0] = geciciKume[1][0]*cos(radyan) + geciciKume[1][1]*sin(radyan);
  basis[1][1] = -geciciKume[1][0]*sin(radyan) + geciciKume[1][1]*cos(radyan);
}

void rotateR(){
  scanf("%f", &derece);
  radyan = (derece/180.0)*PI;
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      geciciKume[i][j] = basis[i][j];
    }
  }
  basis[0][0] = geciciKume[0][0]*cos(radyan) - geciciKume[0][1]*sin(radyan);
  basis[0][1] = geciciKume[0][0]*sin(radyan) + geciciKume[0][1]*cos(radyan);
  basis[1][0] = geciciKume[1][0]*cos(radyan) - geciciKume[1][1]*sin(radyan);
  basis[1][1] = geciciKume[1][0]*sin(radyan) + geciciKume[1][1]*cos(radyan);
}

void dig(){
  printf("Coordinates: %.2f %.2f\n", coordinates[0][0], coordinates[0][1]);
}




int main(){
    for(i=0;;i++){
      scanf("%c", &mod);

      if(mod=='m'){ //move
        moveVector();
      }
      if(mod=='c'){ //change basis
        changeBasis();
      }
      if(mod=='l'){ //rotate Left
        rotateL();
      }
      if(mod=='r'){ //rotate Right
        rotateR();
      }
      if(mod=='d'){  //DIG
        dig();
        break;
      }
    } //end for
    return 0;
  }
