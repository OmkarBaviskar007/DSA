#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& v, int size) {
    for(int i=0; i<size-1; i++) {
        if(v[i]>v[i+1]) {
            int temp = v[i+1];
            v[i+1] = v[i];
            v[i] = temp;
        }
        for(int j=i; j>0; j--) {
            if(v[j]<v[j-1]) {
                int temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            } else break;
        }
    }
}

int main() {
    int size;
    cout<<"Enter size of inout vector - ";
    cin>>size;
    cout<<endl<<"Enter the inpout vector -"<<endl;
    vector<int> v(size);
    for(int i=0; i<size; i++) {
        cin>>v[i];
    }
    cout<<"Sorted vector is -"<<endl;
    insertionSort(v, size);
    for(int i=0; i<size; i++) {
        cout<<v[i]<<" ";
    }
}