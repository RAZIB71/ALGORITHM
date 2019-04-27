#include<bits/stdc++.h>
using namespace std;
int visited[100] = {0};
stack<int> s;
void DFS(vector<int> vec[], int i){
	visited[i] = 1;
	for(int j = 0; j<vec[i].size(); j++){
		if(!visited[vec[i][j]]){
			DFS(vec, vec[i][j]);
		}
	}
	visited[i] = 2;
	s.push(i);
}

int main(){

	vector <int> vec[100];
	int V, E;
	cin >> V >> E;
	for(int i = 0; i<E; i++){
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	cout<<endl;
	for(int i = 0; i<V; i++){
		if(!visited[i]){
			DFS(vec, i);
		}
	}
	while(!s.empty()){
		int x = s.top();
		s.pop();
		cout << x << " ";
	}
}


