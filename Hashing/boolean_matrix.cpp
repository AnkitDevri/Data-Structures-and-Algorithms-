using namespace std;
#include <bits/stdc++.h>
void get_result ( vector< vector <int>>& mat) {
    vector <int> row(mat.size(),0);
    vector <int> col(mat[0].size(),0);
    for ( int i = 0; i < mat.size(); i++){ 
        for ( int j = 0; j < mat[i].size(); j++){
            if( mat[i][j] ){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for ( int i = 0; i < mat.size(); i++){
        for ( int j = 0 ; j < mat[i].size(); j++) {
            if( row[i] == 1 || col[j] == 1) {
                mat[i][j] = 1;
            }
        }
    }
}
int main() {
    int rows, columns;
    scanf("%d", &rows);
    scanf("%d", &columns);

    vector <vector <int>> matrix(rows, vector <int>(columns, 0));

    for ( int i = 0; i < rows; i++){ 
        for ( int j = 0; j < columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    get_result(matrix);

    for ( int i = 0; i < rows; i++){ 
        for ( int j = 0; j < columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}