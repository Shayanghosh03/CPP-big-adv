#include<iostream>
#include<climits>
using namespace std;

int trappinRainWater(int *height, int n) {
    int leftMax[20000];
    int rightMax[20000];
    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];
    
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i-1]);
        cout<<leftMax[i]<<", ";
    }
    cout<<endl;
    for(int i = n-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i+1]);
        cout<<rightMax[i]<<", ";
    }
    cout<<endl;

    int wrappedWater = 0;
    for(int i = 0; i < n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - height[i];
        if(currWater > 0) {
            wrappedWater += currWater;
        }
    }

    return wrappedWater;
}

int main() {
    int heights[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights) / sizeof(heights[0]);

    int result = trappinRainWater(heights, n);
    cout<<"Traipping Rain Watter is => "<<result<<endl;

    return 0;
}