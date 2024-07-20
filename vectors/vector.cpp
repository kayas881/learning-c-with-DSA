#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// vector in c++ is a sequence container that encapsulates dynamic size arrays
// vector is a template class that takes 3 parameters
// vector <int> v; //declaration of vector
// vector <int> v(5,10); //declaration of vector with 5 elements with value 10
// vector <int> v2(v); //declaration of vector v2 with v
// vector <int> v3(v.begin(),v.end()); //declaration of vector v3 with v from begin to end
// vector <int> v4{10,20,30}; //declaration of vector v4 with 10,20,30


// v.push_back() is used to add elements in the vector
// v.pop_back() is used to remove the last element in the vector
// v.size() is used to get the size of the vector
// v.begin() is used to get the starting element of the vector
// v.end() is used to get the ending element of the vector
// v.clear() is used to clear the vector
// v.empty() is used to check if the vector is empty
// v.front() is used to get the first element of the vector
// v.back() is used to get the last element of the vector



// pair in c++ is a container to store a pair of objects
// pair <int, char> p;


// myCompare function to sort the pair of objects
bool myCompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first; // return true if p1 is less than p2
};


//explaining the use of vector and pair
//here in main function we are taking an array and storing the index of the array in the pair
//then we are sorting the pair and storing the index in the array
//this is done to store the index of the array in the sorted order
//then we are printing the array


int main(){

    //vector is used as an dynamic array
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i =0; i<v.size();  i++){
        cout<<v[i]<<endl;
    }

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end(); it++){
        cout<<*it<<endl;
    }

    // auto is used to automatically declare a initial variable
    for(auto element:v){
        cout<<element<<endl;
    }

    // to remove the ending element
    v.pop_back();
    vector<int> v2 (3,50) ;

    //to swap values for v and v2
    swap(v,v2);

    for(auto element:v){
        cout<<element<<endl;
    }


    //pair is a container to store pair of objects
    pair<int,char> p;
    p.first = 3;
    p.second = 'a';




    return 0;
}


int main(){
    int arr[]= {10,16,7,14,5,3,12,9};
    vector < pair<int,int> > v;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
    v.push_back(make_pair(arr[i],i));
    }

    sort(v.begin(),v.end(), myCompare);
    for(int i =0;i< v.size(); i++){
        arr[v[i].second]=i;
    }

     for(int i =0;i< v.size(); i++){
       cout<<arr[i]<<" ";
    }
     return 0;
}


