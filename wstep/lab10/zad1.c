#include<stdio.h>
int main (){
int x;
int *wsk;
wsk = &x;
x = 100;
printf("oto wartość x : %d",x);
*wsk = 5;
printf("oto wartość x : %d",x);
return 0;
}
