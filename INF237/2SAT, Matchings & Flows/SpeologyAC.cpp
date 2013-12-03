#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include<iostream>
#include<sstream>

    
#define REP(i,n) for(int _n=(n),i=0; i<_n; ++i)
#define FOR(i,a,b) for(int _b=(b),i=(a); i<= _b; ++i)
#define FORD(i,a,b) for(int _b=(b),i=(a); i>=_b; --i)

#define PB push_back
#define BEG begin()
#define END end()
#define SZ s()
#define MP make_pair
#define F first
#define S second
#define D double
#define LL long long
#define LD long double
#define VI vector<int>
#define INF 3000*3000*3000


using namespace std;

vector<int> naboer[250];
int visited[250];
int n;
vector<int> graf[250];
int vekt[250][250];
int parNode[250];
int kanter[250];

int v, e;
int s, t;

vector<int> lagSett(int start) {
	vector<int> sett;
	bool flagg = false;
	memset(visited, 0,sizeof(visited));
	queue<int> qu;
	qu.push(start);
	while(!qu.empty()) {
		int akt = qu.front();
		qu.pop();
		REP(i,naboer[akt].size()) {
			int nab = naboer[akt].at(i);
			if(nab==n) sett.PB(akt);
			if(visited[nab]!=1) {
				qu.push(nab);
				visited[nab] = 1;
			}
		}
		visited[akt] = 1;
	}
return sett;
}

void print() {
	printf("\n\n");
	printf("  ");
	FOR(i,1,t)printf(" %d ",i);
	printf("\n");
	FOR(i,1,t) {
		printf("%d ",i);
		FOR(j,1,t) {
			printf(" %d ",vekt[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");	
}


int bfs() {
    int ret = 0;
    for (int i=1;i<=v;i++) parNode[i] = 0;
    queue<int> qu;
    queue<int> minimumVekt;
    parNode[s] = -1;
    qu.push(s);
    minimumVekt.push(INF);
    while (!qu.empty())   {
        int fra = qu.front();
        int minVekt = minimumVekt.front();
        qu.pop();
        minimumVekt.pop();
        for (int i=0;i<graf[fra].size();i++) {	
            int til = graf[fra][i];
            if (vekt[fra][til] > 0 && parNode[til] == 0) {
                qu.push(til);
                minimumVekt.push(min(minVekt,vekt[fra][til]));
                parNode[til] = fra;
                if (til == t)
                {	
                    ret = min(minVekt, vekt[fra][til]); //1
                    break;
                }
            }
        }
    }
    if (ret > 0) {
        int node = t;
        while (node != s) { 
            vekt[parNode[node]][node] -= 1;
            vekt[node][parNode[node]] += 1;
            node = parNode[node];
        }
    }
    return ret;
}


int main(int argc, char *argv[]) {
	
	queue<int> q;
	scanf("%d",&n);
	int sP;
	scanf("%d",&sP);
	REP(k,sP) {
		int nabo;
		scanf("%d",&nabo);
		q.push(nabo);
	}
	
	FOR(i,2,n-1) {
		int paths;
		scanf("%d",&paths);
		REP(j,paths) {
			int nabo;
			scanf("%d",&nabo);
			if(nabo<=n)
			naboer[i].PB(nabo);
		}
	}
	memset(kanter,0,sizeof(kanter));
	v = n, 
	s = 1, t = n;
	while(!q.empty()) {
		int a = q.front();
		vector<int> ab = lagSett(a);
		graf[s].PB(a);
		graf[a].PB(s);
		vekt[s][a] = s;
		e+=1;
		REP(i,ab.size()) {
			int b = ab[i];
			graf[a].PB(b);
			graf[b].PB(a);
			vekt[a][b] = 1;
			e+=1;
			if(kanter[b]!=1) {
				graf[b].PB(v);
				graf[v].PB(b);
				vekt[b][v] = 1;
				kanter[b] = 1;
				e+=1;
			}
		}
		q.pop();
	}
	int maxF = 0;
	    while (true)
	    {
	        int flow = bfs();
	        if (flow == 0) break;
	        else maxF += flow;
	    }
	 printf("%d",maxF);

	
	
}