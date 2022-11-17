	#include<bits/stdc++.h>
    using namespace std;
    
    void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if((matrix[i][j] == -1 || matrix[i][k] + matrix[k][j] < matrix[i][j]) && matrix[i][k]!=-1 && matrix[k][j]!=-1)
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	            }
	        }
	    }
	}

    int main(){
        int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
        shortest_distance(matrix);
        for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout <<endl;
		}
    }