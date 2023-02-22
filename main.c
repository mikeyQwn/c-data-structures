#include "lib/i_linked_list.h"
#include <stdio.h>
#include <string.h>

int getHash(char *string) {
    unsigned long result = 543;
    for (int i = 0; i < strlen(string); ++i) {
        result = (result << 6) + result + (int)string[i];
    }
    return result;
}

int main(void) {
    printf("%u\n", getHash((char *)"2380918293"));
    return 0;
}
