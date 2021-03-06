#include<iostream>

using namespace std;

struct item
{
  int w, p;
}items[100];

int ks[100][100];

int knapsack(int n, int w)
{
    if(ks[n][w]!=0)
        return ks[n][w];

    if(n<0)
        return ks[n][w]=0;

    if(items[n].w > w)
        return ks[n][w] = knapsack(n-1, w);

    return ks[n][w] = max(items[n].p + knapsack(n-1, w-items[n].w), knapsack(n-1, w));
}

int main()
{
  int N, W;
  cout << "Enter number of items and maximum weight: " << endl;
  cin >> N >> W;

  cout << "Enter items :" << endl;
  for(int i=0; i<N; i++)
    cin >> items[i].w >> items[i].p;

  knapsack(N, W);
  cout << "Maximum profit = " << ks[N][W] << endl;

  return 0;
}


/*

2 7
6 6
14 7

3 10
6 4
5 5
4 4

3 9
6 6
5 5
4 4

4 10
5 18
2 9
4 12
6 25

*/
