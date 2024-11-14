// NAME HAMMAD YOUNUS
// ID   24K-0689



#include <stdio.h>

int match(int n) {
    if (n % 5 == 0) {
        return -1;
    } else {
        return n % 5;
    }
}

int main() { 
    int n;
    printf("Please enter the number of matches: ");
    scanf("%d", &n);
    
    int result = match(n);
    
    if (result == -1) {
        printf("Output: -1\n");
    } else {
        printf("A should take %d matchstick(s).\n", result);
    }
}