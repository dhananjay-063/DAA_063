#include <iostream>

using namespace std;

void sort(int startTimes[], int endTimes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (endTimes[j] < endTimes[minIndex]) {
                minIndex = j;
            }
        }
        
        int tempEnd = endTimes[minIndex];
        endTimes[minIndex] = endTimes[i];
        endTimes[i] = tempEnd;
    
        int tempStart = startTimes[minIndex];
        startTimes[minIndex] = startTimes[i];
        startTimes[i] = tempStart;
    }
}

int max(int startTimes[], int endTimes[], int n, int numPersons) {
    
    sort(startTimes, endTimes, n);

    int personsEndTime[10] = {0};  
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int start = startTimes[i];
        int end = endTimes[i];
        
        for (int j = 0; j < numPersons; j++) {
            if (personsEndTime[j] <= start) {  
                personsEndTime[j] = end;  
                count++;
                break;  
            }
        }
    }
    
    return count;
}

int main() {
    int startTimes[] = {1, 8, 3, 2, 6};
    int endTimes[] = {5, 10, 6, 5, 9};
    int numPersons = 2;
    int n = sizeof(startTimes) / sizeof(startTimes[0]);
    cout << "Maximum number of shops visited: " << max(startTimes, endTimes, n, numPersons) << endl;  

    return 0;
}
