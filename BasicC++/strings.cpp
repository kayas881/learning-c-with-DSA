#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// int main(){
//     string str;
//     cin>>str;

//     cout<<"is this what you wrote:"<<" "<<str<<endl;


//     return 0;
// }

// int main(){
//     string str;
//     getline(cin, str);

//     cout<<str<<endl;

//     return 0;
// }

// int main(){
//     string s1 = "fam";
//     string s2 = "ily";

//     s1.append(s2);

//     cout<<s1<<endl;
//     return 0;
// }


int main(){
    string s = "asandksaidnma";

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    cout<<s<<endl;
}
