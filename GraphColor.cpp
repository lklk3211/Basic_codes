#include <bits/stdc++.h>
using namespace std;

bool isSafe(bool** edges,int v,int* color,int c, int n){
	for(int i=0;i<n;i++){
		if(edges[v][i] && color[i]==c) return false;
	}
	return true;
}

bool colorGraph(bool** edges,int v,int* color,int c,int n){
	if(v==n) return true;
	for(int i=1;i<=c;i++){
		if(isSafe(edges,v,color,i,n)){
			color[v] = i;
			if(colorGraph(edges,v+1,color,c,n)) return true;
			color[v]=0;
		}
	}
	return false;
}

int main() {
	int v,e;
	cin>>v>>e;
	bool** edges = new bool*[v];
	for(int i=0;i<v;i++){
		edges[i] = new bool[v];
		for(int j=0;j<v;j++){
			edges[i][j] = 0;
		}
	}
	while(e--){
		int f,s;
		cin>>f>>s;
		edges[f-1][s-1] = 1;
		edges[s-1][f-1] = 1;
	}
	int c;
	cin>>c;
	int* color = new int[v]();
	if(colorGraph(edges,0,color,c,v)){
		for(int i=0;i<v;i++){
			cout<<i+1<<" : "<<color[i]<<endl;
		}
	}
	return 0;
}
