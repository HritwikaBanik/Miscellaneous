#include <bits/stdc++.h>
using namespace std;

/*
For vector to work as a resizable dynamic array, it has to implement the following features:

Random Access using Index: Quick access to elements using index, with O(1) time complexity.
Dynamic Resizing: The size should automatically change according to elements inserted or deleted without any user interference.
Fast Insertion and Deletion at the End: Insertion and deletion of the elements at the end of the vector must provide O(1) time complexity.
Homogeneous Elements: All the elements must be of same type.
*/

int main() {
    vector<int> v;

    // Both size and capacity increase on adding elements
    for (int i = 1; i <= 7; i++)
        v.push_back(i);

    cout << "Initial Size: " << v.size() << endl;
    cout << "Initial Capacity: " << v.capacity() << endl;

    // On removing elements, only size decrease
    v.pop_back();
    v.pop_back();
  
    cout << "Final Size: " << v.size() << endl;
    cout << "Final Capacity: " << v.capacity() << endl;
    return 0;
}