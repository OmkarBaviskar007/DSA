/*
852. Peak Index in a Mountain Array
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

 

Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1

 

Constraints:

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
*/

#include<vector>
#include<iostream>

using namespace std;

int findPeak(vector<int>& v, int size) {
    int s=0;
    int e=size-1;
    while(s<=e) {
        int mid=s+(e-s)/2;
        if(mid!=0 && mid!=size-1) {
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1]) {
                return v[mid];
            } else if(v[mid]>v[mid-1] && v[mid]<v[mid+1]) {
                s=mid+1;
            } else {
                e=mid-1;
            }
        } else {
            return -1;
        }
    }
    return -1;
}

int main() {
    int size;
    cout<<"Enter size of the inpput vector - ";
    cin>>size;
    vector<int> v(size);
    cout<<endl<<"Enter the input mountain vector - ";
    for(int i=0; i<size; i++) {
        cin>>v[i];
    }
    int peak = findPeak(v, size);
    if(peak>0) {
        cout<<"Peak index is "<<peak;
    } else {
        cout<<"Input is not mountain vector";
    }
}