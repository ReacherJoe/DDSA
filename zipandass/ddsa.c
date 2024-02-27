#include "stdio.h"
int a=10;
int main(){

    for (int i = 0; i < a; i++)
    {
        for (int j =0 ; j<=a-i ; j++){
            printf(" ");
        }
        for (int x=0 ; x<i*2-1; x++){
            printf("*");
        }
       
         for (int j =0 ; j<=a-i ; j++){
            printf(" ");
        }
          for (int j =0 ; j<=a-i ; j++){
            printf(" ");
        }
        for (int x=0 ; x<i*2-1; x++){
            printf("*");
        }


        printf("\n");
    }
   
        
       
    
    




    return 0;
}