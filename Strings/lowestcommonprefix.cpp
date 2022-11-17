    #include<bits/stdc++.h>
    using namespace std;
    
    string longestCommonPrefix(vector<string>& strs) {
        int index = INT_MAX;
        
        string first = strs[0];
        
        for(int i=1;i<strs.size();i++){
            int j=0, k=0, c=0;
            string temp = strs[i];
            
            while(first[j]==temp[k] && j<first.length() && k<temp.length()){
                c++;
                j++;
                k++;
            }
            index = min(index, c);
        }
        return strs[0].substr(0, index);
    }
    
    int main(){
        int n;
        cin>>n;
        vector<string> strs(n);
        for(int i=0;i<n;i++){
            cin>>strs[i];
        }
        cout<<longestCommonPrefix(strs);
    }