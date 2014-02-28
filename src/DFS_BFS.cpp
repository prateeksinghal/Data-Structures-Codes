/* Program Performs :
    -> Depth First Search
    -> Breadth First Search
    on the GRAPH
    
    SPOJ: http://www.spoj.com/problems/TDBFS/
    
*/

#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v,bool visited[]);
public:
	Graph(int V);
	void add_edge(int v,int w);
	void DFS(int v);
	void BFS(int v);
};

Graph::Graph(int V)
{
	this->V=V;
	adj = new list<int>[V];
}

void Graph::add_edge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v,bool visited[])
{
	visited[v]=true;
	printf("%d ",(v+1));	
	list<int>::iterator i;
	for(i=adj[v].begin();i != adj[v].end(); ++i)
	{
		if(!visited[*i])
			DFSUtil(*i,visited);
	}

}


void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;

	DFSUtil(v,visited);
	
}

void Graph::BFS(int v)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	
	list<int> queue;
	visited[v]=true;
	queue.push_back(v);
	
	list<int>::iterator i;

	while(!queue.empty())
	{
		v=queue.front();
		printf("%d ",(v+1));	
		queue.pop_front();

		for(i=adj[v].begin(); i != adj[v].end(); i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
	
}

int main()
{
	int t,n,j,i,m,k,a,v,c=0,Q;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d",&n);
		Graph g(n);
		for(j=0;j<n;j++)
		{
			scanf("%d %d",&i,&m);
			for(k=0;k<m;k++)
			{
				scanf("%d",&a);	
				g.add_edge(i-1,a-1);
			}
		}
		printf("graph %d\n",(++c));
		while(1)
		{
		    scanf("%d %d",&v,&Q);
		    if(v==0 && Q==0)
		      break;
			if(Q==0)
			{
				g.DFS(v-1);
				printf("\n");
				continue;
			}
			g.BFS(v-1);
			printf("\n");
		}
	}
	return 0;
}
				
