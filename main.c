/*
const
    MAX_LEN : integer = 30;
    MAX_BIKES : integer = 2;
type
    tBattery = record
        battery : integer;
    end record
    tWeight = record
        weight : real;
    end record
    tBycicle = record
        idModel : string;
        capacity : tBattery;
        weight : tWeight;
    end record
end type

algorithm PEC4
    var
        bikeGroup : array[MAX_BIKES] of tBycicle;
        i : integer;
        resultCmp : integer;
        fileToRead : file;
    end var
    fileToRead := openFile("test.data");
        for i = 1 to MAX_BIKES do
            ch := readCharFromFile(fileToRead);
            in := readIntegerFromFile(fileToRead);
            re := readRealFromFile(fileToRead);
        end for
        (define var)
        bestBike := integer;
        for i = 1 to MAX_BIKES + 1 do
            if (bikeGroup[i].capacity.battery > bikeGroup[bestBike]capacity.battery
                or bikeGroup[i].capacity.battery = bikeGroup[bestBike]capacity.battery
                and bikeGroup[i].weight < bikeGroup[bestBike]weight) then
                bestBike = i;
            end if
            if (bikeGroup[i].capacity.battery = bikeGroup[bestBike]capacity.battery
                and bikeGroup[i].weight = bikeGroup[bestBike]weight) 
                and if (strbikeGroup[i].idModel < strbikeGroup[bestBike].idModel) then
                bestBike = i;
            end if
        end for
        writeString("OUTPUT");
        writeString("THE BEST E-BIKE IS:");
        writeString(bikeGroup[bestBike].idModel);
    closeFile(fileToRead);
end algorithm
*/
#include <stdio.h>
#include <string.h>
#define MAX_LEN 30+1 /* maximum leght of characters for bike name */
#define MAX_BIKES 2 /* just change the maximum for more bikes */

typedef struct {
    int battery;
} tBattery;

typedef struct {
    float weight;
} tWeight;

typedef struct {
    char idModel[MAX_LEN];
    tBattery capacity;
    tWeight weight;
} tBycicle;

int main()
{
    tBycicle bikeGroup[MAX_BIKES]; /* array[MAX_BIKES] of tBycicle */
    int i, resultCmp; /* iteration & comparation*/
    FILE* fileToRead; /* file to open */
    
    fileToRead = fopen("test.data","r");
    for (i = 0; i < MAX_BIKES; i++) {
    fscanf(fileToRead, "%s %d %f", bikeGroup[i].idModel, &bikeGroup[i].capacity.battery, &bikeGroup[i].weight.weight);
    }
    
    int bestBike = 0; /* We take the first as the best bycicle */
    resultCmp = strcmp(bikeGroup[i].idModel, bikeGroup[bestBike].idModel);
    for (i = 1; i < MAX_BIKES; i++) { 
        if (bikeGroup[i].capacity.battery > bikeGroup[bestBike].capacity.battery ||
        (bikeGroup[i].capacity.battery == bikeGroup[bestBike].capacity.battery && 
        bikeGroup[i].weight.weight < bikeGroup[bestBike].weight.weight)) {
            bestBike = i; /* Bike i is the best one */
        }
        if (((bikeGroup[i].capacity.battery == bikeGroup[bestBike].capacity.battery && 
        bikeGroup[i].weight.weight == bikeGroup[bestBike].weight.weight) && 
        (resultCmp = strcmp(bikeGroup[i].idModel, bikeGroup[bestBike].idModel)) < 0)) {
            bestBike = i; /* Bike i is the best one */
        }
        }
    printf("OUTPUT\n");
    printf("THE BEST E-BIKE IS %s\n", bikeGroup[bestBike].idModel);
    fclose(fileToRead); /* close read file */
	return 0;
}

