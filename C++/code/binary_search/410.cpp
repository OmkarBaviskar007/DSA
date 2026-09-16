/*
410. Split Array Largest Sum
Hard
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/

#include<iostream>
#include<vector>

using namespace std;

bool isSplitEligible(vector<int> nums, int k, int splitValue) {
    // [7,2,5,10,8]
    int sum = 0;
    int i=0;
    while(i<nums.size()) {
        if(k>0) {
            if((sum+nums[i])<=splitValue) {
                sum += nums[i];
            } else {
                --k;
                sum = 0;
                continue;
            }
        } else {
            return false;
        }
        i++;
    }
    return (k>0);
}

int splitArray(vector<int>& nums, int k) {
    int s = 0;
    int e = 0;
    int splitValue = -1;
    for(int i=0; i<nums.size(); i++) {
        e += nums[i];
    }
    while(s<=e) {
        int mid = s+(e-s)/2;
        if(isSplitEligible(nums, k, mid)) {
            splitValue = mid;
            e = mid-1;
        } else {
            s = mid+1;
        }
    }
    return splitValue;
}

int main() {
    int size;
    cout<<"Enter size of vector - ";
    cin>>size;
    vector<int> nums(size);
    cout<<endl<<"Enter the vector to be split - ";
    for(int i=0; i<nums.size(); i++) {
        cin>>nums[i];
    }
    int k;
    cout<<"Enter the parts in which vector needs to be split - ";
    cin>>k;
    cout<<"Largest sum among the two subarrays is only "<<splitArray(nums, k);
}