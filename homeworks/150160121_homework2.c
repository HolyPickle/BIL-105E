#include <stdio.h>
//Habib Bartu Gökalp
//150160121
int main() {
  int i=1, j=1;
  int a1=0, t1=0, c1=0, g1=0;
  int totalCount;
  int aCount=0, tCount=0, cCount=0, Gcount=0, xCount=0;
  char dna;
  printf("Enter a seq.: ");


  for(i=1 ; i<=25 ; i++){  //Scan 25 character.
    dna = getchar( );

      if(i==1){printf("DNA seq.:     ");}
      if(dna == 'x' || dna == 'X'){        //If char is 'x' break for.
        xCount = 1;
        break;
      }

      if(dna == 'a' || dna == 'A'){          //Count every nucleotide.
          if((a1==0 && t1==0) || a1 < t1){printf("A");aCount++;a1++;
              if(a1==1 && t1==1){a1=0; t1=0;}}
        }

      else if(dna == 't' || dna == 'T'){
          if((t1==0 && a1==0) || t1 < a1){printf("T");tCount++;t1++;
              if(a1==1 && t1==1){a1=0; t1=0;}}
          }

      else if(dna == 'c' || dna == 'C'){
          if((c1==0 && g1==0) || c1 < g1){printf("C");cCount++;c1++;
              if(c1==1 && g1==1){c1=0; g1=0;}}
          }

      else if(dna == 'g' || dna == 'G'){
          if((g1==0 && c1==0) || g1 < c1){printf("G");Gcount++;g1++;
              if(c1==1 && g1==1){c1=0; g1=0;}}
          }
      totalCount = aCount + tCount + cCount + Gcount;   //If there are more than 10 nucleotides break loop.
      if(totalCount == 10){
        break;
      }
      if(dna == '\n'){
          break; }

  } //End for.
  printf("\n");
  if(xCount==1){printf("Terminated!\n");}     //If there is a 'x' print.

  else{
    if(aCount == tCount && cCount == Gcount && aCount!=0 && tCount!=0 && cCount!=0 && Gcount!=0){printf("Healty!\n");}
     //Print healty.

    if(totalCount==0){printf("No data to test!\n");}

    if(aCount != tCount || cCount != Gcount){
      if     (aCount > tCount && cCount == Gcount){printf("Disease: A nucleotide.\n");}   //Find the disease.
      else if(aCount < tCount && cCount == Gcount){printf("Disease: T nucleotide.\n");}
      else if(aCount == tCount && cCount > Gcount){printf("Disease: C nucleotide.\n");}
      else if(aCount == tCount && cCount < Gcount){printf("Disease: G nucleotide.\n");}
      else if(aCount > tCount && cCount > Gcount){printf("Disease: A and C nucleotides.\n");}
      else if(aCount > tCount && cCount < Gcount){printf("Disease: A and G nucleotides.\n");}
      else if(aCount < tCount && cCount > Gcount){printf("Disease: T and C nucleotides.\n");}
      else if(aCount < tCount && cCount < Gcount){printf("Disease: T and G nucleotides.\n");}
      }
    }

  return 0;
} //End main.
