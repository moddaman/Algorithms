#include <iostream>
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
#define Infinity 3000*3000*3000


using namespace std;
	
	
	
	
	int kuttet[60][60];
	int a[1002];

	
	
	int kutt(int start, int slutt) {

		if(kuttet[start][slutt] > -1){ 
			return kuttet[start][slutt];
		}
		if(slutt-start <= 1) {
			kuttet[start][slutt] = 0;
			return 0;
		}
		int billigst = INFINITY;
		for(int i = start+1; i < slutt; i++) {
			int venstre = kutt(start, i);
			int hoyre = kutt(i, slutt);
			int pris = a[slutt] - a[start];
			billigst =  min(pris + venstre + hoyre , billigst);
		}
		kuttet[start][slutt]=billigst;
		return billigst;
	
	}
	



	int main() {
	
	while(true) {
		int lengde, n;
		scanf("%d", &lengde);
		if(lengde < 1) break;
		memset(kuttet,-1,sizeof(kuttet));
		scanf("%d", &n);
		a[0] = 0;
		FOR(i,1, n) {
			int v;
			scanf("%d", &v);
			a[i] = v;
		}
		a[n+1] = lengde;
		int billigstePris = kutt(0, n+1);
		printf("The minimum cutting is %d.\n", billigstePris);
	}
	return 0;
}