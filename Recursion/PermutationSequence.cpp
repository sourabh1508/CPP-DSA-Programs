    #include<bits/stdc++.h>
    using namespace std;
    
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact = fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans;
        k = k-1;
        while(nums.size()!=0){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            k = k%fact;
            if(nums.size()!=0)
                fact = fact/nums.size();
        }
        return ans;
    }


int main(){
    int n, k;
    cin>>n>>k;
    cout<<getPermutation(n, k);
} 