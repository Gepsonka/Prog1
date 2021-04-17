#include <stdio.h>
#include <string.h>


void prt(char* p, int x){
    printf("p is \"%s\" and x is %d\n",p,x);
}


int main(){

    char x[100]="Hello";
    char y[]="world!";

    

    strcat(x," ");
    strcat(x,y);

    printf("%s\n",x);

    char for_print[]="F4U corsair";
    char for_print2[]="P51 mustang";
    char for_print3[]="Suparmarine Spitfire";

    prt(for_print, 123);


}