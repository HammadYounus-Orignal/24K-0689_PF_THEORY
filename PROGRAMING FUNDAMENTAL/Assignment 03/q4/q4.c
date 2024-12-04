// NAME HAMMAD YOUNUS
// ID   24K-0689




#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
    int *ratings;
    int totalScore;
} Employee;

void inputEmployees(int **ratings, int numEmployees, int numPeriods)
{
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Enter the ratings for Employee %d\n", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            printf("Enter the rating for period %d: ", j + 1);
            scanf("%d", &ratings[i][j]);
            while (ratings[i][j] < 1 || ratings[i][j] > 10)
            {
                printf("Invalid rating. Please enter a rating between 1 and 10: ");
                scanf("%d", &ratings[i][j]);
            }
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods)
{
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Employee %d ratings: ", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            printf("Rating for period %d: %d\n",j+1, ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods)
{
    int maxAvgIndex = 0;
    double maxAvg = 0;
    for (int i = 0; i < numEmployees; i++)
    {
        double total = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            total += ratings[i][j];
        }
        double avg = total / numPeriods;
        if (avg > maxAvg)
        {
            maxAvg = avg;
            maxAvgIndex = i;
        }
    }
    return maxAvgIndex;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods)
{
    int maxAvgIndex = 0;
    double maxAvg = 0;
    for (int i = 0; i < numPeriods; i++)
    {
        double total = 0;
        for (int j = 0; j < numEmployees; j++)
        {
            total += ratings[j][i];
        }
        double avg = total / numEmployees;
        if (avg > maxAvg)
        {
            maxAvg = avg;
            maxAvgIndex = i;
        }
    }
    return maxAvgIndex;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods)
{
    int minAvgIndex = 0;
    double minAvg = 10;
    for (int i = 0; i < numEmployees; i++)
    {
        double total = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            total += ratings[i][j];
        }
        double avg = total / numPeriods;
        if (avg < minAvg)
        {
            minAvg = avg;
            minAvgIndex = i;
        }
    }
    return minAvgIndex;
}

int main()
{
    int numEmployees, numPeriods;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int **ratings = (int **)malloc(numEmployees * sizeof(int *));
    for (int i = 0; i < numEmployees; i++)
    {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the year: %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest rated period: %d\n", highestRatedPeriod + 1);

    int worstPerformingEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst performing employee: %d\n", worstPerformingEmployee + 1);

    for (int i = 0; i < numEmployees; i++)
    {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}