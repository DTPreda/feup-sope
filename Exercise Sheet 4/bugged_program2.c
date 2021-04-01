#include <stdio.h>
#include <string.h>

void foo(char *bar)
{
   char c[15];
   gets(c);

   strcpy(bar, c);  // no bounds checking
}

int main(void) {
    //printf("%p", trainwreck);
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");

    foo(buff);

    if(strcmp(buff, "thegeekstuff")) {
        printf ("\n Wrong Password. \n");
    } else {
        printf ("\n Correct Password.\n");
        pass = 1;
    }

    if (pass) {  // do something priviledged stuff
        printf ("\n Root privileges given to the user.\n");
    }
    
    return 0;
}