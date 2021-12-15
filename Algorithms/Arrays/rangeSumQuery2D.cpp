#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> preprocess(vector<vector<int>>& arr){
    vector<vector<int>> result(arr.size(),vector<int>(arr[0].size(),0));
    for(int i = 0; i < arr.size(); i++){
        result[i][0] = arr[i][0];
        for(int j = 1; j < arr[i].size(); j++){
            result[i][j] = arr[i][j] + result[i][j-1];
        }
    }
    return result;
}

int compute(vector<vector<int>>& sumMatrix, int row1, int col1, int row2, int col2){
    int sum = 0;
    for(int i = row1 ; i <= row2 ; i++){
        if(col1==0) 
            sum = sum + sumMatrix[i][col2];
        else 
            sum = sum + sumMatrix[i][col2] - sumMatrix[i][col1-1]; 
    }
    return sum;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int width,height;
    cin>>width>>height;
    vector<vector<int>> numMatrix(width,vector<int>(height,0));

    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
            cin>>numMatrix[i][j];
    
    vector<vector<int>> preSum = preprocess(numMatrix);

    for(int i = 0 ; i < preSum.size(); i++){
        for(int j = 0; j < preSum[i].size(); j++){
            cout<< preSum[i][j]<<" ";
        }
        cout<<endl;
    }

    int queries;
    cin>>queries;
    vector<vector<int>> queryList(queries,vector<int>(4,0));

    int row1,col1,row2,col2;
    for(int i = 0; i < queries; i++){
        for( int j = 0; j < 4; j++){
            cin>>queryList[i][j];
        }
    }

    vector<int> answer(queryList.size(),0);
    for(int i = 0 ; i < queryList.size(); i++){
        row1 = queryList[i][0];
        col1 = queryList[i][1];
        row2 = queryList[i][2];
        col2 = queryList[i][3];
        answer[i] = compute(preSum,row1,col1,row2,col2);
    }

    for(auto i : answer) cout<<i<<" ";

    return 0;
}