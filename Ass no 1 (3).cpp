#include <iostream>
using namespace std;

class Count
{
public:
    int first(int a[], int low, int high);
    int total(int a[], int n);
};

int Count::first(int a[], int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || a[mid - 1] == 1) && a[mid] == 0)
        {
            return mid;
        }
        if (a[mid] == 1)
        {
            return first(a, mid + 1, high);
        }
        else
        {
            return first(a, low, mid - 1);
        }
    }
    return -1;
}

int Count::total(int a[], int n)
{
    int f = first(a, 0, n - 1);
    if (f == -1)
    {
        return 0;
    }
    return (n - f);
}

int main()
{
    Count c;
    int a[] = {1, 1, 1, 1, 0, 0, 0, 0};
    int n = sizeof(a) / sizeof(a[0]); 
    int t = c.total(a, n);
    cout << t;
    return 0;
}
