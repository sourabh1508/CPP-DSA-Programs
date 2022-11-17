#include<bits/stdc++.h>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void balanceHeaps();

void insertHeap(int &x)
    {
        if(maxHeap.size() == 0)
            maxHeap.push(x);
        else if(x < maxHeap.top())
            maxHeap.push(x);
        else
            minHeap.push(x);
        
        balanceHeaps();
    }

void balanceHeaps()
    {
        if(maxHeap.size() > minHeap.size() && maxHeap.size() - minHeap.size() > 1){
            int t = maxHeap.top();
            maxHeap.pop();
            minHeap.push(t);
        }
        else if(maxHeap.size()<minHeap.size() && minHeap.size() - maxHeap.size() > 1){
            int t = minHeap.top();
            minHeap.pop();
            maxHeap.push(t);
        }
    }


double getMedian()
    {
        if(maxHeap.size() == minHeap.size()){
            double med = (maxHeap.top() + minHeap.top())/2.0;
            return med;
        }
        else{
            if(maxHeap.size() > minHeap.size()){
                return maxHeap.top();
            }
            else{
                return minHeap.top();
            }
        }
    }

int main(){
    int n, x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        insertHeap(x);
        cout<<getMedian()<<endl;
    }
    return 0;
}