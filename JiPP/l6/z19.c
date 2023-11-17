
#include <stdio.h>
#include <string.h>

#define MAX_LINE 256
char litery[] = {'a',165,'b','c',134,'d','e',169,'f','g','h','i','j','k','l',136,
                 'm','n',228,'o',162,'p','q','r','s',152,'t','u','v','w','x','y','z',190,1,
        71,'A',164,'B','C',143,'D','E',168,'F','G','H','I','J','K','L',157,'M','N',
        227,'O',224,'P','Q','R','S',151,'T','U','V','W','X','Y','Z',189,141,',',
        '.',',','?',':','-','0','1','2','3','4','5','6','7','8','9','!','\0' };
char *mors[] = { ".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.","...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--",".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.", "...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--"," ",".-.-.-","--..--","..--..","---...","-....-","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","!",0 };

void encode(char *zdanie, char morse[MAX_LINE][8]) {
    int numtab[MAX_LINE];
    int num = 0;
    char znak;
    int i = 0;
    while ((znak = zdanie[i]) != '\0') {

        for (int j = 0; j < 89; j++) {

            if (znak == litery[j]) {
                numtab[num] = j;
                num++;
                break;
            }
        }
        i++;
    }

    int len = 0;
    for (int k = 0; k < num; k++) {
        int pos = numtab[k];
        strcpy(morse[k], mors[pos]);
        len++;
    }

    for (int k = 0; k < num; k++) {
        printf("%s\n", morse[k]); // TODO: wlacz
    }

    printf("\n");

}

void decode(char morse[MAX_LINE][8], char *zdanie) {
    int numTab2[MAX_LINE];
    int num = 0;
    for (int i = 0; i < strlen(zdanie); i++) {
        for (int j = 0; j < 88; j++) {
            if (stricmp(morse[i], mors[j]) == 0) {
                numTab2[num] = j;
                num++;
                break;
            }
        }
    }
    printf("%d\n", num);

    for (int i = 0; i < num; i++) {
        printf("%c", litery[numTab2[i]]);
    }
    printf("\n");
}


int main() {
    char *zdanie = "alamakotaiolamapsa";
    char morse[MAX_LINE][8];
    encode(zdanie, morse);
    decode(morse, zdanie);
    return 0;
}