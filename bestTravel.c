#include "bestTravel.h"

int chooseBestSum(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize) {
    TravelData input;
    initializeInputData(distanceLimit, maxTownsToVisit, townDistances, townDistancesSize, &input);

    RecursionData recursionData;
    initializeRecursionData(maxTownsToVisit, &recursionData);

    findBestSum(&input, &recursionData, 0, 0);
    free(recursionData.permutation);
    return (recursionData.bestSum);
}

void initializeInputData(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize, TravelData *input) {
    input->distanceLimit = distanceLimit;
    input->maxTownsToVisit = maxTownsToVisit;
    input->townDistances = townDistances;
    input->townDistancesSize = townDistancesSize;
}

void initializeRecursionData(int maxTownsToVisit, RecursionData *recursionData) {
    recursionData->permutation = calloc(maxTownsToVisit, sizeof(int));
    recursionData->bestSum = -1;
}

void findBestSum(TravelData *input, RecursionData *recursionData, int permutationIndex, int offset) {
    if (permutationIndex == input->maxTownsToVisit) {
        updateBestSum(input, recursionData);
        return ;
    }
    for (int distanceIndex = offset; distanceIndex < input->townDistancesSize; distanceIndex++) {
        recursionData->permutation[permutationIndex] = input->townDistances[distanceIndex];
        findBestSum(input, recursionData, permutationIndex + 1, distanceIndex + 1);
    }
}

void updateBestSum(TravelData *input, RecursionData *recursionData) {
    int sum = 0;
    for (int permutationIndex = 0; permutationIndex < input->maxTownsToVisit; permutationIndex++) {
        sum += recursionData->permutation[permutationIndex];
    }
    if (sum > recursionData->bestSum && sum <= input->distanceLimit) {
        recursionData->bestSum = sum;
    }
}

int main() {
    int townDistances[] = {1,2,3,4,5};
    int townDistancesSize = 5;
    int townsToVisit = 3;
    int bestSum = chooseBestSum(12, townsToVisit, townDistances, townDistancesSize);
    printf("%d\n", bestSum);
}