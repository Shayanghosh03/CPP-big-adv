#include<iostream>
#include<climits>
using namespace std;

void maxSubarraySum1(int *arr, int n) { /// O(n^3)
    int maxSum = INT_MIN;
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            int subarraySum = 0;
            for(int i = start; i <= end; i++) {
                subarraySum += arr[i];
            }
            cout<<subarraySum<<", ";
            maxSum = max(maxSum, subarraySum);
        }
        cout<<endl;
    }
    cout<<"Maximum subarray sum is => "<<maxSum<<endl;
}

// Optimized Solution
void maxSubarraySum2(int *arr, int n) { /// O(n^2) 
    int maxSum = INT_MIN;
    for(int start = 0; start < n; start++) {
        int currSum = 0;
        for(int end = start; end < n; end++) {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout<<"Maximum subarray sum is => "<<maxSum<<endl;
}

// Kadane's Algorithm
void maxSubarraySum3(int *arr, int n) { // O(n)
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }

    cout<<"Maximum Subarray Sum is => "<<maxSum<<endl;
}

int main() {
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxSubarraySum1(arr, n);
    maxSubarraySum2(arr, n);
    maxSubarraySum3(arr, n);

    return 0;
}