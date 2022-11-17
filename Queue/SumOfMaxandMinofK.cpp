#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    
    deque<int> maxi;
    deque<int> mini;

    for(int i=0;i<k;i++){   //for 1st k elements
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    int res = 0;

    res += arr[maxi.front()] + arr[mini.front()];

    for(int i=k;i<n;i++){ //for k to n elements 

        
        //removal
        if(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }
        if(!maxi.empty() && i - mini.front() >= k){
            mini.pop_front();
        }

        //addition
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        res += arr[maxi.front()] + arr[mini.front()];
    }
    
    cout<<res<<endl;
    return 0;
}