#include <iostream>
using namespace std;

// Function to check if 'tasksPerDay' tasks per day can finish all tasks in 'totalDays' days
bool canCompleteInDays(int tasksPerDay, int tasks[], int numTasks, int totalDays) {
    int daysNeeded = 0;
    for (int i = 0; i < numTasks; i++) {
        daysNeeded += (tasks[i] + tasksPerDay - 1) / tasksPerDay; // Calculate required days for each task
        if (daysNeeded > totalDays) return false; // Return false if it exceeds available days
    }
    return true;
}

// Function to find the minimum number of tasks that can be done each day
int findMinimumTasksPerDay(int tasks[], int numTasks, int totalDays) {
    int left = 1, right = tasks[0];
    for (int i = 1; i < numTasks; i++) {
        if (tasks[i] > right) right = tasks[i]; // Find the maximum task value
    }

    int result = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCompleteInDays(mid, tasks, numTasks, totalDays)) {
            result = mid;
            right = mid - 1; // Search the left half
        } else {
            left = mid + 1; // Search the right half
        }
    }

    return result;
}

// Driver code
int main() {
    int tasks[] = {3, 4, 7, 15};
    int totalDays = 10;
    int numTasks = sizeof(tasks) / sizeof(tasks[0]);

    cout << "Minimum tasks per day to finish within " << totalDays << " days: " << findMinimumTasksPerDay(tasks, numTasks, totalDays) << endl;

    return 0;
}
