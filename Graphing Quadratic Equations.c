#include <stdio.h>

void graph_coefficient(int a, int b, int c){
  FILE *graph;
  graph = fopen("coefficients.txt","w");
  fprintf(graph,"%d\n",a);
  fprintf(graph,"%d\n",b);
  fprintf(graph,"%d\n",c);
  fclose(graph);
  printf("coefficients.txt file has been created.\n");
}

void draw(int a,int b,int c){

for(int y=15; y >= -15; y--){
     for(int x= -55; x<=55;x++){
            if(x == 0 && y != 0 )
                printf("|") ;
            if(x == -1 && y % 5==0 && y != 0){
                printf("\033[33m");
                printf("\b\b\b%3d", y);
                printf("\033[0m");}
             if(y == 0 && x != 0 ){
                printf("-");
             }
            if(y == -1 && x == 0) printf("\b|");
            if(y == - 1 && x % 10 == 0 && x != 0){

                    printf("\033[33m");
                    printf("\b\b%3d", x ) ;
                    printf("\033[0m");
            }
            else if(y == -1 && x == -1) printf("0");
            else if(( x == (a*y*y + b*y + c))){
              
              if(y != 0){
             printf("\033[34m");
              printf("\b#");
              printf("\033[0m");}
              else{
              printf("#");
              printf("\033[0;34m");
              printf("\b#");
              printf("\033[0m");
            }
            }
            else if(y != 0 && x != 10  )
                printf(" ");
 } printf("\n") ;}
}




int main(){
int num;

    int a,b,c;
    FILE *graph;
  do{
    printf("select an operation... \n");
    printf("0 ->enter the coefficients.\n");
    printf("1 -> draw the graph. \n");
    printf("2 -> print the graph into a .txt file.\n");
    printf("3 -> exit.\n");
    
    printf("choice: ");
    scanf("%d",&num);
    switch(num){
        
     case 0:
        printf ("please enter the coefficient for the following equation: x=a*y*y+b*y+c\n");
        printf("a: ");
        scanf("%d",&a);
        printf("b: ");
        scanf("%d",&b);
        printf("c: ");
        scanf("%d",&c);
        graph_coefficient(a, b, c);
    break;
     case 1:
     
 if(graph ==NULL){
  printf("No file");}
  else{ 
  graph = fopen("coefficients.txt","r");
  fscanf(graph,"%d ",&a);
  fscanf(graph,"%d ",&b);
  fscanf(graph,"%d ",&c);
  fclose(graph);
          draw(a,b,c);
          }
      break;
      case 2:
      break;
      case 3:
      break;
      default:
          printf("You can select only 1,2,3 or 4\n");
          printf("Please select again!\n");
      break;

    }

  }while(num != 3);


return 0;
}
