// NAME HAMMAD YOUNUS
// ID   24K-0689





#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validateEmail(char *email);

int main()
{
    int length = 50;
    char *email;
    email = (char *) malloc(length * sizeof(char));

    if (email == NULL)
    {
        printf("Error! Memory not allocated.");
        return 1;
    }

    printf("Enter your email address: ");
    fgets(email, length, stdin);
    email[strcspn(email, "\n")] = '\0';

    if (validateEmail(email))
    {
        printf("Valid Email.\n");
    }
    else
    {
        printf("Invalid Email.\n");
    }

    free(email);
    return 0;
}

int validateEmail(char *email)
{
    if (email == NULL || strlen(email) == 0 || strcmp(email, " ") == 0)
    {
        return 0;
    }

    int count_at = 0, count_dot = 0;
    for (int i = 0; *(email + i) != '\0'; i++)
    {
        if (*(email + i) == '@')
        {
            count_at++;
        }
        else if (*(email + i) == '.' && count_at > 0)
        {
            count_dot++;
        }
    }

    if (count_at == 1 && count_dot >= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}