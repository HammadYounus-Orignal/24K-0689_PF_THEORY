// NAME HAMMAD YOUNUS
// ID   24K-0689



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct weather_forecast {
    float temperature;
    float rainfall;
    float wind_speed;
} weather_forecast;

typedef struct crop {
    char crop_type[50];
    char growth_stage[50];
    float expected_yield;
    weather_forecast* weather;
} crop;

typedef struct equipment {
    char equipment_type[50];
    float fuel_level;
    char operational_status[50];
    char activity_schedule[100];
} equipment;

typedef struct sensor {
    char sensor_type[50];
    float data_value;
} sensor;

typedef struct field {
    float gps_latitude;
    float gps_longitude;
    float soil_health_metric;
    float moisture_level;
    crop* crops;
    int num_crops;
    equipment* equipments;
    int num_equipments;
    sensor* sensors;
    int num_sensors;
} field;

typedef struct regional_hub {
    field* fields;
    int num_fields;
    float aggregated_yield;
    char resource_distribution_plan[100];
    char emergency_response_plan[100];
} regional_hub;

void initialize_field(field* f, int num_crops, int num_equipments, int num_sensors) {
    f->crops = malloc(num_crops * sizeof(crop));
    f->num_crops = num_crops;
    for (int i = 0; i < num_crops; i++) {
        f->crops[i].weather = malloc(sizeof(weather_forecast));
    }
    f->equipments = malloc(num_equipments * sizeof(equipment));
    f->num_equipments = num_equipments;
    f->sensors = malloc(num_sensors * sizeof(sensor));
    f->num_sensors = num_sensors;
}

void free_field(field* f) {
    for (int i = 0; i < f->num_crops; i++) {
        free(f->crops[i].weather);
    }
    free(f->crops);
    free(f->equipments);
    free(f->sensors);
}

void initialize_hub(regional_hub* hub, int num_fields) {
    hub->fields = malloc(num_fields * sizeof(field));
    hub->num_fields = num_fields;
}

void free_hub(regional_hub* hub) {
    for (int i = 0; i < hub->num_fields; i++) {
        free_field(&hub->fields[i]);
    }
    free(hub->fields);
}

int main() {
    int num_hubs, num_fields, num_crops, num_equipments, num_sensors;
    regional_hub* hubs;

    printf("Enter the number of regional hubs: ");
    scanf("%d", &num_hubs);

    hubs = malloc(num_hubs * sizeof(regional_hub));

    for (int i = 0; i < num_hubs; i++) {
        printf("Enter the number of fields for hub %d: ", i + 1);
        scanf("%d", &num_fields);
        initialize_hub(&hubs[i], num_fields);

        for (int j = 0; j < num_fields; j++) {
            printf("Field %d - Enter the number of crops: ", j + 1);
            scanf("%d", &num_crops);
            printf("Field %d - Enter the number of equipments: ", j + 1);
            scanf("%d", &num_equipments);
            printf("Field %d - Enter the number of sensors: ", j + 1);
            scanf("%d", &num_sensors);
            initialize_field(&hubs[i].fields[j], num_crops, num_equipments, num_sensors);
        }
    }

    for (int i = 0; i < num_hubs; i++) {
        free_hub(&hubs[i]);
    }

    free(hubs);

    return 0;
}