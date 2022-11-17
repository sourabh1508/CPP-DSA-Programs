#include<bits/stdc++.h>
using namespace std;

int minCostRopes(int arr[], int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int cost = 0;
    while(pq.size() > 1){
        int sum = 0;
        int firstMin = pq.top();
        pq.pop();
        int secondMin = pq.top();
        pq.pop();

        sum = firstMin + secondMin;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main(){
    int arr[] = {2, 5, 4, 8, 6, 9};
    int n=6;
    cout<<minCostRopes(arr, n);
    return 0;
}