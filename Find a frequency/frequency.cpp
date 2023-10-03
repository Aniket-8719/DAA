#include<bits/stdc++.h> 
using namespace std; 
void findFrequency(int *arr, int n){ 
 map<int, int> m; 
for(int i = 0; i< n; i++){ 
 m[arr[i]]++; 
 } 
for(auto i = m.begin(); i != m.end(); i++){ 
cout<< "Frequency of " <<i->first << ": " <<i->second <<endl; 
 } 
cout<<endl; 
} 
int main(){ 
 int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
findFrequency(arr, sizeof(arr)/sizeof(arr[0])); 
 int arr1[] = {1, 2, 1, 2, 4, 5, 4, 3, 2, 1, 56, 9}; 

findFrequency(arr1, sizeof(arr1)/sizeof(arr1[0]));
 return 0; 
}