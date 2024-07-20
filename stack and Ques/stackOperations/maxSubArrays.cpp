#include <bits/stdc++.h>
// Function to calculate the maximum length of subarray with at most k zeros
int main(){
    int n;
    cin>>n; // Read the size of the array

    int k;
    cin>>k; // Read the maximum number of zeros allowed

    vector<int> a(n);
    for(auto &i : a)
        cin>>i; // Read the elements of the array

    int zerocnt = 0; // Variable to count the number of zeros
    int i=0; // Pointer to the start of the subarray
    int ans=0; // Variable to store the maximum length of subarray

    for(int j=0;j<n;j++){
        if(a[j]==0){
            zerocnt++; // Increment the zero count if the current element is zero
        }

        while(zerocnt>k){
            if(a[i]==0){
                zerocnt--; // Decrement the zero count if the element at the start of the subarray is zero
            }
            i++; // Move the start pointer to the right
        }

        ans = max(ans, j-i+1); // Update the maximum length of subarray
    }

    // Print the result
    cout << ans << endl;
}