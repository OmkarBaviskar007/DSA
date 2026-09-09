#include <bits/stdc++.h>
#include <iostream>
// #include <array>

using namespace std;

int main() {
    // cout<<"Helow world";
    int target = 0;
    int arr[10] = {1,3,5,7,9,11,13,15,17,19};
    cin>>target;
    return binarySearch(arr, target);
}

bool binarySearch(int arr[10], int target) {
    int s = 0;
    int e = arr.length-1;
    int mid = s + (e-s)/2;
    while(s<=e) {
        if(arr[mid] == target) return true;

        if(target > arr[mid]) {
            s = mid+1;
        } else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }

    return false;
}