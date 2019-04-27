#include<bits/stdc++.h>
using namespace std;
typedef vector<int>:: iterator vit;
int visited[100]= {0};

int bfs(vector<int> v[],int s)
{
    visited[s]=1;
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        cout<<n<<" ";
        for(vit i=v[n].begin(); i!=v[n].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i]=1;
                q.push(*i);
            }

        }
    }

}

int main()
{
    vector<int> v[100];
    int vtx,edg;
    cout<<"no. of vertex and edges : ";
    cin>>vtx>>edg;
    cout<<"node connections :"<<endl;

    for(int i=0; i<edg; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    int s;
    cout<<"source : ";
    cin>>s;
    bfs(v,s);





}
