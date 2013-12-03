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

using namespace std;
vector<int> uvenner[20002];
int kanBliBrukt[16002];
int brukt[16002];
int naboValgt[16002];
int n;


int nabo(int a) {
	if(a%2==0) return a-1;
	else return a+1;
	
}

int main(int argc, char *argv[]) {

	
int m;
scanf("%d %d",&n,&m);
memset(kanBliBrukt,0,sizeof(kanBliBrukt));
memset(brukt,0,sizeof(brukt));
vector<int> v;

REP(i,m) {
	int a,b;
	if(scanf("%d %d",&a,&b)==2) {
	if(brukt[a]==1)kanBliBrukt[b] = 1;
	if(brukt[b]==1)kanBliBrukt[a] = 1;
	if(kanBliBrukt[a]==0 && brukt[a]==0){ //Hvis kan bli brukt og ikke brukt
			kanBliBrukt[a] = 1;
			kanBliBrukt[b] = 1;
			kanBliBrukt[nabo(a)]=1;
			brukt[a]=1;
			v.PB(a);
	}	 
	else if(kanBliBrukt[b]==0 && brukt[b]==0){ //Hvis kan bli brukt og ikke brukt
	 		kanBliBrukt[b] = 1;
			kanBliBrukt[a] = 1;
			kanBliBrukt[nabo(b)]=1;
			brukt[b]=1;
			v.PB(b);
		}	 
	}
¨}

for(int i = 1; i<= n*2;i++) {
	if(kanBliBrukt[i]==0 && brukt[i]!=1) {
		brukt[i] = 1;
		kanBliBrukt[i] = 1;
		if(i%2==0) kanBliBrukt[i-1] = 1;
		else kanBliBrukt[i+1]=1;
		v.PB(i);
	}
	
}
	
sort(v.begin(),v.end());
if(v.size()<n) printf("NIE");
else {
	REP(i,v.size()) {
		printf("%d\n",v[i]);
	}
}
	
	
	
	

	
	
	
	
}