#include <stdio.h>

void checkIfLarger(int distanceLimit, int *permutation, size_t townsToVisit, int *largestDistance)
{
    int sum = 0;
    for (size_t i = 0; i < townsToVisit; i++) {
        sum += permutation[i];
    }
    if (sum <= distanceLimit)
        *largestDistance = *largestDistance > sum ? *largestDistance : sum;
}

void THEFUNCTION(int distanceLimit, int *largestDistance, int townDistances[], size_t townDistancesSize, int *permutation, size_t townsToVisit, size_t depth, size_t offset) {
    if (depth == townsToVisit) {
        checkIfLarger(distanceLimit, permutation, townsToVisit, largestDistance);
        return ;
    }
    for (size_t i = offset; i < townDistancesSize; i++) {
        permutation[depth] = townDistances[i];
        THEFUNCTION(distanceLimit, largestDistance, townDistances, townDistancesSize, permutation, townsToVisit, depth + 1, i + 1);
    }
}

int chooseBestSum(int distanceLimit, size_t townsToVisit, int townDistances[], size_t townDistancesSize) {
    int permutation[townsToVisit];
    int largestDistance = -1;
    THEFUNCTION(distanceLimit, &largestDistance, townDistances, townDistancesSize, permutation, townsToVisit,  0, 0);
    return largestDistance;
}

int main() {
    int townDistances[] = {1,2,3,4,5};
    size_t townDistancesSize = 5;
    size_t townsToVisit = 3;
    int a = chooseBestSum(6, townsToVisit, townDistances, townDistancesSize);
    printf("%d\n", a);
}