// NAME HAMMAD YOUNUS
// ID 24K-0689



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int runtime; 
    char encoding[50];
} ContentMetadata;

typedef struct {
    float resolution;
    int playbackHistory; 
    float bandwidthUsage; 
} DevicePreferences;

double** createEngagementMatrix(int userCount, int categoryCount) {
    double **matrix = (double**)malloc(userCount * sizeof(double*));
    for (int i = 0; i < userCount; i++) {
        matrix[i] = (double*)malloc(categoryCount * sizeof(double));
    }
    return matrix;
}

DevicePreferences*** createDeviceMatrix(int userCount, int deviceCount) {
    DevicePreferences ***matrix = (DevicePreferences***)malloc(userCount * sizeof(DevicePreferences**));
    for (int i = 0; i < userCount; i++) {
        matrix[i] = (DevicePreferences**)malloc(deviceCount * sizeof(DevicePreferences*));
        for (int j = 0; j < deviceCount; j++) {
            matrix[i][j] = (DevicePreferences*)malloc(sizeof(DevicePreferences));
        }
    }
    return matrix;
}

ContentMetadata*** createContentMetadataMatrix(int categoryCount, int contentCount) {
    ContentMetadata ***matrix = (ContentMetadata***)malloc(categoryCount * sizeof(ContentMetadata**));
    for (int i = 0; i < categoryCount; i++) {
        matrix[i] = (ContentMetadata**)malloc(contentCount * sizeof(ContentMetadata*));
        for (int j = 0; j < contentCount; j++) {
            matrix[i][j] = (ContentMetadata*)malloc(sizeof(ContentMetadata));
        }
    }
    return matrix;
}

void freeEngagementMatrix(double **matrix, int userCount) {
    for (int i = 0; i < userCount; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeDeviceMatrix(DevicePreferences ***matrix, int userCount, int deviceCount) {
    for (int i = 0; i < userCount; i++) {
        for (int j = 0; j < deviceCount; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

void freeContentMetadataMatrix(ContentMetadata ***matrix, int categoryCount, int contentCount) {
    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < contentCount; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int userCount, categoryCount, deviceCount, contentCount;
    
    printf("Enter the number of users: ");
    scanf("%d", &userCount);

    printf("Enter the number of content categories: ");
    scanf("%d", &categoryCount);

    printf("Enter the number of devices per user: ");
    scanf("%d", &deviceCount);

    printf("Enter the number of content items per category: ");
    scanf("%d", &contentCount);
    double **engagementMatrix = createEngagementMatrix(userCount, categoryCount);
    DevicePreferences ***deviceMatrix = createDeviceMatrix(userCount, deviceCount);
    ContentMetadata ***contentMetadataMatrix = createContentMetadataMatrix(categoryCount, contentCount);

    for (int i = 0; i < userCount; i++) {
        for (int j = 0; j < categoryCount; j++) {
            printf("Enter engagement score for User %d in Category %d: ", i + 1, j + 1);
            scanf("%lf", &engagementMatrix[i][j]);
        }
    }

    for (int i = 0; i < userCount; i++) {
        for (int j = 0; j < deviceCount; j++) {
            printf("Enter resolution for User %d on Device %d: ", i + 1, j + 1);
            scanf("%f", &deviceMatrix[i][j]->resolution);

            printf("Enter playback history for User %d on Device %d (in minutes): ", i + 1, j + 1);
            scanf("%d", &deviceMatrix[i][j]->playbackHistory);

            printf("Enter bandwidth usage for User %d on Device %d (in Mbps): ", i + 1, j + 1);
            scanf("%f", &deviceMatrix[i][j]->bandwidthUsage);
        }
    }

    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < contentCount; j++) {
            printf("Enter content title for Category %d, Content %d: ", i + 1, j + 1);
            getchar(); 
            fgets(contentMetadataMatrix[i][j]->title, sizeof(contentMetadataMatrix[i][j]->title), stdin);
            contentMetadataMatrix[i][j]->title[strcspn(contentMetadataMatrix[i][j]->title, "\n")] = '\0'; 

            printf("Enter rating for Content %d in Category %d: ", j + 1, i + 1);
            scanf("%f", &contentMetadataMatrix[i][j]->rating);

            printf("Enter runtime (in minutes) for Content %d in Category %d: ", j + 1, i + 1);
            scanf("%d", &contentMetadataMatrix[i][j]->runtime);

            printf("Enter encoding format for Content %d in Category %d: ", j + 1, i + 1);
            getchar();
            fgets(contentMetadataMatrix[i][j]->encoding, sizeof(contentMetadataMatrix[i][j]->encoding), stdin);
            contentMetadataMatrix[i][j]->encoding[strcspn(contentMetadataMatrix[i][j]->encoding, "\n")] = '\0';
        }
    }
    printf("\nDisplaying Engagement Scores, Device Preferences, and Content Metadata:\n");
    for (int i = 0; i < userCount; i++) {
        for (int j = 0; j < categoryCount; j++) {
            printf("User %d, Category %d - Engagement Score: %.2f\n", i + 1, j + 1, engagementMatrix[i][j]);
        }
    }
    for (int i = 0; i < userCount; i++) {
        for (int j = 0; j < deviceCount; j++) {
            printf("User %d, Device %d - Resolution: %.2f, Playback History: %d, Bandwidth Usage: %.2f Mbps\n",
                   i + 1, j + 1, deviceMatrix[i][j]->resolution, deviceMatrix[i][j]->playbackHistory, deviceMatrix[i][j]->bandwidthUsage);
        }
    }
    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < contentCount; j++) {
            printf("Category %d, Content %d - Title: %s, Rating: %.2f, Runtime: %d mins, Encoding: %s\n",
                   i + 1, j + 1, contentMetadataMatrix[i][j]->title, contentMetadataMatrix[i][j]->rating,
                   contentMetadataMatrix[i][j]->runtime, contentMetadataMatrix[i][j]->encoding);
        }
    }
    freeEngagementMatrix(engagementMatrix, userCount);
    freeDeviceMatrix(deviceMatrix, userCount, deviceCount);
    freeContentMetadataMatrix(contentMetadataMatrix, categoryCount, contentCount);

    return 0;
}