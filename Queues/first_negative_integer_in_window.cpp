using namespace std;
#include <bits/stdc++.h>

void pushToWindow(vector<int>& source, deque <int>& window,int start, int end){
    for ( int i = start;i <= end; i++){
        while( !window.empty() && source[window.back()] <= source[i]) window.pop_back();
        window.push_back(i);  
    }
}
bool popFromWindow(deque<int>& window,int lastIndex,int windowSize){
    if( window.front() + windowSize - 1  ==  lastIndex ) return true;
    return false;
}

vector <int> calculateMaxms(vector<int> source, int winSize){
    deque <int> usefulValues;
    vector <int> maxmValues;
    for( int i = 0; i < source.size(); i++) 
        if ( source[i] <0 ) usefulValues.push_back(i);

    for (int i = 0; i < source.size() - winSize + 1; i++){
        //pushToWindow(source,usefulValues,i,i+winSize-1);
        maxmValues.push_back(source[usefulValues.front()]);

        if(popFromWindow(usefulValues,i+winSize-1,winSize)) {
            usefulValues.pop_front(); 
        }
        
       
    }
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

