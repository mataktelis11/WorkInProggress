#include <stdio.h>
#include <stdlib.h>

int main() 
{    
    int c;
    
    
    // declaring string 
    char str[2]; 
      
    // reading string 
    scanf("%s",str); 
      
    
    int x=atoi(str);

    int numbers[x-1];

    for (int i=0;i<x-1;i++){
        
        numbers[i]=i+2;
    }
   
    // for (int j=0;j<x-1;j++){

    //     printf("%d",numbers[j]);
    //     printf("\n");
    // }
 
 

    int center=numbers[0]; 
    int position;
    int counter=0;

//while((center*center)<=x){

for (int j=0;j<x-1;j++){

    for (int j=0;j<x-1;j++){

       if (((numbers[j]%center)==0)&&(numbers[j]!=center)){
           //printf("%d",numbers[j]);
           //printf("\n");
           position=j;
            for (c = position; c < x - 2; c++)
                numbers[c] = numbers[c+1];
       
       if(numbers[j]==x){

           numbers[j]=numbers[0];
       }
       }

       
    }
 
counter+=1;
center=numbers[counter];



}

//}
 
 /*
center=numbers[1]; 
   position;
 
    for (int j=0;j<x-1;j++){

       if (((numbers[j]%center)==0)&&(numbers[j]!=center)){
           printf("%d",numbers[j]);
           printf("\n");
           position=j;
            for (c = position; c < x - 2; c++)
                numbers[c] = numbers[c+1];
       
        if(numbers[j]==x){

           numbers[j]=numbers[0];
       }
       
       
       }
    }

*/


 printf("\n");
// for (int j=0;j<x-1;j++){

//         printf("%d",numbers[j]);
//         printf("\n");
//     }
 



 /*
 int position=5;
 
 for (c = position ; c < x - 1; c++)
             numbers[c] = numbers[c+1];
          printf("Resultant array:\n");
          for (c = 0; c < x - 2; c++)
              printf("%d\n", numbers[c]);
 
 
 
 */
 
 
 
 
 
 
 
 
 /*
int position=0;



int center=numbers[0];
int k=0;

while(center^2<=x){


for (int j=0;j<=x-1;j++){

       if (((numbers[j]%center)==0)&&(numbers[j]!=center)){
           
           position=j;
           printf("%d",position);
           printf("\n");
    
    // for (c = position ; c < x - 1; c++)
    //         numbers[c] = numbers[c+1];
    //     // printf("Resultant array:\n");
    //     // for (c = 0; c < x - 2; c++)
    //     //     printf("%d\n", numbers[c]);
        
        }
    
    }
 

k+=1;
center=numbers[k];

}


for (int j=0;j<=x-2;j++){
    printf("%d\n", numbers[j]);}
 */
int temp=0;

for (int j=0;j<x-1;j++){

    if (x==numbers[j]){printf("prwtos");
    temp=1;
    break;
    }
   
}

if (temp==0){

    printf("not prwtos");
}




    return 0; 
} 
