#include <stdio.h>
#include <cs50.h>
#include <math.h>


void digit_extract(long card_number);
long length(long n1);
long digit(long n2, int t);
int sum_of_digits(long num);
long long divisor = 1;
long dig,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
long r,u, length_card, total_sum;
bool checksum(void);

int main(void)
{  
    printf("Number:");
    long card_number = get_long_long();
    digit_extract(card_number);
    length_card = length(card_number) +1;
    bool x = checksum();
    if(x == true)
    {
       if((p == 4 && length_card == 16 )|| (m==4 &&length_card == 13))
       {
           printf("VISA\n");
       }
       else if(o == 3&&length_card==15&&(n==7||n==4))
       {
           printf("AMEX\n");
       }
       else if(p==5 && length_card==16 && (o==1 || o==2 || o==3 || o==4 || o==5))
       {
           printf("MASTERCARD\n");
       }
       else
       {
           printf("INVALID\n");
       }
    }
    else
    {
        printf("INVALID\n");
    }
    
}
long length(long n1)
{
    if(n1 >= 10)
    {
        r = r + 1;
        u= round(n1/10);
        length(u);
    }
     return r ;
}


void digit_extract(long card_number)
{
     a = digit(card_number, 1);
     b = digit(card_number, 2);
     c = digit(card_number, 3);
     d = digit(card_number, 4);
     e = digit(card_number, 5);
     f = digit(card_number, 6);
     g = digit(card_number, 7);
     h = digit(card_number, 8);
     i = digit(card_number, 9);
     j = digit(card_number, 10);
     k = digit(card_number, 11);
     l = digit(card_number, 12);
     m = digit(card_number, 13);
     n = digit(card_number, 14);
     o = digit(card_number, 15);
     p = digit(card_number, 16);
}
long digit(long n2, int t)
{   for(int y=1; y<t; y++)
        {
            divisor = divisor*10;
        }
    dig = (n2 / divisor) % 10;
    divisor = 1;
    return dig;
}
bool checksum(void)
{
    total_sum = 
     sum_of_digits(a) +sum_of_digits(2*b) 
    +sum_of_digits(c) +sum_of_digits(2*d) 
    +sum_of_digits(e) +sum_of_digits(2*f)
    +sum_of_digits(g) +sum_of_digits(2*h) 
    +sum_of_digits(i) +sum_of_digits(2*j)
    +sum_of_digits(k) +sum_of_digits(2*l) 
    +sum_of_digits(m) +sum_of_digits(2*n) 
    +sum_of_digits(o) +sum_of_digits(2*p);
    
    int remaind = total_sum % 10;
    if( remaind == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int sum_of_digits(long num)
{
    return digit(num, 1) + digit(num, 2);
}