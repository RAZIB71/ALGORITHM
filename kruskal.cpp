#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge
{
 int a, b, w;
};



vector<edge> edges;
int weightMST;
int par[100];

bool compare(edge a, edge b)
{
  return a.w < b.w;
}

void initDisjointSets(int n)
{
 for(int i=0; i<n; i++)
    par[i] = i;
}

int findparent(int x)
{
  if(par[x] == x)
    return x;
  else
    return findparent(par[x]);
}

bool isSameSet(int x, int y)
{
  return findparent(x) == findparent(y);
}

void dsUnion(int x, int y)
{

     par[findparent(y)] = findparent(x);

}

void kruskal(int v)
{
  sort(edges.begin(), edges.end(), compare);

  initDisjointSets(v);

  for(vector<edge>::iterator i= edges.begin(); i!=edges.end(); i++){
     edge e = *i;
     par[e.a] = findparent(e.a);
     par[e.b] = findparent(e.b);

     if(par[e.a] != par[e.b]){
        cout << e.a << "-" << e.b << " : " << e.w << endl;
        weightMST+= e.w;
        dsUnion(e.a, e.b);
     }
  }

}

int main()
{
  int v, e;

  cout << "Enter number of vertex: " << endl;
  cin >> v;
  cout << "Enter number of edges: " << endl;
  cin >> e;

  cout << "Enter the edges and their weights: " << endl;
  for(int i=1; i<=e; i++){
    edge x;
    cin >> x.a >> x.b >> x.w;
    edges.push_back(x);
  }

  cout << endl << "Edges of MST: " << endl;
  kruskal(v);

  cout << endl << "Weight of MST: " << weightMST << endl;

}
