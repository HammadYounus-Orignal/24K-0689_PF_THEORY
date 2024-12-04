// NAME HAMMAD YOUNUS
// ID   24K-0689




#include <stdio.h>
#include <string.h>

typedef struct
{
    long employeeCode;
    char employeeName[50];
    int dateOfJoining[3];
} Employee;

void assigning_details(Employee employees[], int size);
void tenure_check(Employee employees[], int size);

int main()
{
    Employee employees[4];
    printf("Enter the details of the Employees below\n");
    assigning_details(employees, 4);

    tenure_check(employees, 4);

    return 0;
}

void assigning_details(Employee employees[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Employee %d:\n", i + 1);
        printf("Enter the employee's code: ");
        scanf("%ld", &employees[i].employeeCode);
        getchar(); // Consume the newline left after using scanf()
        printf("Enter the employee's name: ");
        fgets(employees[i].employeeName, 50, stdin);
        employees[i].employeeName[strcspn(employees[i].employeeName, "\n")] = '\0'; // Replacing \n with \0 at the end of the string
        printf("Enter the employee's date of joining (dd-mm-yyyy): ");
        scanf("%d-%d-%d", &employees[i].dateOfJoining[0], &employees[i].dateOfJoining[1], &employees[i].dateOfJoining[2]);
        printf("\n");
    }
}

void tenure_check(Employee employees[], int size)
{
    int current_date[3];
    int count = 0;
    printf("Enter the current date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &current_date[0], &current_date[1], &current_date[2]);

    printf("\nThe employees who have a tenure of more than 3 years are :\n");
    for (int i = 0; i < size; i++)
    {
        int tenure = current_date[2] - employees[i].dateOfJoining[2]; // Calculation for tenure years

        if (current_date[1] < employees[i].dateOfJoining[1])
        { // If the month of the current date is less than date of joining
            tenure--;
        }

        if (current_date[1] == employees[i].dateOfJoining[1] && current_date[0] < employees[i].dateOfJoining[0])
        { // If months are same, but the date of current is less
            tenure--;
        }

        if (tenure > 3)
        {
            count++;
            printf("Employee Code: %ld\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date Of Joining: %d-%d-%d\n", employees[i].dateOfJoining[0], employees[i].dateOfJoining[1], employees[i].dateOfJoining[2]);
            printf("\n");
        }
    }
    printf("The total number of employees who have a tenure of more than 3 years are %d.", count);
}