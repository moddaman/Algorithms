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


int min(int a, int b) {
	if(a < b) return a;
	else return b;
	
}

using namespace std;
int main(int argc, char *argv[]) {
while(true) {
	int letters = 'z' - 'a'+1;
	int A[letters];
	int B[letters];
	vector< pair<int,int> > x;
	REP(i,letters) {
		A[i] = 0;
		B[i] = 0;
	}
	char a;
	if(scanf("%c",&a) == EOF) break;
	while(true) {
		if(a == '\n') break;
		int index = a-'a';
		A[index] += 1;
		scanf("%c",&a);
	}
	while(true) {
		char a;
		scanf("%c",&a);
		if(a == '\n') break;
		int index = a-'a';
		B[index] += 1;
	}
	REP(i,letters) {
		int minste = min(A[i],B[i]);
		if(minste != 0) x.PB(MP(i,minste));
	}

	REP(i,x.size()) {
		REP(j, x[i].S) {
			printf("%c", x[i].F+'a');
			}
		}
	printf("\n");	
	}
return 0;
}