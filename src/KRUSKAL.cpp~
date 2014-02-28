#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#define ll long long 

using namespace std;

typedef pair<ll,pair<ll,ll> > edge;
typedef priority_queue<edge, vector<edge>, greater<edge> > min_heap;

vector<edge> MST(ll N, min_heap Q);

int main()
{
	ll t,p,n,m,a,b,c,i,sum;
	cin >> t;
	while(t--)
	{
		cin >> p;
		cin >> n;
		cin >> m;
		min_heap Q;
		for(i=0;i<m;i++)
		{
			cin >> a >> b >> c;
			Q.push(make_pair(c,make_pair(a,b)));
		}
		vector<edge> min_span(MST(n,Q));
		sum=0;
		for(i=0;i<min_span.size();i++)
		{
			sum+=min_span[i].first;
		}
		cout << (sum*p) << endl;
	}
	return 0;
}

vector<edge> MST(ll N,min_heap Q)
{
	vector<edge> mst;
	ll i;
	map<ll,ll> joined;
	for(i=1;i<=N;i++)
		joined[i]=i;
	
	while(!Q.empty())
	{
		int u=Q.top().second.first;
		int v=Q.top().second.second;
		int w=Q.top().first;

		int parent_u=joined[u];
		int parent_v=joined[v];

		if(parent_u != parent_v)
		{
			mst.push_back(make_pair(w,make_pair(u,v)));
			
			for(i=1;i<=N;i++)
			{
				if(joined[i] == parent_v)
					joined[i]=parent_u;
			}
		}
		Q.pop();
	}
	return mst;
}		
	

	
	

	
		
		
