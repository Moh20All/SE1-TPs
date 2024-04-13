#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_REF_STRING 50

typedef struct {
    int page_num;
    bool referenced;
    bool second_chance;
} Page;

int main() {
    int i, j, k, faults = 0, clock_ptr = 0;
    int num_frames, num_pages;
    int ref_string[MAX_REF_STRING];
    Page frames[MAX_FRAMES];

    // Get input
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the length of the reference string: ");
    scanf("%d", &num_pages);

    printf("Enter the reference string, separated by spaces: ");
    for (i = 0; i < num_pages; i++) {
        scanf("%d", &ref_string[i]);
    }

    // Initialize frames
    for (i = 0; i < num_frames; i++) {
        frames[i].page_num = -1;
        frames[i].referenced = false;
        frames[i].second_chance = false;
    }

    // Simulate Second Chance algorithm
    for (i = 0; i < num_pages; i++) {
        // Check if page is already in memory
        bool page_fault = true;
        for (j = 0; j < num_frames; j++) {
            if (frames[j].page_num == ref_string[i]) {
                frames[j].referenced = true;
                page_fault = false;
                break;
            }
        }

        // If page is not in memory, replace a page
        if (page_fault) {
            while (true) {
                // Check if current page has second chance
                if (frames[clock_ptr].second_chance) {
                    frames[clock_ptr].second_chance = false;
                    clock_ptr = (clock_ptr + 1) % num_frames;
                }
                else {
                    // Replace page
                    frames[clock_ptr].page_num = ref_string[i];
                    frames[clock_ptr].referenced = true;
                    frames[clock_ptr].second_chance = true;
                    faults++;
                    clock_ptr = (clock_ptr + 1) % num_frames;
                    break;
                }
            }
        }
    }

    // Print results
    printf("Number of page faults: %d\n", faults);
    printf("Final memory state: ");
    for (i = 0; i < num_frames; i++) {
        if (frames[i].page_num != -1) {
            printf("%d ", frames[i].page_num);
        }
    }
    printf("\n");

    return 0;
}
