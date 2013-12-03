

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


using namespace std;
int find(int p, int id[]) {
		while(p != id[p]) {
			p = id[id[p]];
			p = id[p];
		}
		return p;
	}


int main() {
	
	int k,n;
	int sm=0;
	scanf("%d", &k);
	n = k + 1;	
	int id[n];
	int s[n];
	
	REP(i, n) {
		id[i] = i;
		s[i] = 1;
	}
	REP(r, k) {	
		int p,k;
		p = r+1;
		scanf("%d", &k);
		int i = find(p, id);
		int j = find(k, id);
		
			if(s[i] < s[j]) {
				id[i] = j;
				s[j] += s[i];
			}
			else {
				id[j] = i;
				s[i] += s[j];
			}
		}
	FOR(t,1,k) {
		if(id[t] == t) sm++	; 
		
	}

		
	printf("%d\n", sm);
	return 0;
	
	
}