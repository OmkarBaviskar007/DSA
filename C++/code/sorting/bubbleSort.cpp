#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& v, int size) {
    for(int i=size-1; i>0; i--) {
        bool isSwapDone = false;
        for(int j=0; j<i; j++) {
            if(v[j]>v[j+1]) {
                int temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
                isSwapDone = true;
            }
        }
        if(!isSwapDone) return;
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
    bubbleSort(v, size);
    for(int i=0; i<size; i++) {
        cout<<v[i]<<" ";
    }
}