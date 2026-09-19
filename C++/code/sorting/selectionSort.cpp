#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& v, int size) {
    
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
        cout<<v[i];
    }
}