#include<stdio.h>
#include<math.h>
int GCD(int i, int j){
   if(j>i)
      return GCD(j,i);
   if(j==0)
      return i;
   else
      return GCD(j,i%j);
}

int main(){
   int a,b;
   printf("Enter the two integers: ");
   scanf("%d%d",&a,&b);
   printf("GCD of %d and %d is %d",a,b,GCD(a,b));
}
