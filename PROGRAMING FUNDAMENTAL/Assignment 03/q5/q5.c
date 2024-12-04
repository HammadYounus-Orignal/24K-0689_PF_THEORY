// NAME HAMMAD YOUNUS
// ID   24K-0689



#include <stdio.h>
#include <stdlib.h>

void initializeInventory(char **speciesSupplies, int numSpecies)
{
    speciesSupplies = (char **)malloc(numSpecies * sizeof(char *));
    for (int i = 0; i < numSpecies; i++)
    {
        speciesSupplies[i] = (char *)malloc(1 * sizeof(char));
    }
}

void addSupplies(char ***speciesSupplies, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++)
    {
        printf("Enter the number of supplies for species %d: ", i + 1);
        int numSupplies;
        scanf("%d", &numSupplies);
        speciesSupplies[i] = (char **)realloc(speciesSupplies[i], numSupplies * sizeof(char*));
        for (int j = 0; j < numSupplies; j++)
        {
            printf("Enter supply %d for species %d: ", j + 1, i + 1);
            scanf("%s", &speciesSupplies[i][j]);
        }
    }
}

void updateSupplies(char **speciesSupplies, int numSpecies)
{
    int speciesIndex, supplyIndex;
    printf("Enter the species index to update supplies: ");
    scanf("%d", &speciesIndex);
    printf("Enter the supply index to update: ");
    scanf("%d", &supplyIndex);
    printf("Enter the new supply name: ");
    scanf("%s", &speciesSupplies[speciesIndex][supplyIndex]);
}

void removeSpecies(char **speciesSupplies, int numSpecies)
{
    int speciesIndex;
    printf("Enter the species index to remove: ");
    scanf("%d", &speciesIndex);
    free(speciesSupplies[speciesIndex]);
    for (int i = speciesIndex; i < numSpecies - 1; i++)
    {
        speciesSupplies[i] = speciesSupplies[i + 1];
    }
    speciesSupplies = (char **)realloc(speciesSupplies, (numSpecies - 1) * sizeof(char *));
}

void displayInventory(char **speciesSupplies, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++)
    {
        printf("Species %d supplies: ", i + 1);
        for (int j = 0; j < sizeof(speciesSupplies[i]); j++)
        {
            printf("%s\n", speciesSupplies[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int numSpecies;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    char **speciesSupplies;
    initializeInventory(speciesSupplies, numSpecies);

    addSupplies(speciesSupplies, numSpecies);
    displayInventory(speciesSupplies, numSpecies);

    updateSupplies(speciesSupplies, numSpecies);
    displayInventory(speciesSupplies, numSpecies);

    removeSpecies(speciesSupplies, numSpecies);
    displayInventory(speciesSupplies, numSpecies);

    return 0;
}