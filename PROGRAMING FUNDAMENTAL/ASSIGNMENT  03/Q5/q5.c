// NAME HAMMAD YOUNUS
// ID   24K-0689





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Supply {
    char name[100];
};

int main() {
    int speciesCount, supplyCount;

    printf("Enter the number of species: ");
    scanf("%d", &speciesCount);

    printf("Enter the number of supplies for each species: ");
    scanf("%d", &supplyCount);

    // Dynamically allocate memory for species list
    struct Supply ***inventory = (struct Supply ***)malloc(speciesCount * sizeof(struct Supply **));

    // Initialize each species with a list of supplies
    for (int i = 0; i < speciesCount; i++) {
        inventory[i] = (struct Supply **)malloc((supplyCount + 1) * sizeof(struct Supply *));  // +1 for species name
    }

    // Input species names and supplies
    for (int i = 0; i < speciesCount; i++) {
        printf("Enter the name of species %d: ", i + 1);
        getchar();  // To capture the newline character after scanf
        fgets(inventory[i][0]->name, 100, stdin);
        inventory[i][0]->name[strcspn(inventory[i][0]->name, "\n")] = '\0';  // Remove newline from species name

        for (int j = 1; j <= supplyCount; j++) {
            printf("Enter supply %d for species %d: ", j, i + 1);
            fgets(inventory[i][j]->name, 100, stdin);
            inventory[i][j]->name[strcspn(inventory[i][j]->name, "\n")] = '\0';  // Remove newline from supply name
        }
    }

    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Add a Species\n");
        printf("2. Update a Species\n");
        printf("3. Remove a Species\n");
        printf("4. Show Inventory\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                speciesCount++;
                inventory = (struct Supply ***)realloc(inventory, speciesCount * sizeof(struct Supply **));
                inventory[speciesCount - 1] = (struct Supply **)malloc((supplyCount + 1) * sizeof(struct Supply *));

                // Input for new species
                printf("Enter the name of species %d: ", speciesCount);
                getchar();  // To capture the newline character
                fgets(inventory[speciesCount - 1][0]->name, 100, stdin);
                inventory[speciesCount - 1][0]->name[strcspn(inventory[speciesCount - 1][0]->name, "\n")] = '\0';  // Remove newline

                for (int i = 1; i <= supplyCount; i++) {
                    printf("Enter supply %d for species %d: ", i, speciesCount);
                    fgets(inventory[speciesCount - 1][i]->name, 100, stdin);
                    inventory[speciesCount - 1][i]->name[strcspn(inventory[speciesCount - 1][i]->name, "\n")] = '\0';  // Remove newline
                }
                break;
            }

            case 2: {
                int speciesIndex;
                printf("Enter the index (0-%d) of the species to update: ", speciesCount - 1);
                scanf("%d", &speciesIndex);

                if (speciesIndex < 0 || speciesIndex >= speciesCount) {
                    printf("Invalid species index.\n");
                    break;
                }

                printf("Enter the new name for species %d: ", speciesIndex + 1);
                getchar();  // To capture the newline character
                fgets(inventory[speciesIndex][0]->name, 100, stdin);
                inventory[speciesIndex][0]->name[strcspn(inventory[speciesIndex][0]->name, "\n")] = '\0';  // Remove newline

                for (int i = 1; i <= supplyCount; i++) {
                    printf("Enter new supply %d for species %d: ", i, speciesIndex + 1);
                    fgets(inventory[speciesIndex][i]->name, 100, stdin);
                    inventory[speciesIndex][i]->name[strcspn(inventory[speciesIndex][i]->name, "\n")] = '\0';  // Remove newline
                }
                break;
            }

            case 3: {
                int speciesIndex;
                printf("Enter the index (0-%d) of the species to remove: ", speciesCount - 1);
                scanf("%d", &speciesIndex);

                if (speciesIndex < 0 || speciesIndex >= speciesCount) {
                    printf("Invalid species index.\n");
                    break;
                }

                // Free the memory for the species supplies
                free(inventory[speciesIndex]);

                // Shift the species down
                for (int i = speciesIndex; i < speciesCount - 1; i++) {
                    inventory[i] = inventory[i + 1];
                }

                // Reallocate the memory for the reduced species count
                speciesCount--;
                inventory = (struct Supply ***)realloc(inventory, speciesCount * sizeof(struct Supply **));
                break;
            }

            case 4: {
                // Display current species and supplies
                for (int i = 0; i < speciesCount; i++) {
                    printf("\nSpecies %d (%s):\n", i + 1, inventory[i][0]->name);
                    for (int j = 1; j <= supplyCount; j++) {
                        printf("  Supply %d: %s\n", j, inventory[i][j]->name);
                    }
                }
                break;
            }

            case 5:
                // Exit program
                for (int i = 0; i < speciesCount; i++) {
                    free(inventory[i]);
                }
                free(inventory);
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
