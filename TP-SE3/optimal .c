#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_REF_STRING 50

int main() {
    int memoryFrames[MAX_FRAMES], refString[MAX_REF_STRING], futureRefs[MAX_REF_STRING];
    int memorySize, refSize, pageFaults = 0, pageHits = 0, i, j, k, max, maxIndex;

    // Read in memory size and reference string
    printf("Enter the memory size: ");
    scanf("%d", &memorySize);
    printf("Enter the reference string (enter -1 to terminate):\n");
    for (i = 0; i < MAX_REF_STRING; i++) {
        scanf("%d", &refString[i]);
        if (refString[i] == -1) {
            refSize = i;
            break;
        }
    }

    // Initialize memory frames to -1 to indicate empty frames
    for (i = 0; i < MAX_FRAMES; i++) {
        memoryFrames[i] = -1;
    }

    // Loop through reference string
    for (i = 0; i < refSize; i++) {
        // Check if page is already in memory frames
        int pageFound = 0;
        for (j = 0; j < memorySize; j++) {
            if (memoryFrames[j] == refString[i]) {
                pageHits++;
                pageFound = 1;
                break;
            }
        }

        // If page is not already in memory frames, add it
        if (!pageFound) {
            pageFaults++;
            // Check if there is space in memory frames
            int spaceFound = 0;
            for (j = 0; j < memorySize; j++) {
                if (memoryFrames[j] == -1) {
                    memoryFrames[j] = refString[i];
                    spaceFound = 1;
                    break;
                }
            }
            // If no space is available, find page to replace using future reference string
            if (!spaceFound) {
                // Initialize future reference string to -1 to indicate no future reference
                for (j = 0; j < MAX_REF_STRING; j++) {
                    futureRefs[j] = -1;
                }
                // Fill in future reference string for each page in memory frames
                for (j = 0; j < memorySize; j++) {
                    for (k = i + 1; k < refSize; k++) {
                        if (memoryFrames[j] == refString[k]) {
                            futureRefs[j] = k;
                            break;
                        }
                    }
                }
                // Find the page that will not be needed for the longest time in the future
                max = -1;
                maxIndex = -1;
                for (j = 0; j < memorySize; j++) {
                    if (futureRefs[j] == -1) {
                        maxIndex = j;
                        break;
                    }
                    if (futureRefs[j] > max) {
                        max = futureRefs[j];
                        maxIndex = j;
                    }
                }
                // Replace the page with the longest future time
                memoryFrames[maxIndex] = refString[i];
            }
        }
    }

    // Print the number of page faults and hits
    printf("Number of page faults: %d\n", pageFaults);
    printf("Number of page hits: %d\n", pageHits);

    return 0;
}


/*
#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_REF_STRING 50

// Function to read in memory size and reference string
void readInput(int *memorySize, int *refString) {
    int i;

    printf("Enter the memory size: ");
    scanf("%d", memorySize);

    printf("Enter the reference string (enter -1 to terminate):\n");
    for (i = 0; i < MAX_REF_STRING; i++) {
        scanf("%d", &refString[i]);
        if (refString[i] == -1) {
            break;
        }
    }
}

// Function to simulate Optimal page replacement algorithm
void simulateOptimal(int memorySize, int refString[], int refSize, int *pageFaults, int *pageHits) {
    int memoryFrames[MAX_FRAMES], futureRefs[MAX_REF_STRING];
    int i, j, k, max, maxIndex;

    // Initialize memory frames to -1 to indicate empty frames
    for (i = 0; i < MAX_FRAMES; i++) {
        memoryFrames[i] = -1;
    }

    // Loop through reference string
    for (i = 0; i < refSize; i++) {
        // Check if page is already in memory frames
        int pageFound = 0;
        for (j = 0; j < memorySize; j++) {
            if (memoryFrames[j] == refString[i]) {
                (*pageHits)++;
                pageFound = 1;
                break;
            }
        }

        // If page is not already in memory frames, add it
        if (!pageFound) {
            (*pageFaults)++;
            // Check if there is space in memory frames
            int spaceFound = 0;
            for (j = 0; j < memorySize; j++) {
                if (memoryFrames[j] == -1) {
                    memoryFrames[j] = refString[i];
                    spaceFound = 1;
                    break;
                }
            }
            // If no space is available, find page to replace using future reference string
            if (!spaceFound) {
                // Initialize future reference string to -1 to indicate no future reference
                for (j = 0; j < MAX_REF_STRING; j++) {
                    futureRefs[j] = -1;
                }
                // Fill in future reference string for each page in memory frames
                for (j = 0; j < memorySize; j++) {
                    for (k = i + 1; k < refSize; k++) {
                        if (memoryFrames[j] == refString[k]) {
                            futureRefs[j] = k;
                            break;
                        }
                    }
                }
                // Find the page that will not be needed for the longest time in the future
                max = -1;
                maxIndex = -1;
                for (j = 0; j < memorySize; j++) {
                    if (futureRefs[j] == -1) {
                        maxIndex = j;
                        break;
                    }
                    if (futureRefs[j] > max) {
                        max = futureRefs[j];
                        maxIndex = j;
                    }
                }
                // Replace the page with the longest future time
                memoryFrames[maxIndex] = refString[i];
            }
        }
    }
}

int main() {
    int memorySize, refString[MAX_REF_STRING], refSize, pageFaults = 0, pageHits = 0;

    readInput(&memorySize, refString);

    for (refSize = 0; refSize < MAX_REF_STRING; refSize++)

*/