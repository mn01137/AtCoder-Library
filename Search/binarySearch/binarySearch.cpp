#include <bits/stdc++.h>
using namespace std;
vector<int> a = {1, 14, 32, 51, 243, 419, 750, 910};

int binary_search(int key)
{
    int left = 0, right = (int)a.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    sort(a.begin(), a.end());
    // Returns the index of the value in the array if there is one.
    cout << binary_search(51) << endl;
    // If not, return -1.
    cout << binary_search(0) << endl;
}