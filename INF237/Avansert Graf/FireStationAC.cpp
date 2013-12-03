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
//http://www.questtosolve.com/browse.php?pid=10278
using namespace std;
struct PairComparator 
{
  
bool operator()( pair<int,int> n1, pair<int,double> n2) 
    {  
	return n1.S > n2.S;
       }
    
};


int distTo[502];
int visited[502];
vector<pair<int,int> > node[502];
char inn[100];
int tab[600];
vector<int> fireS;


int finnMax(int n) {
	int maximus = 0;
	FOR(i,1,n) {
		if(distTo[i]>maximus)
			maximus = distTo[i];
	}
	return maximus;
}

int djikstra(int start, int n) {
	REP(i,n+1) {
		distTo[i] = 3000*3000*3000;
		visited[i] = 0;
	}
	if(start!=-1)node[0].PB(MP(start,0));
	distTo[0] = 0;
	int max=0;
	priority_queue<pair<int,int> , vector< pair<int,int> > , PairComparator> pq;
	pq.push(MP(0,0));
	while(!pq.empty()) {
		pair<int,int> akt = pq.top();
		pq.pop();
		REP(i,node[akt.F].size()) {
			pair<int,int> nabo = node[akt.F].at(i);
			if(visited[nabo.F]!=1 && distTo[akt.F]+nabo.S<=distTo[nabo.F]) {
					distTo[nabo.F] = distTo[akt.F]+nabo.S;
					if(distTo[akt.F]+nabo.S>max) max=distTo[akt.F]+nabo.S;
					pq.push(MP(nabo.F,distTo[nabo.F]));
			}
		}
		visited[akt.F] = 1;
	}
	if(start!=-1)
	node[0].pop_back();
	return finnMax(n);
}


int main(int argc, char *argv[]) {
	

string line;  
    int output = 0, cases;  
	int maxN;
    int n, nFire;  
    int a, b, d;  
    istringstream iss;  
	 
	 cin >> cases;  
	while (cases--)  {  
	 
	    cin >> nFire >> n;  
		int tab[600];
		memset(tab,0,sizeof(tab));
	    for (int c = 1; c <= nFire; c++)  {
				int ab;
	             cin >> ab;
				if(tab[ab]!=1) {
					node[0].PB(MP(ab,0));
					tab[ab]=1;
			}
		}
				

		 cin.ignore();  
		 while (getline(cin, line), line.length())  {  
	           iss.clear();  
 	           iss.str(line);  
 	           iss >> a >> b >> d;  
	      	   node[a].PB(MP(b,d));
			   node[b].PB(MP(a,d));
		      }  


			int beMax = 3000*3000*3000;
			if(nFire > 0) 
			  beMax = djikstra(-1,n);	
			int nMax=1;
	
			FOR(i,1,n) {
				if(tab[i]!=1) { //Sjekker om det er en brannstasjon
					int t = djikstra(i,n);
				if(t<beMax) {
					nMax=i;
					beMax=t;
				}	
			}
			}
	
		  if (output++)  
			     cout << endl;  
		cout << nMax << endl;  
		
		REP(i,n+1) node[i].clear();
  }
	
	return 0;

	
}