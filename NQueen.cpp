#include<bits/stdc++.h>
using namespace std;
int board[100][100];
int n;
bool s(int r, int c){

  for(int i=r; i>=0; i--)
    if(board[i][c] == 1) return false;

  for(int i=r, j=c; i>=0 && j>=0; i--, j--)
    if(board[i][j] == 1) return false;

  for(int i=r, j=c; i>=0 && j<n; i--, j++)
    if(board[i][j] == 1) return false;


  return true;
}

bool nq(int r){

  if(r>=n)
    return true;

  for(int i=0; i<n; i++){

     if(s(r, i)){

        board[r][i] = 1;

        if(nq(r+1))
          return true;
        else
          board[r][i] = 0;

     }

  }

  return false;
}

int main(){

  cout << "Enter n for n*n board: " << endl;
  cin >> n;

  nq(0);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
        cout << (board[i][j]==0? "*" : "Q") << "\t";
    cout << endl;
  }

  cout << endl;

  return 0;
}

