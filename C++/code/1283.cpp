/*

1283. Find the Smallest Divisor Given a Threshold
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106

*/

#include<iostream>
#include<vector>

using namespace std;

// int findMaxElement(vector<int> nums) {
//     int maxElement = 1;
//     for(int i=0; i<nums.size(); i++) {
//         if(nums[i]>maxElement) maxElement = nums[i];
//     }
//     return maxElement;
// }

bool isDivisorEligible(vector<int> nums, int divisor, int threshold) {
    for(int i=0;i<nums.size();i++) {
        if(threshold<=0) return false;
        // *** (a + b - 1) / b -> easy formula for ceil ***
        // if(nums[i]%divisor==0) threshold -= (nums[i]/divisor);
        // else threshold -= (nums[i]+divisor-1)/divisor;
        threshold -= (nums[i]+divisor-1)/divisor;
    }
    return threshold>=0;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int minDivisor = 1;
    int maxElement = 1;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i]>maxElement) maxElement = nums[i];
    }
    int s = 1;
    while(s<=maxElement) {
        int mid = s+(maxElement-s)/2;
        if(isDivisorEligible(nums, mid, threshold)) {
            minDivisor = mid;
            maxElement=mid-1;
        } else {
            s=mid+1;
        }
    }
    return minDivisor;
}

int main() {
    int size;
    cout<<"Please enter size of input vector - ";
    cin>>size;
    vector<int> v(size);
    cout<<endl<<"Enter input vector - "<<endl;
    for(int i=0; i<size; i++) {
        cin>>v[i];
    }
    int threshold;
    cout<<"Enter threshold value"<<endl;
    cin>>threshold;
    cout<<"Smallest divisor is - "<<smallestDivisor(v, threshold);
}