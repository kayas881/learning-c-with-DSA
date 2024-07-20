#include <iostream>
#include <string>
using namespace std;



// here in reverse function we are reversing a string
// if the length of the string is 0 then we return
// else we call the function reverse with the rest of the string and print the first character
// for example s = "abc"
// output = "c b a"
void reverse(string s){
    if(s.length()==0){
        return;
    }

    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0]<<" ";
}


// here in replacePi function we are replacing the pi with 3.14
// if the length of the string is 0 then we return
// else we check if the first two characters are pi
// if they are then we print 3.14 and call the function replacePi with the rest of the string
// else we print the first character and call the function replacePi with the rest of the string
// for example s = "pippppiiiipi"
// output = "3.14 pppp 3.14 iii 3.14"
void replacePi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14"<<" ";
        replacePi(s.substr(2));
    } else{
        cout<<s[0]<<" ";
        replacePi(s.substr(1));
    }
}

// duplicates function removes the duplicates from the string
// if the length of the string is 0 then we return ""
// else we check if the first character is equal to the first character of the rest of the string
// if they are equal then we call the function duplicates with the rest of the string
// else we return the first character and call the function duplicates with the rest of the string
// for example s = "aaabbbccc"
// output = "abc"
string duplicates(string s){
    if(s.length()==0){
        return "";
    }
   char ch = s[0];
 string ans =  duplicates(s.substr(1));
 if(ch==ans[0]){
    return ans;
 }
 return (ch+ans);

}

// movellX function moves all the x to the end of the string
// if the length of the string is 0 then we return ""
// else we check if the first character is x
// if it is then we call the function movellX with the rest of the string and add x to the end
// else we return the first character and call the function movellX with the rest of the string
// for example s = "axbxc"
// output = "abcx"
string movellX(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = movellX(s.substr(1));
    if(ch=='x'){
        return (ans+ch); 
    }
    return (ch+ans);

}

// subseq function prints all the subsequences of a string
// if the length of the string is 0 then we print the answer
// else we take the first character of the string and the rest of the string
// and call the function subseq with the rest of the string and the answer
// and call the function subseq with the rest of the string and the answer+first character
// for example s = "abc"
// output = "","c","b","bc","a","ac","ab","abc"
void subseq(string s, string ans){
    if(s.length()==0){
       cout<<ans<<endl;
       return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    
    subseq(ros,ans);
    subseq(ros,ans+ch);

}



// here in subseq function we are printing all the subsequences of a string
// if the length of the string is 0 then we print the answer
// else we take the first character of the string and the rest of the string
// and call the function subseq with the rest of the string and the answer
// and call the function subseq with the rest of the string and the answer+first character
// for example s = "abc"
// output = "","c","b","bc","a","ac","ab","abc"
void subsq(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subsq(ros, ans);
    subsq(ros, ans + ch);
    subsq(ros,ans + to_string(code));
}



// here in perm function we are printing all the permutations of a string
// if the length of the string is 0 then we print the answer
// else we take the first character of the string and the rest of the string
// and call the function perm with the rest of the string and the answer+first character
// for example s = "abc"
// output = "abc","acb","bac","bca","cab","cba"
void perm(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string ros = s.substr(0,i)+s.substr(i+1);

        perm(ros,ans+ch);
    }
}