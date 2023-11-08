#include <string.h>
#include <printf.h>

void hanoi(int N, char k_z, char k_do, char k_pomoc) {
    if (N == 0) return;

    hanoi(N-1, k_z, k_pomoc, k_do);
    printf("Przesunieto %d z %c do %c\n", N, k_z, k_do);
    hanoi(N-1, k_pomoc, k_do, k_z);
}



int main() {
    int N = 3;
    hanoi(N, 'A', 'B', 'C');
    return 0;
}
