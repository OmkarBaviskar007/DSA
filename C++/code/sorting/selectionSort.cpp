#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>& v, int size) {
    for(int i=size-1; i>0; i--) {
        int max = 0;
        for(int j=0; j<=i; j++) {
            if(v[j]>v[max]) max = j;
        }
        if(v[max]!=v[i]) {
            int temp = v[max];
            v[max] = v[i];
            v[i] = temp;
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
    selectionSort(v, size);
    for(int i=0; i<size; i++) {
        cout<<v[i]<<" ";
    }
}