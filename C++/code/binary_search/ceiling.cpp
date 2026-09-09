#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sortVector(vector<int> &v, int size) {
    cout<< "Input unsorted list - "<<endl;
    for(int i=0; i<size; i++) {
        cout<<v[i]<<" ";
    }

    for (int i=0; i<size-1; i++) {
        int min = i;
        for (int j=i+1; j<size; j++) {
            if (v[min] > v[j]) min = j;
        }
        if (min != i) swap(v[i], v[min]);
    }

    cout<<endl;
    cout<< "Output sorted list -"<<endl;
    for(int i=0; i<size; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int printCeiling(vector<int> &v, int size, int target) {
    sortVector(v, size);
    int s = 0;
    int e = size-1;
    int ceiling = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;
        if(v[mid] == target) {
            return v[mid];
        } else if(v[mid] > target) {
            ceiling = v[mid];
            e = mid-1;
        } else {
            s = mid+1;
        }
    }
    return ceiling;
}

int main() {
    int size;
    cout << " Enter the size of input vector - ";
    cin >> size;
    vector<int> v(size);
    cout << " Enter the vector - ";
    for(int i=0; i<size; i++) {
        cin >> v[i];
    }
    cout << " Enter target for ceiling - ";
    int target;
    cin >> target;
    cout << "Ceiling value is: " << printCeiling(v, size, target);
}