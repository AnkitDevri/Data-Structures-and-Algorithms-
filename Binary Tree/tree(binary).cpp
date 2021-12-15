using namespace std;
#include<bits/stdc++.h>

class treeNode{
    public:
    int data;
    treeNode *left,*right;
    treeNode(int Nodedata){
        this->data=Nodedata;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class tree{
 public:
 treeNode* root;
 tree(){
     this->root=nullptr;
 }

 treeNode* insert(treeNode* root,int data){
     if(!root)
      return new treeNode(data);

    else{
        if(root->data>data)
        root->left=insert(root->left,data);

        else
        root->right=insert(root->right,data);
    }
    return root;
 }

int totalNodes(treeNode* root){
    if(!root)
    return 0;

    return totalNodes(root->left)+totalNodes(root->right)+1;
} 

int totalSum(treeNode* root){
    if(!root)
    return 0;
 return totalSum(root->left)+totalSum(root->right)+root->data;
}

 void Inorder(treeNode* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
void iterativePreorder(treeNode* root){
    vector<int> values;
    stack <treeNode*> callstack;
    if(root) callstack.push(root);
    while(!callstack.empty()){
        treeNode* node = callstack.top();
        callstack.pop();
        values.push_back(node->data);
        if(node->right) callstack.push(node->right);
        if(node->left) callstack.push(node->left);
    }
}

/*
 void checkBST(treeNode* root,long& prev,bool& answer){
        if(!root) return;
        checkBST(root->left,prev,answer);
        if(prev > root->data){
            answer = false;
            return;
        }
        prev = root->data;
        checkBST(root->right,prev,answer);
    }
    
    bool isValidBST(treeNode* root) {
        bool answer = true;
        long val = LONG_MIN;
        checkBST(root,val,answer);
        return answer;
    } */

    pair<long,long>checkBST(treeNode* root,bool& answer){
        if(!root) return make_pair(LONG_MAX,LONG_MIN);
        pair<int,int> leftVals = checkBST(root->left, answer);
        pair<int,int> rightVals = checkBST(root->right,answer);
        
        if(root->data < leftVals.second || root->data > rightVals.first ) answer = false;
        
        long MAX = max(leftVals.second,max(root->data,rightVals.second));
        long MIN = min(leftVals.first,min(root->data,rightVals.first));
        return make_pair(MIN,MAX);
    }
    
    bool isValidBST(treeNode* root) {
        bool answer = true;
        pair<long,long> values = checkBST(root,answer);
        return answer;
    }
};
int main(){
    tree binary;
    int total,element;
    cin>>total;
    for(int i=0;i<total;i++){
        cin>>element;
        binary.root=binary.insert(binary.root,element);
    }
    binary.Inorder(binary.root);
    cout<<endl<<binary.isValidBST(binary.root);
    //cout<<endl<<"Total Nodes: "<<binary.totalNodes(binary.root);
    //cout<<endl<<"Total sum of Nodes: "<<binary.totalSum(binary.root);
    getchar();
    return 0;
}