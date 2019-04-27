
#include <bits/stdc++.h>

using namespace std;
int mat[101][101];

int main()
{
    int n, v, c;
    vector <int> coins;
    coins.push_back(0);
    cin >> n >> v;
    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= v; j++) {
            mat[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i <= n; i++) {
        mat[i][0] = 0;
    }
    for(int i = 0; i <= v; i++) {
        mat[0][i] = INT_MAX;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= v; j++) {
            if(j < coins[i])
                mat[i][j] = mat[i - 1][j];
            else if(j >= coins[i]) {
                if(mat[i][j - coins[i]] == INT_MAX) {
                    mat[i][j] = min(mat[i][j - coins[i]], mat[i-1][j]);
                }
                else
                    mat[i][j] = mat[i][j - coins[i]] + 1;
            }
        }
    }
    if(mat[n][v] == INT_MAX)
        mat[n][v] = -1;
    cout << mat[n][v] << endl;

    return 0;
}
