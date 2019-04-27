#include<bits/stdc++.h>
using namespace std;
int visited[100]={0};

int dfs(vector<int> v[],int s)
{
    visited[s]=1;
    stack<int> stk;
    stk.push(s);

    while(!stk.empty())
    {
        int n=stk.top();
        for(int i=0;i<v[n].size();i++)
        {
            if(!visited[v[n][i]])
            {
                dfs(v,v[n][i]);
            }
        }
        int t=stk.top();
        stk.pop();
        cout<<t<<" ";
    }

}

int main()
{
    vector<int> v[100];
    int vtx,edg;
    cout<<"enter number of vertex: ";
    cin>>vtx;
    cout<<endl;
    cout<<"enter number of edges: ";
    cin>>edg;
    cout<<"enter node connection"<<endl;

    for(int i=0;i<edg;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int s;

    cout<<"enter source :";
    cin>>s;

    dfs(v,s);

}








