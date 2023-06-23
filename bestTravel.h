#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct travelData {
    int distanceLimit;
    int maxTownsToVisit;
    int *townDistances;
    int townDistancesSize;
} travelData;

typedef struct recursionData {
    int *permutation;
    int bestSum;
} recursionData;

int chooseBestSum(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize);
void initInputData(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize, travelData *input);
void initRecursionData(int maxTownsToVisit, recursionData *recData);
void findBestSum(travelData *input, recursionData *recData, int depth, int offset);
void updateBestSum(travelData *input, recursionData *recData);