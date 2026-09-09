/*

744. Find Smallest Letter Greater Than Target
Easy
Topics
premium lock icon
Companies
Hint
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
 

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.

*/

#include<iostream>
#include<vector>

using namespace std;

char nextGreatestLetter(vector<char> &letters, int arrSize, char target) {
    int s = 0;
    int e = arrSize - 1;
    while(s<=e) {
        int mid = s+(e-s)/2;
        if(letters[mid] > target) {
            e = mid-1;
        } else {
            s = mid+1;
        }
    }
    return letters[s%arrSize];
}

int main() {
    int arrSize;
    cout<<"Please enter size of input array :- "<<endl;
    cin>>arrSize;
    vector<char> letters(arrSize);
    cout<<"Please enter input array :- "<<endl;
    for(int i=0; i<arrSize; i++) {
        cin>>letters[i];
    }
    char target;
    cout<<"Please enter target"<<endl;
    cin>>target;
    cout<< "Smallest alphabet greater then target char is "<<nextGreatestLetter(letters, arrSize, target);
}