#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int distanceLimit;
    int maxTownsToVisit;
    int *townDistances;
    int townDistancesSize;
} TravelData;

typedef struct {
    int *permutation;
    int bestSum;
} RecursionData;

int chooseBestSum(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize);
void initInputData(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize, TravelData *input);
void initRecursionData(int maxTownsToVisit, RecursionData *recursionData);
void findBestSum(TravelData *input, RecursionData *recursionData, int depth, int offset);
void updateBestSum(TravelData *input, RecursionData *recursionData);