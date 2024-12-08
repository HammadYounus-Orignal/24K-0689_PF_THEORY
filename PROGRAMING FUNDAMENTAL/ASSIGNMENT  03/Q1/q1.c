//  NAME HAMMAD YOUNUS
//  ID   24K-0689



#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[100];
    char dateOfJoining[11];
};

void assignEmployeeDetails(struct Employee *emp) {
    printf("Enter Employee Code: ");
    scanf("%d", &emp->employeeCode);
    getchar();

    printf("Enter Employee Name: ");
    fgets(emp->employeeName, 100, stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = 0;

    printf("Enter Date of Joining (YYYY-MM-DD): ");
    scanf("%s", emp->dateOfJoining);
}

int calculateTenure(char joiningDate[], int currentYear, int currentMonth, int currentDay) {
    int joiningYear, joiningMonth, joiningDay;
    sscanf(joiningDate, "%d-%d-%d", &joiningYear, &joiningMonth, &joiningDay);

    int years = currentYear - joiningYear;

    if (currentMonth < joiningMonth || (currentMonth == joiningMonth && currentDay < joiningDay)) {
        years--;
    }

    return years;
}

void displayEmployeesWithTenureMoreThanThree(struct Employee employees[], int n, int currentYear, int currentMonth, int currentDay) {
    int count = 0;
    
    printf("\nEmployees with more than 3 years of tenure:\n");
    for (int i = 0; i < n; i++) {
        int tenure = calculateTenure(employees[i].dateOfJoining, currentYear, currentMonth, currentDay);
        
        if (tenure > 3) {
            count++;
            printf("\nEmployee Code: %d\nEmployee Name: %s\nDate of Joining: %s\nTenure: %d years\n", 
                   employees[i].employeeCode, employees[i].employeeName, employees[i].dateOfJoining, tenure);
        }
    }

    printf("\nTotal Employees with tenure more than 3 years: %d\n", count);
}

int main() {
    struct Employee employees[4];
    int currentYear, currentMonth, currentDay;

    printf("Enter current year: ");
    scanf("%d", &currentYear);
    
    printf("Enter current month: ");
    scanf("%d", &currentMonth);
    
    printf("Enter current day: ");
    scanf("%d", &currentDay);

    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        assignEmployeeDetails(&employees[i]);
    }

    displayEmployeesWithTenureMoreThanThree(employees, 4, currentYear, currentMonth, currentDay);

    return 0;
}
