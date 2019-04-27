#include<bits/stdc++.h>

using namespace std;


int visited[100] = {0};
int visitf[100] = {0};
int visitedrev[100] = {0};
int t = 0;
int ri = 0;
int DFS(vector<int> v[], int i){
	t++;
	visited[i] = 1;
	visitedrev[ri] = i;
	ri++;
	for(int j = 0; j<v[i].size(); j++){
		if(!visited[v[i][j]]){
			DFS(v, v[i][j]);
		}
	}
	t++;
	visitf[i] = t;
	visited[i] = 2;
}


int main(){
	int V, E;
	vector <int> v[100], vr[100];
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		vr[b].push_back(a);
	}

	for(int i = 0; i<V; i++){
		if(!visited[i]){
			DFS(v, i);
		}
	}

	int indexarr[100];
	for(int i = 0; i<V; i++){
		int x = INT_MIN;
		for(int j = 0; j<V; j++){
			if(x<visitf[j]){
				x = visitf[j];
				indexarr[i] = j;
			}
		}
		visitf[indexarr[i]] = INT_MIN;
	}
	fill(visited, visited+V, 0);
	t = 0;
	for(int i = 0; i<V; i++){

		if(!visited[indexarr[i]]){
			ri = 0;
			DFS(vr, indexarr[i]);
			cout << "Strongly Connected Components: ";
			for(int i = 0; i<ri; i++){
				cout << visitedrev[i]<<" ";
				visitedrev[i] = 0;
			}
			cout << endl;
		}



	}

	return 0;
}


