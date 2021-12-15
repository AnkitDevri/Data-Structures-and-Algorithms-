using namespace std;
#include <bits/stdc++.h>
vector<vector<int>> countMat(100,vector<int>(100,0));

vector<vector<int>> preprocess (vector<vector<int>>& stars,int maxBrightness){
    vector<vector<int>> answer(100, vector<int>(100,0));

    for(int i = 0; i < stars.size(); i++){
        answer[stars[i][0] - 1][stars[i][1] - 1] =  stars[i][2] % maxBrightness;
        countMat[stars[i][0] - 1][stars[i][1] - 1]++;
    }
    
    for(int i = 0; i < 100; i++)
        for(int j = 1 ; j < 100; j++){
            answer[i][j] = answer[i][j - 1] + answer[i][j];
            countMat[i][j] = countMat[i][j - 1] + countMat[i][j];
        }
        
    return answer;
            
}
int computeSum(vector<vector<int>>& sumMatrix, int row1, int col1, int row2, int col2, int MaxBrightness, int moment){
    int starCount,sum = 0;
    for(int i = row1 ; i <= row2 ; i++){
        if(col1 == 0){
            starCount = countMat[i][col2];
            sum = sum + (sumMatrix[i][col2] % MaxBrightness + (moment*starCount));
        }
        else {
            starCount = countMat[i][col2] - countMat[i][col1-1];
            sum = sum + (sumMatrix[i][col2] - sumMatrix[i][col1-1]) % MaxBrightness + (moment*starCount); 
        }
    }
    return sum;
}

vector<int> compute(vector<vector<int>>& views, vector<vector<int>>& preprocessed, int maxBrightness){
    vector<int> answer;
    int moment,x1,y1,x2,y2,sum;
    for(int i = 0 ; i < views.size(); i++){
        moment = views[i][0];
        x1 = views[i][1] - 1;
        y1 = views[i][2] - 1;
        x2 = views[i][3] - 1;
        y2 = views[i][4] - 1;
        sum = computeSum(preprocessed,x1,y2,x2,y1,maxBrightness,moment);
        answer.push_back(sum);
    }
    return answer;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int numStars, numViews, maxBrightness;
    cin>>numStars>>numViews>>maxBrightness;

    vector<vector<int>> stars(numStars, vector<int>(3,0));

    for(int i = 0; i < numStars; i++){
        cin>>stars[i][0]; // x coordinate
        cin>>stars[i][1]; // y coordinate
        cin>>stars[i][2]; // intial brightness
    }

    vector<vector<int>> views(numViews,vector<int>(5,0));
    for(int i = 0; i < numViews; i++){
        cin>>views[i][0]; // t moment
        cin>>views[i][1]; // x lower left rectangle
        cin>>views[i][2]; // y lower left rectangle
        cin>>views[i][3]; // x upper right rectangle
        cin>>views[i][4]; // y upper right rectangle
    }
    vector<vector<int>> preprocessed = preprocess(stars,maxBrightness);
    vector<int> answer = compute(views,preprocessed,maxBrightness);

    for(int i = 0 ; i < answer.size(); i++)
        cout<< answer[i]<< endl;

    return 0;
}