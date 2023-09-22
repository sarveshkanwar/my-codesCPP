#include<iostream>
using namespace std;

int trap(int arr[], int n) {
    int left[n];
    int right[n];
    left[0] = arr[0];

    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], arr[i]);
    }

    right[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (min(left[i], right[i]) - arr[i]);
    }

    return ans;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = trap(arr, n); // Call the function and store the result.
    
    cout << "the rainwater stored is " << result << endl; // Display the result.
    
    return 0;
}
