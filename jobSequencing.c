#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Job structure
typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

// Function to compare two jobs by profit in descending order
int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->profit - j1->profit;
}

int main() {
    Job jobs[MAX];
    int n, max_deadline = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter job details (id deadline profit):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    // Sort jobs by decreasing profit
    qsort(jobs, n, sizeof(Job), compare);

    int slot[MAX] = {0};  // Time slots, 0 means free
    int result[MAX];      // To store result (job ids)
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output the job sequence
    printf("\nSelected Jobs: ");
    for (int i = 1; i <= max_deadline; i++) {
        if (slot[i])
            printf("Job%d ", result[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}
