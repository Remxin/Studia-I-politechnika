

#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    printf("_____ WELCOME to LIFO, FIFO manager _____\n"
           "What structure you want to create:\n"
           "0) LIFO (list)\n"
           "1) LIFO (tab)\n"
           "2) FIFO (list)\n"
           "3) FIFO (tab)\n: ");
}

void showActionMenu() {
    printf("What do you want to do with your structure: \n"
           "0) add new element\n"
           "1) get element\n"
           "2) search for element\n"
           "3) list all elements\n"
           "4) get the length of the list\n"
           "5) delete whole structure\n"
           "6) end the program\n");
}

void showFieldTypeMenu() {
    printf("What field do you want to search in: \n"
           "0) name\n"
           "1) surname\n"
           "2) year of birth\n");
}
void closeMenu() {
    printf("_____ GOODBYE! _____\n");
    exit(0);
}

