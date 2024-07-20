/**
 * This program demonstrates the usage of the deque container in C++.
 * A deque (double-ended queue) is a sequence container that allows insertion and deletion at both ends.
 */
#include <iostream>
#include <deque>
#include<vector>
using namespace std;

// int main(){

//     deque<int> dq;
//     dq.push_back(1);
//     dq.push_back(2);
//     dq.push_front(3);
//     dq.push_front(4);
//     for(auto i : dq){
//         cout<<i<<" ";
//         cout<<"\n";
//     }

//     return 0;
// }

int main(){

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    
    return 0;
}