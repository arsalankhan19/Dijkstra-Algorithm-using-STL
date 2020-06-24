#include<iostream>
#include<vector>
#include<set>
#define pb push_back
#define mp make_pair
#define INF 1000000000
using namespace std;

class Graph
{
private:

	int v;
	vector<pair<int,int>> *g;

public:

	Graph(int v){

		this->v = v;

		g = new vector<pair<int,int>>[v];
	}

	void addEdge(int x,int y,int w){

		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));
	}

	void printGraph(){

		for(int i=0;i<v;i++){

			cout<<i<<" -> ";

			for(auto p : g[i]){

				cout<<p.first<<" "<<p.second<<",";
			}
			cout<<endl;
		}
	}

	void dijsktra(int src)
	{
		int dist[v];        //if nodes are given int form of string then we had to take map

		for(int i=0;i<v;i++)   //updating distances as INF
			dist[i] = INF;

		set<pair<int,int>> s;

		dist[src] = 0;

		s.insert(mp(0,src));       //mp(distance,vertex)

		while(!s.empty()){

			auto p = *(s.begin());    //ye statement set ka pehla node dega

			int node = p.second;        
			int nodeDist = p.first;      //source se distance

			s.erase(s.begin());

			for(auto neigh : g[node]){

				int childnode = neigh.first;
				int childDist = neigh.second;

				if(nodeDist + childDist < dist[childnode]){

					auto f = s.find(mp(dist[childnode],childnode));    //purana node jo hai
					if(f != s.end()){
						s.erase(f);
					}

					dist[childnode] = nodeDist + childDist;

					s.insert(mp(dist[childnode],childnode));
				}

			}

		}

		for(int i=0;i<v;i++)
			cout<<dist[i]<<" ";

	}

};

int main()
{
	Graph g(9);

	g.addEdge(0,1,4);
	g.addEdge(0,7,8);
	g.addEdge(1,2,8);
	g.addEdge(1,7,11);
	g.addEdge(7,8,7);
	g.addEdge(6,7,1);
	g.addEdge(2,8,2);
	g.addEdge(2,3,7);
	g.addEdge(2,5,4);
	g.addEdge(6,8,6);
	g.addEdge(5,6,2);
	g.addEdge(3,5,14);
	g.addEdge(3,4,9);
	g.addEdge(4,5,10);

	// g.printGraph();
	g.dijsktra(0);


}

//to implement dijsktra we can take a vector of pairs i.e. vector<pair<int,int>> v[1001].