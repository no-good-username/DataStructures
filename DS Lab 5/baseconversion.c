
#include <stdio.h>


int bin(int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 * bin(decimal_number / 2));
}

int dec_hex(int no){
    int hex=0;
    if(!no)
        return;
    else {
        hex=no%16;
        dec_hex(no/16);
    }
    if(hex>9)
        printf("%c",'A'+(hex-10));
    else
        printf("%d",hex);
    }

int dec_octa(int n){
    if(n > 0){
        dec_octa(n/8);

        printf("%d",n%8);
    }
}

int main()
{
    int decimal_number;
    int m=1;
    while(m){
        printf("1.Decimal to Binary. \n2.Decimal to Hexadecimal\n3.Decimal to octa\n");
        scanf("%d",&m);
        switch (m)
        {
        case 1:
            printf("Enter the decimal Number");
            scanf("%d",&decimal_number);
            int p = bin(decimal_number);
            printf("%d\n", p);
            break;
        case 2:
            printf("Enter the decimal Number");
            scanf("%d",&decimal_number);
            printf("%d\n",dec_hex(decimal_number));
            break;
        case 3:
            printf("Enter the decimal Number");
            scanf("%d",&decimal_number);
            printf("%d",dec_octa(decimal_number));
            break;
        }
    }
    return 0;
}
