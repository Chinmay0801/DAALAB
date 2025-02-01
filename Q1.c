#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N;  // Number of tasks/agents
int minCost = INT_MAX; // Stores the minimum assignment cost

// Function to calculate total assignment cost for a given permutation
int calculateCost(int **costMatrix, int *assignment) {
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}

// Utility function for generating all permutations using backtracking
void permute(int **costMatrix, int *assignment, int l) {
    if (l == N) {
        int currentCost = calculateCost(costMatrix, assignment);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
        return;
    }

    for (int i = l; i < N; i++) {
        // Swap
        int temp = assignment[l];
        assignment[l] = assignment[i];
        assignment[i] = temp;

        // Recur
        permute(costMatrix, assignment, l + 1);

        // Backtrack
        temp = assignment[l];
        assignment[l] = assignment[i];
        assignment[i] = temp;
    }
}

int main() {
    printf("Enter the number of tasks/agents: ");
    scanf("%d", &N);

    // Allocate memory for cost matrix dynamically
    int **costMatrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        costMatrix[i] = (int *)malloc(N * sizeof(int));
    }

    printf("Enter the cost matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Initialize assignment array
    int *assignment = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        assignment[i] = i;
    }

    // Generate permutations and find minimum assignment cost
    permute(costMatrix, assignment, 0);

    printf("Minimum Assignment Cost: %d\n", minCost);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(costMatrix[i]);
    }
    free(costMatrix);
    free(assignment);

    return 0;
}
