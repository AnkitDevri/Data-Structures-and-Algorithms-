using namespace std;
#include <bits/stdc++.h>

void pushToWindow(vector<int>& source, deque <int>& window,int start){
    //for ( int i = start;i <= i + winSize - 1; i++){
        while( !window.empty() && source[window.back()] <= source[start]) window.pop_back();
        window.push_back(start);  
    //}
}
bool popFromWindow(deque<int>& window,int lastIndex,int windowSize){
    int i = lastIndex;
    if( window.front() + windowSize - 1  ==  lastIndex ) return true;
    return false;
}

vector <int> calculateMaxms(vector<int> source, int winSize){
    deque <int> usefulValues;
    vector <int> maxmValues;
    for (int i =0; i < winSize; i++)
    pushToWindow(source,usefulValues,i);

    for (int i = winSize; i < source.size(); i++){
        maxmValues.push_back(source[usefulValues.front()]);
        int j = usefulValues.front();
        if(popFromWindow(usefulValues,i+winSize-1,winSize)) {
            usefulValues.pop_front(); 
        }
        pushToWindow(source,usefulValues,i);
        
       
    }
    if(popFromWindow(usefulValues,source.size()+winSize-1,winSize)) {
            usefulValues.pop_front(); 
        }
    if(!usefulValues.empty())maxmValues.push_back(source[usefulValues.front()]);
    return maxmValues;
    
}
int main(){
    int size,windowSize,ele;
    scanf("%d", &size);
    scanf("%d",&windowSize);
    vector <int> source;
    for ( int i = 0; i < size; i++) {
        scanf("%d",&ele);
        source.push_back(ele);
    }
    vector <int> maxmsInSlidingWindow = calculateMaxms(source, windowSize);

    for ( auto i : maxmsInSlidingWindow) cout<< i<<" ";
    return 0;
}