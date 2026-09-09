#include<iostream>
#include<vector>

using namespace std;

void sortVector(vector<int> &v, int size) {
    for(int i=0; i< size-1; i++) {
        int min = i;
        for(int j = i+1; j<size; j++) {
            if(v[min]>v[j]) {
                min = j;
            }
        }
        if(min!=i) {
            int temp = v[min];
            v[min] = v[i];
            v[i] = temp;
        }
    }
}

int floorNumber(vector<int> &v, int size, int target) {
    sortVector(v, size);
    int s = 0;
    int e = size-1;
    int floor = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;
        if(v[mid] == target) {
            return v[mid];
        } else if(v[mid]>target) {
            e = mid-1;
        } else {
            floor = v[mid];
            s = mid+1;
        }
    }
    return floor;
}

int main() {
    int size;
    int target;
    cout<< "Enter input vector size - ";
    cin>>size;
    vector<int> v(size);
    cout<< "Enter input vector - "<<endl;
    for(int i=0; i<size; i++) {
        cin>>v[i];
    }
    cout << "Enter target - "<<endl;
    cin >> target;
    cout<< "Floor number is - " << floorNumber(v, size, target);
}