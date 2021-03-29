#include<stdio.h>
#include<stdlib.h>
#include<time.h>


 int main(int argc, char const *argv[]) {

int number=1;
srand(time(0));
int n=(rand()%100)+1  ; //1----100

int num;
printf("Enter the Your Guess number Between 1 to 100 \n");
do
{


scanf("%d",&num);
if(num>n)
printf(" Please Enter the lower number !! \n");
else if(num<n)
printf(" Please Enter the higher number !! \n");
else
{

  printf(" Yes !! You guessed \n");
  printf(" You guess in  %d ",number);
  printf(" attempts !! \n");
}


number++;
}while(n!=num);


return 0;
}