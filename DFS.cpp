#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
int check[100];
int flag;

void DFS(int node){
    stack<int> s;
    check[node] = 1;
    s.push(node);
  while(!s.empty()){
        int u = s.top();
        s.pop();
 for(int i=0; i<graph[u].size(); i++){
            int temp = graph[u][i];
            if(temp == node){
                cout << "\nYes Found." << endl;
                flag=1;
                return;
            }
            check[temp]++;
            if(check[temp] < 2)
                s.push(temp);
        }
    }
}

int main() {
	int vertex;
	int edge;
	int node;
	cout << "Enter no. of vertex :";
	cin >> vertex ;
	cout<<endl;
	cout << "Enter no. of edge :";
	cin >> edge ;
	cout<<endl;
    cout << "Enter the nodes with adjacency : " << endl;
	for(int i=0; i<edge; i++){
        int p, q;
        cin >> p >> q;
        graph[p].push_back(q);
	}
    cout << "Enter the source node : ";
	cin >> node;
	DFS(node);
	if(flag!=1)
        cout << "\nNot Found." << endl;
	return 0;
}

