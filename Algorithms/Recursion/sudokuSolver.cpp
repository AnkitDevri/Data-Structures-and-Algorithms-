using namespace std;
#include<bits/stdc++.h>
int findMat(int& i,int& j){
  if(i<=2 && j<=2)
   return 0;

  else if(i<=2 && j<=5)
  return 1;

  else if(i<=2 && j<=8)
  return 2;

  else if(i<=5 && j<=2)
   return 3;

  else if(i<=5 && j<=5)
  return 4;

  else if(i<=5 && j<=8)
  return 5;

  else if(i<=8 && j<=2)
   return 6;

  else if(i<=8 && j<=5)
  return 7;

  else if(i<=8 && j<=8)
  return 8;

}
void solve(vector<vector<vector<int>>>& solutions,vector<vector<int>>& sudoku,vector<vector<int>>& row,vector<vector<int>>& col,vector<vector<int>>& mat,int i,int j){
    if(j/sudoku.size()>=1){
        i++;
        j=j%sudoku.size();
    }
 
    if(i==sudoku.size()){
        solutions.push_back(sudoku);
        return;
    }
    int r=i,c=j;
        if(sudoku[r][c]==0){
            for(int t=1;t<10;t++){

                int idx=findMat(r,c);
                if(row[r][t-1]==0 && col[c][t-1]==0 && mat[idx][t-1]==0){
                    
                    sudoku[r][c]=t;
                    row[r][t-1]=1;
                    col[c][t-1]=1;
                    mat[idx][t-1]=1;

                    solve(solutions,sudoku,row,col,mat,r,c+1);

                    sudoku[r][c]=0;
                    row[r][t-1]=0;
                    col[c][t-1]=0;
                    mat[idx][t-1]=0;

                }
                
            }
        }

}

int main(){
    
    int n,ele;
    n=9;

    vector<vector<int>> sudoku(n,vector<int>(n,0));
    vector<vector<vector<int>>> solutions;
    vector<vector<int>> rowCheck(n,vector<int>(n,0));
    vector<vector<int>> colCheck(n,vector<int>(n,0));
    vector<vector<int>> matCheck(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){

            cin>>ele;

            if(ele>0){

                sudoku[i][j]=ele;
                rowCheck[i][ele-1]=1;
                colCheck[j][ele-1]=1;
                matCheck[findMat(i,j)][ele-1]=1;

            }
        }
  /*   for(int i=0;i<n;i++){
         cout<<endl;
    for(int j=0;j<n;j++){
        cout<<sudoku[i][j]<<" ";
        }
     }
    */
    cout<<"Solutions...\n\n";
    for(int k=0;k<solutions.size();k++){
        cout<<"\n\n\n\n";
        for(int i=0;i<n;i++){
            cout<<"\n";
            for(int j=0;j<n;j++){
                cout<<solutions[k][i][j]<<" ";
            }
        }    
    }
    getchar();
    return 0;
}