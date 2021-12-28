using namespace std;
#include<bits/stdc++.h>

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<vector<int>> nodeList(size,vector<int>(2,0));
    for(int i = 0 ; i < nodeList.size(); i++){
        cin>>nodeList[i][0];
        cin>>nodeList[i][1];
    }

    unordered_map <int,vector<int>> nArrayTree;

    for(int i = 0; i < nodeList.size(); i++){

        if(nArrayTree.find(nodeList[i][0]) == nArrayTree.end()){
            vector<int> temp;
            temp.push_back(nodeList[i][1]);
            nArrayTree.insert({nodeList[i][0],temp});
        }
        else nArrayTree[nodeList[i][0]].push_back(nodeList[i][1]);
        
        if(nArrayTree.find(nodeList[i][1]) == nArrayTree.end()){
            vector<int> temp;
            temp.push_back(nodeList[i][0]);
            nArrayTree.insert({nodeList[i][1],temp});
        }
        else nArrayTree[nodeList[i][1]].push_back(nodeList[i][0]);
    }


    for( auto i : nArrayTree){
        for( int j = 0; j < i.second.size(); j++) 
            cout<<i.second[j]<<" ";
        cout<<endl;
    }
    return 0;
}
