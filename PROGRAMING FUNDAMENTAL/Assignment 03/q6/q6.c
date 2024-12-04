// NAME HAMMAD YOUNUS
// ID 24K-0689






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

typedef struct {
    char cropType[30];
    char growthStage[30];
    float expectedYield;
    WeatherForecast *weather;
} Crop;

typedef struct {
    char equipmentType[30];
    char operationalStatus[20];
    float fuelLevel;
    char activitySchedule[50];
} Equipment;

typedef struct {
    float soilNutrients;
    float pHLevel;
    int pestActivity;
} Sensor;

typedef struct {
    float gpsCoordinates[2];
    float soilHealthMetrics;
    float moistureLevel;
    Crop **crops;
    int cropCount;
    Equipment **equipment;
    int equipmentCount;
    Sensor **sensors;
    int sensorCount;
} Field;

Field *createField();
Crop *createCrop();
Equipment *createEquipment();
Sensor *createSensor();
void displayField(Field *field);
void freeField(Field *field);

int main() {
    Field *fields[MAX_FIELDS] = {NULL};
    int fieldCount = 0;
    int choice;

    while (1) {
        printf("\n--- Agritech System Menu ---\n");
        printf("1. Add Field\n");
        printf("2. Add Crop to a Field\n");
        printf("3. Add Equipment to a Field\n");
        printf("4. Add Sensor to a Field\n");
        printf("5. Display All Fields\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (fieldCount < MAX_FIELDS) {
                    fields[fieldCount++] = createField();
                } else {
                    printf("Maximum field limit reached!\n");
                }
                break;
            case 2: {
                int index;
                printf("Enter field index (0 to %d): ", fieldCount - 1);
                scanf("%d", &index);
                if (index >= 0 && index < fieldCount) {
                    fields[index]->crops = realloc(fields[index]->crops, 
                            (fields[index]->cropCount + 1) * sizeof(Crop *));
                    fields[index]->crops[fields[index]->cropCount++] = createCrop();
                } else {
                    printf("Invalid field index.\n");
                }
                break;
            }
            case 3: {
                int index;
                printf("Enter field index (0 to %d): ", fieldCount - 1);
                scanf("%d", &index);
                if (index >= 0 && index < fieldCount) {
                    fields[index]->equipment = realloc(fields[index]->equipment, 
                            (fields[index]->equipmentCount + 1) * sizeof(Equipment *));
                    fields[index]->equipment[fields[index]->equipmentCount++] = createEquipment();
                } else {
                    printf("Invalid field index.\n");
                }
                break;
            }
            case 4: {
                int index;
                printf("Enter field index (0 to %d): ", fieldCount - 1);
                scanf("%d", &index);
                if (index >= 0 && index < fieldCount) {
                    fields[index]->sensors = realloc(fields[index]->sensors, 
                            (fields[index]->sensorCount + 1) * sizeof(Sensor *));
                    fields[index]->sensors[fields[index]->sensorCount++] = createSensor();
                } else {
                    printf("Invalid field index.\n");
                }
                break;
            }
            case 5:
                for (int i = 0; i < fieldCount; i++) {
                    printf("\n--- Field %d ---\n", i);
                    displayField(fields[i]);
                }
                break;
            case 6:
                for (int i = 0; i < fieldCount; i++) {
                    freeField(fields[i]);
                }
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

Field *createField() {
    Field *field = (Field *)malloc(sizeof(Field));
    printf("Enter GPS Latitude: ");
    scanf("%f", &field->gpsCoordinates[0]);
    printf("Enter GPS Longitude: ");
    scanf("%f", &field->gpsCoordinates[1]);
    printf("Enter Soil Health Metric: ");
    scanf("%f", &field->soilHealthMetrics);
    printf("Enter Moisture Level: ");
    scanf("%f", &field->moistureLevel);

    field->crops = NULL;
    field->cropCount = 0;
    field->equipment = NULL;
    field->equipmentCount = 0;
    field->sensors = NULL;
    field->sensorCount = 0;

    printf("Field created successfully.\n");
    return field;
}

Crop *createCrop() {
    Crop *crop = (Crop *)malloc(sizeof(Crop));
    printf("Enter Crop Type: ");
    scanf("%s", crop->cropType);
    printf("Enter Growth Stage: ");
    scanf("%s", crop->growthStage);
    printf("Enter Expected Yield: ");
    scanf("%f", &crop->expectedYield);

    crop->weather = (WeatherForecast *)malloc(sizeof(WeatherForecast));
    printf("Enter Weather Temperature: ");
    scanf("%f", &crop->weather->temperature);
    printf("Enter Weather Rainfall: ");
    scanf("%f", &crop->weather->rainfall);
    printf("Enter Weather Wind Speed: ");
    scanf("%f", &crop->weather->windSpeed);

    printf("Crop added successfully.\n");
    return crop;
}

Equipment *createEquipment() {
    Equipment *equipment = (Equipment *)malloc(sizeof(Equipment));
    printf("Enter Equipment Type: ");
    scanf("%s", equipment->equipmentType);
    printf("Enter Operational Status: ");
    scanf("%s", equipment->operationalStatus);
    printf("Enter Fuel Level: ");
    scanf("%f", &equipment->fuelLevel);
    printf("Enter Activity Schedule: ");
    scanf("%s", equipment->activitySchedule);

    printf("Equipment added successfully.\n");
    return equipment;
}

Sensor *createSensor() {
    Sensor *sensor = (Sensor *)malloc(sizeof(Sensor));
    printf("Enter Soil Nutrients: ");
    scanf("%f", &sensor->soilNutrients);
    printf("Enter pH Level: ");
    scanf("%f", &sensor->pHLevel);
    printf("Enter Pest Activity (0: None, 1: Low, 2: Moderate, 3: High): ");
    scanf("%d", &sensor->pestActivity);

    printf("Sensor added successfully.\n");
    return sensor;
}

void displayField(Field *field) {
    printf("GPS Coordinates: (%f, %f)\n", field->gpsCoordinates[0], field->gpsCoordinates[1]);
    printf("Soil Health: %.2f\n", field->soilHealthMetrics);
    printf("Moisture Level: %.2f\n", field->moistureLevel);

    printf("Crops:\n");
    for (int i = 0; i < field->cropCount; i++) {
        printf("  - Type: %s, Growth Stage: %s, Yield: %.2f\n",
               field->crops[i]->cropType, field->crops[i]->growthStage, field->crops[i]->expectedYield);
    }

    printf("Equipment:\n");
    for (int i = 0; i < field->equipmentCount; i++) {
        printf("  - Type: %s, Status: %s, Fuel: %.2f\n",
               field->equipment[i]->equipmentType, field->equipment[i]->operationalStatus, field->equipment[i]->fuelLevel);
    }

    printf("Sensors:\n");
    for (int i = 0; i < field->sensorCount; i++) {
        printf("  - Nutrients: %.2f, pH: %.2f, Pest: %d\n",
               field->sensors[i]->soilNutrients, field->sensors[i]->pHLevel, field->sensors[i]->pestActivity);
    }
}

void freeField(Field *field) {
    for (int i = 0; i < field->cropCount; i++) {
        free(field->crops[i]->weather);
        free(field->crops[i]);
    }
    free(field->crops);

    for (int i = 0; i < field->equipmentCount; i++) {
        free(field->equipment[i]);
    }
    free(field->equipment);

    for (int i = 0; i < field->sensorCount; i++) {
        free(field->sensors[i]);
    }
    free(field->sensors);

    free(field);
}