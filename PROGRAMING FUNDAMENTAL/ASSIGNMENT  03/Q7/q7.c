// NAME HAMMAD YOUNUS
// ID   24K-0689






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ENCODING_FORMAT 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rating;
    int runtime;
    char encoding_format[MAX_ENCODING_FORMAT];
} ContentMetadata;

void initializeEngagementMatrix(double** matrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

void initializeDeviceMatrix(double** matrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

void initializeContentMetadata(ContentMetadata** matrix, int numCategories, int numContent) {
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContent; j++) {
            strcpy(matrix[i][j].title, "");
            matrix[i][j].rating = 0.0;
            matrix[i][j].runtime = 0;
            strcpy(matrix[i][j].encoding_format, "");
        }
    }
}

void freeEngagementMatrix(double** matrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeDeviceMatrix(double** matrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeContentMetadata(ContentMetadata** matrix, int numCategories) {
    for (int i = 0; i < numCategories; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int numUsers, numCategories, numDevices, numContent;
    double** engagementMatrix;
    double** deviceMatrix;
    ContentMetadata** contentMatrix;

    printf("Enter number of users: ");
    scanf("%d", &numUsers);
    printf("Enter number of categories (e.g., Action, Drama, Comedy): ");
    scanf("%d", &numCategories);
    printf("Enter number of devices per user (e.g., smart TV, laptop, phone): ");
    scanf("%d", &numDevices);
    printf("Enter number of content items per category: ");
    scanf("%d", &numContent);

    engagementMatrix = malloc(numUsers * sizeof(double*));
    deviceMatrix = malloc(numUsers * sizeof(double*));
    contentMatrix = malloc(numCategories * sizeof(ContentMetadata*));

    for (int i = 0; i < numUsers; i++) {
        engagementMatrix[i] = malloc(numCategories * sizeof(double));
    }

    for (int i = 0; i < numUsers; i++) {
        deviceMatrix[i] = malloc(numDevices * sizeof(double));
    }

    for (int i = 0; i < numCategories; i++) {
        contentMatrix[i] = malloc(numContent * sizeof(ContentMetadata));
    }

    initializeEngagementMatrix(engagementMatrix, numUsers, numCategories);
    initializeDeviceMatrix(deviceMatrix, numUsers, numDevices);
    initializeContentMetadata(contentMatrix, numCategories, numContent);

    engagementMatrix[0][1] = 8.5;

    deviceMatrix[0][0] = 1080.0;

    strcpy(contentMatrix[0][0].title, "Inception");
    contentMatrix[0][0].rating = 8.8;
    contentMatrix[0][0].runtime = 148;
    strcpy(contentMatrix[0][0].encoding_format, "H.264");

    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDeviceMatrix(deviceMatrix, numUsers);
    freeContentMetadata(contentMatrix, numCategories);

    return 0;
}
