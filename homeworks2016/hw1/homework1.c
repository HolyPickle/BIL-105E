#include <stdio.h>
/*
Habib Bartu GOKALP
150160121
*/
int main() {
  int num;
  int primenum = 2;
  int j = 0;
  printf("Enter a number:  ");
  scanf("%d", &num);
  while(num < 2){         //While number smaller than 2,the program wants a valid number
    printf("Enter a valid number:  ");
    scanf("%d", &num );
  } //End while
  printf("Prime factorization of %d: ",num);
  while(num >= 2) {       //While number is valid, program divise the number what times it possible
    if (num % primenum == 0) {
      num = num / primenum;
      j++;
    }
    else {
      if(j != 0){printf("%d^%d ",primenum ,j);}   //If division is not valid, print the primenum
      if(j > 0) {printf("* ");}                   //Print *
      primenum++;
      j = 0;}
    } // End while
  if(j != 0) {printf("%d^%d ",primenum ,j);}      //Print last primenum
printf("\n");
return 0;
} //End main
