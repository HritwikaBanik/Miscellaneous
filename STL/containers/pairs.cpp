#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    pair<int, string> p ;    //syntax 
    cin >> p.first ;         //How we access elements of pair
    cin >> p.second  ;       //taking user input 

    p = { 2 , "abcd"};       //Can be initialied this way or using make_pair(2,"abcd")
    pair<int , string> p2 = p;     //creating shallow copies
    p2.first = 3 ;                 
    cout << p.first << " "<<p.second <<" "<<endl;   //changing value in p1 wont reflect in p 
    pair<int , string> &p2 = p;    //creating deep copies
    p2.first = 3 ;
    cout << p.first << " "<<p.second <<" "<<endl;   //this will change the value in p 
   
   /*why was pair needed ? 
    *Suppose we have two arrays A , B of same length
    * we want to swap the first & last index element in both --> so we first pair them up and do
    * Makes easier for large group of mapped data and similar action 
    */
    int A[] ={1 ,2 ,3};
    int B[] = { 3 , 5 , 6};
    pair<int, int> arr[3];  //maps and pairs elements from both
    arr[0]={1,3};
    arr[1]={2,5};
    arr[2]= {3,6};

    swap(arr[0],arr[2]);   //1
    for(int i = 0 ; i < arr.sixe() ; i++){
        cout<<arr[i].first <<" "<<arr[i].second<<" "<<endl; //2
    }
    return 0;
}