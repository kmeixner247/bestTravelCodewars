#include "bestTravel.h"

int chooseBestSum(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize) {
    travelData input;
    initInputData(distanceLimit, maxTownsToVisit, townDistances, townDistancesSize, &input);

    recursionData recData;
    initRecursionData(maxTownsToVisit, &recData);

    findBestSum(&input, &recData, 0, 0);
    free(recData.permutation);
    return (recData.bestSum);
}

void initInputData(int distanceLimit, int maxTownsToVisit, int townDistances[], int townDistancesSize, travelData *input) {
    input->distanceLimit = distanceLimit;
    input->maxTownsToVisit = maxTownsToVisit;
    input->townDistances = townDistances;
    input->townDistancesSize = townDistancesSize;
}

void initRecursionData(int maxTownsToVisit, recursionData *recData) {
    recData->permutation = calloc(maxTownsToVisit, sizeof(int));
    recData->bestSum = -1;
}

void findBestSum(travelData *input, recursionData *recData, int permutationIndex, int offset) {
    if (permutationIndex == input->maxTownsToVisit) {
        updateBestSum(input, recData);
        return ;
    }
    for (int distanceIndex = offset; distanceIndex < input->townDistancesSize; distanceIndex++) {
        recData->permutation[permutationIndex] = input->townDistances[distanceIndex];
        findBestSum(input, recData, permutationIndex + 1, distanceIndex + 1);
    }
}

void updateBestSum(travelData *input, recursionData *recData) {
    int sum = 0;
    for (int permutationIndex = 0; permutationIndex < input->maxTownsToVisit; permutationIndex++) {
        sum += recData->permutation[permutationIndex];
    }
    if (sum > recData->bestSum && sum <= input->distanceLimit) {
        recData->bestSum = sum;
    }
}

int main() {
    int townDistances[] = {1,2,3,4,5};
    int townDistancesSize = 5;
    int townsToVisit = 3;
    int bestSum = chooseBestSum(12, townsToVisit, townDistances, townDistancesSize);
    printf("%d\n", bestSum);
}