//  NAME HAMMAD YOUNUS
//  ID   24K-0689




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    if (email == NULL || strlen(email) == 0) {
        return 0; // Empty email
    }
    
    int atCount = 0;
    int dotAfterAt = 0;
    
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            if (atCount == 1) {
                dotAfterAt = 1;
            }
        }
    }

    return (atCount == 1 && dotAfterAt == 1);
}

int main() {
    char *email = NULL;
    size_t length = 0;
    
    printf("Enter your email address: ");
    getline(&email, &length, stdin);
    
    // Remove the newline character at the end if present
    email[strcspn(email, "\n")] = 0;
    
    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }
    
    // Free dynamically allocated memory
    free(email);

    return 0;
}
