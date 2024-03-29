#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#define USERDEF 135

typedef void (*funcp)();

typedef struct f {
    char c1;
    double d;
    char c2;
} mystruct;

char msg[] = \
"This insecure menu system takes a numeric input as an index to a function\n\
a function table, only it doesn't validate the user's input to ensure it\n\
doesn't exceed the size of the table.  To solve this level, find the index\n\
that will go beyond the array of mystructs and invoke the function that\n\
is passed in as an argument.  To make this level easier, we have included\n\
the source code used to generate your binary.\n\n";

void print_msg() {
        printf("%s",msg);
}

void segv_handler(int sig) {
        printf("Segmentation fault.  Try again.\n");
        exit(0);
}

void print_good() {
    printf("Good Job.\n");
    exit(0);
}

void print_nogood() {
    printf("Try again.\n");
}
void print_helloworld() {
    printf("Hello world.\n");
}
void print_nosoup () {
    printf("No soup for you.\n");
}
void try_command() {
    int i;
    mystruct m[USERDEF];
    funcp f[3] = {print_nogood, print_helloworld, print_nosoup};
    printf("The password is the command to execute (0=nogood, 1=helloworld, 2=nosoup)\n");
    printf("Enter the password: ");
    sleep(2);
    scanf("%d",&i);
    f[i]();
}

main() {
    funcp fg=print_good;
    signal(SIGSEGV, segv_handler);
    print_msg();
    try_command();
    print_nogood();
    return 0;
}
