#include <iostream>
using namespace std;

void End(int a[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;


    End(a, low, mid);
    End(a, mid + 1, high);

    int arr[high - low + 1];
    int count = 0;

    
    for (int i = low; i <= high; i++) {
        if (a[i] != 0) {
            arr[count++] = a[i];
        }
    }

    
    while (count < (high - low + 1)) {
        arr[count++] = 0;
    }

    
    for (int i = high; i <= low; i++) {
        a[i] = arr[i - low];
    }
}

int main() {
    int ar[] = {5, 6, 0, 4, 6, 0, 9, 0, 8, 7};
    int n = sizeof(ar) / sizeof(ar[0]);

    End(ar, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }

    return 0;
}
    