#include <stdio.h>

void hanoi(int n,char A,char B,char C){
    if (n==0)
        return;
    hanoi(n-1,A,B,C);
    printf("Moved %d from %c to %c \n",n,A,C);
    hanoi(n-1,C,A,B);
}

int main(){
    int n;
    printf("ENter the number of rings!");
    scanf("%d",&n);
    hanoi(n,'f','t','m');
    //f is first rod t is third rod m is middle rod
}
