

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    vector<vector<int>> visited;
	Solution(){
		for(int i = 0; i < 1000; i++){
			vector<int> vec(1000,0);
			visited.push_back(vec);
		}
	}
    vector<pair<int,int>> generateValidMoves(vector<int>& KnightPos,int N){
        vector<pair<int,int>> validMoves;
        
        if((KnightPos[0]-1 >0 && KnightPos[0]-1 <= N) && (KnightPos[1]-2>0 && KnightPos[1]-2 <= N)) validMoves.push_back({KnightPos[0]-1 ,KnightPos[1]-2});
        if((KnightPos[0]-1 >0 && KnightPos[0]-1 <= N) && (KnightPos[1]+2>0 && KnightPos[1]+2 <= N)) validMoves.push_back({KnightPos[0]-1 ,KnightPos[1]+2});
        if((KnightPos[0]+1 >0 && KnightPos[0]+1 <= N) && (KnightPos[1]-2>0 && KnightPos[1]-2 <= N)) validMoves.push_back({KnightPos[0]+1 ,KnightPos[1]-2});
        if((KnightPos[0]+1 >0 && KnightPos[0]+1 <= N) && (KnightPos[1]+2>0 && KnightPos[1]+2 <= N)) validMoves.push_back({KnightPos[0]+1 ,KnightPos[1]+2});
        if((KnightPos[0]-2 >0 && KnightPos[0]-2 <= N) && (KnightPos[1]-1>0 && KnightPos[1]-1 <= N)) validMoves.push_back({KnightPos[0]-2 ,KnightPos[1]-1});
        if((KnightPos[0]-2 >0 && KnightPos[0]-2 <= N) && (KnightPos[1]+1>0 && KnightPos[1]+1 <= N)) validMoves.push_back({KnightPos[0]-2 ,KnightPos[1]+1});
        if((KnightPos[0]+2 >0 && KnightPos[0]+2 <= N) && (KnightPos[1]-1>0 && KnightPos[1]-1 <= N)) validMoves.push_back({KnightPos[0]+2 ,KnightPos[1]-1});
        if((KnightPos[0]+2 >0 && KnightPos[0]+2 <= N) && (KnightPos[1]+1>0 && KnightPos[1]+1 <= N)) validMoves.push_back({KnightPos[0]+2 ,KnightPos[1]+1});
        
        return validMoves;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    pair<int,int> target = make_pair(TargetPos[0],TargetPos[1]);
	    queue<pair<int,int>> line;
	    int count = 0;
	    line.push(make_pair(KnightPos[0],KnightPos[1]));
	    visited[KnightPos[0]][KnightPos[1]] = 1;
	    while(!line.empty()){
            int idx = 1;
            int size = line.size();
            while(idx<=size){
                 pair<int,int> curr = line.front();
                line.pop();
                if(curr == target) return count;
	            vector<int> sample;
	            sample.push_back(curr.first);
	            sample.push_back(curr.second);
	            vector<pair<int,int>> validMoves = generateValidMoves(sample,N);
	            for( int i = 0; i < validMoves.size(); i++){
	                if(visited[validMoves[i].first][validMoves[i].second] == 0){
	                    line.push(validMoves[i]);
	                    visited[validMoves[i].first][validMoves[i].second] = 1;
	                }
	            }
                idx++;
            }
	        count++;
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends