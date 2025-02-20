/*
    You are given an array of `events` where `events[i] = [startDayi, endDayi]`. Every event `i` starts at `startDayi`
    and ends at `endDayi`.

    You can attend an event `i` at any day `d` where `startTime_i <= d <= endTime_i`. You can only attend one event at
    any time `d`.

    Return the maximum number of events you can attend.

    ## Example 1

    ```
    Input: events = [[1,2],[2,3],[3,4]]
    Output: 3
    Explanation: You can attend all the three events.
    One way to attend them all is as shown.
    Attend the first event on day 1.
    Attend the second event on day 2.
    Attend the third event on day 3.
    ```

    ## Example 2
    ```
    Input: events= [[1,2],[2,3],[3,4],[1,2]]
    Output: 4
    ```

    ## Constraints

    * `1 <= events.length <= 10^5`
    * `events[i].length == 2`
    * `1 <= startDayi <= endDayi <= 10^5`
*/

#include <stdio.h>
#include <stdlib.h>

int comp (const void * a, const void * b) {
    int *rowA = *(int **)a;
    int *rowB = *(int **)b;

    // Compare the first elements of each row
    if (rowA[0] != rowB[0]) {
        return rowA[0] - rowB[0];
    }
    else {
        // If the first elements are the same, compare the second elements
        return rowA[1] - rowB[1];
    }
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    int attended_events = 0;
    int when_available = 1;
    int i = 0;

    qsort(events, eventsSize, sizeof(int *), comp);

    for (i = 0; i < eventsSize; i++) {
        if (events[i][0] >= when_available || when_available <= events[i][1]) {
            attended_events++;

            // Next available slot is inside the next event, use this slot and be available the following day
            when_available++;
        }
        else if (when_available < events[i][0]) {
            attended_events++;

            // Next event is after our next available day so now, our next available day will be the following day of
            // the event
            when_available = events[i][0] + 1;
        }
    }

    return attended_events;
}

int main(int argc, char const *argv[]) {
    int rows = 3;
    int cols = 2;
    int i = 0;

    // Allocate memory for the rows
    int **matrix = (int **)malloc(rows * sizeof(int *));

    // Allocate memory for the columns in each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the matrix with the given values
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 2;
    matrix[1][1] = 3;
    matrix[2][0] = 3;
    matrix[2][1] = 4;

    printf("First series of events: %d\n", maxEvents(matrix, rows, &cols));

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);

    rows = 4;

    matrix = (int **)malloc(rows * sizeof(int *));

    // Allocate memory for the columns in each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the matrix with the given values
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 2;
    matrix[1][1] = 3;
    matrix[2][0] = 3;
    matrix[2][1] = 4;
    matrix[3][0] = 1;
    matrix[3][1] = 2;

    printf("Second series of events: %d\n", maxEvents(matrix, rows, &cols));

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}