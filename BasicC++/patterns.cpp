#include <iostream>
#include <string>
using namespace std;



// learning patterns in c++
// rectanguar pattern
// int main(){
//     int rows,col;
//     cout << "Enter the number of rows: ";
//     cin >>rows>>col;
//     for(int i = 1; i<=rows; i++){
//         for(int j = 1; j<=col; j++){
//             cout << "*";
//         }
//         cout << endl;
//     }
// }


// hollow rectangular pattern
// int main(){
//     int rows,col;
//     cout << "Enter the number of rows: ";
//     cin >>rows>>col;
//     for(int i =1; i<=rows; i++){
//         for(int j = 1; j<=col; j++){
//             if(i==1 || i==rows || j==1 || j==col){
//                 cout << "*";
//             } else {
//                 cout <<" ";
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }

// inverted half pyramid
// int main(){
//     int n;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     for(int i = n; i>=1; i--){
//         for (int j = 1; j<=i; j++){
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

// half pyramid after 180 degree rotation
// int main(){
//     int n;
//     cin>>n;
//     for (int i=1; i<=n; i++){
//         for (int j=1; j<=n; j++){
//            if(j<=n-i){
//                 cout << " ";
//               } else {
//                 cout << "*";
//            }
//         }
//         cout << endl;
//     }
//     return 0;
// }
