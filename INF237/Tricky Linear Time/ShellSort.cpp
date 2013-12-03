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
//http://www.questtosolve.com/browse.php?pid=10152
//http://stackoverflow.com/questions/9794558/weighted-median-computation
using namespace std;
vector< pair<int,string> > start;
map<string,int>  end;
vector<pair<string, int> > wrong;
int moves = 0;
int n;
struct PairComparator {
	bool operator() (pair<string, int> p1, pair<string,int> p2){
     	   return p1.S > p2.S;			
    }
};

void distanceLoc() {
	for(int i = start.size()-1; i >= 0; i--)
	{
		int index = start[i].F;
		int skalIndex =  end.find(start[i].S)->S;
		int diff = skalIndex-index;
		if(diff != moves) {
			wrong.PB(MP(start[i].S,skalIndex));
			moves += 1;
		}
	}	
	sort(wrong.begin(), wrong.end(), PairComparator());
	if(wrong.size() > 0) {
		REP(i, wrong.size()) {
			printf("%s\n", wrong[i].F.c_str());
			}
		}
}

int main() {
	
	int tC;
	scanf("%d",&tC);
	REP(ti,tC) {
		scanf("%d", &n);
		string bull;
		getline (cin, bull);
		REP(i,n) {
			string turtle;
			getline (cin, turtle);
			start.PB(MP(i,turtle));
		}
		REP(j,n) {
			string turtle2;
			getline (cin, turtle2);
			end.insert(MP(turtle2,j));
		}
		distanceLoc();
		end.clear();
		start.clear();
		wrong.clear();
		moves = 0;
		putchar('\n');

	}
		return 0;
	
}