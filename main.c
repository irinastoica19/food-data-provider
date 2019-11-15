#include <stdio.h>
#include <stdlib.h>
#define MAX_FOOD_NAME 10
#define MAX_DRINK_NAME 10
#define MAX_LINE 10

void readItems(char * food);

int main() {

    int noOfFoodTypes;
    printf("Please input number of food types\n");
    scanf("%d", &noOfFoodTypes);
    printf("%d\n", noOfFoodTypes);

    printf("Please food types (each on a new line, may contain spaces)\n");
    char ** foods;
    foods = (char**)malloc(noOfFoodTypes* sizeof(char*));
    for(int i=0;i<noOfFoodTypes;i++) {
        // read brand
        foods[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        scanf("%s",foods[i]);
    }

    int * noOfSpecificFood = (int*)malloc(noOfFoodTypes * sizeof(int));
    char *** specificFood = (char***)malloc(noOfFoodTypes * sizeof(char**));
    double ** prices = (double**)malloc(noOfFoodTypes * sizeof(double*));
    for(int i=0; i<noOfFoodTypes; i++) {
        // read no of models
        printf("Please input no of speciffic foods for food%s\n",foods[i]);
        scanf("%d", &noOfSpecificFood[i]);
        getchar();
        printf("%d\n", noOfSpecificFood[i]);

        //read models & prices
        specificFood[i] = (char**)malloc(noOfSpecificFood[i]* sizeof(char*));
        prices[i] = (double*)malloc(noOfSpecificFood[i]* sizeof(double));

        printf("Please input %s speciffic foods &prices: each line in the format <speciffic food> (price)\n", foods[i]);
        for(int j=0;j<noOfSpecificFood[i];j++){
            specificFood[i][j] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
            readItems(specificFood[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%lf", &prices[i][j]);
        }
    }

    int noOfDrinks;
    printf("Please input no of drinks\n");
    scanf("%d", &noOfDrinks);
    printf("%d\n", noOfDrinks);

    int * pricesDrinks = (int*)malloc(noOfDrinks * sizeof(int));
    char ** drinks = (char**)malloc(noOfDrinks * sizeof(char*));

    printf("Please input the drinks: each line in the format <drink> (price):\n");
    for(int i=0; i<noOfDrinks; i++){
        drinks[i] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        readItems(drinks);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%d", &pricesDrinks[i]);
    }
/*
    printf("The food data is:\n");
    for(int i=0;i<noOfFoodTypes;i++) {
        printf("%s: ", foods[i]);
        for(int j=0;j<noOfSpecificFood[i];j++) {
            printf("(%s - %d) ",foods[i][j],prices[i][j]);
        }
        printf("\n");
    }
    printf("The drinks data is:\ndrinks:");
    for(int i=0;i<noOfDrinks;i++){
        printf("%s,", drinks[i]);
    }
    printf("prices:");
    for(int i=0;i<noOfDrinks;i++) {
        printf("%d,", pricesDrinks[i]);
    }
    // free memory
    for(int i=0;i<noOfFoodTypes;i++) {
        for(int j=0;j<noOfSpecificFood;j++) {
            free(specificFood[i][j]);
        }
        free(specificFood[i]);
        free(prices[i]);
        free(foods[i]);
    }
    free(specificFood);
    free(prices);
    free(foods);
    free(noOfSpecificFood);
*/
    return 0;
}

void readItems(char * food) {
    char c = getchar();
    int i=0;
    while(c!='('&& c!=')') {
        food[i] = c;
        c = getchar();
        i++;
    }
    food[i] = '\0';
}