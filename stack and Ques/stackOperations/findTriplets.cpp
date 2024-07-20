#include <bits/stdc++.h>

// in this function triplets are found whose sum is equal to the target sum
// if found then print true else false
//for example n = 5, target = 24, a = [12, 3, 4, 1, 6]
//output will be true
int main(){

    // Read the size of the array
    int n;
    cin >> n;

    // Read the target sum
    int target;
    cin >> target;

    // Read the elements of the array
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    // Initialize a flag to track if the target sum is found
    bool found = false;

    // Sort the array in ascending order
    sort(a.begin(), a.end());

    // Use three pointers to find the triplets that sum up to the target
    for (int i = 0; i < n; i++) {
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int current = a[i] + a[lo] + a[hi];
            if (current == target) {
                found = true;
            }
            if (current < target) {
                lo++;
            } else {
                hi--;
            }
        }
    }

    // Print the result
    if (found) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}