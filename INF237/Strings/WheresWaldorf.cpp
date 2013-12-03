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
#include <iostream>

    
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
 	char letterMatrix[70][70];
	int m,n;
	
char indexBokstav(int index) {
	return index+'a';
}
int bokstavIndex(char c) {
	return c-'a';
}

bool diagNedHoy(int y,int x, string o) {
	for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		y+=1;
		x+=1;
	}
	return true;
}
bool diagOppHoy(int y,int x, string o) {
	for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		y-=1;
		x+=1;
	}
	return true;
}
bool diagNedVen(int y,int x, string o) {
	for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		y+=1;
		x-=1;
	}
	return true;
}
bool diagOppVen(int y,int x, string o) {
for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		y-=1;
		x-=1;
	}
	return true;
}

bool vertikalOpp(int y,int x, string o) {
	for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		y-=1;
	}
	return true;
}
bool vertikalNed(int y,int x, string o) {
	for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		y+=1;
	}
	return true;
}


bool horisontaltHoyre(int y,int x, string o) {
	for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		x+=1;
	}
	return true;
}
bool horisontaltVenstre(int y,int x, string o) {
	for(int i = 0; i < o.length();i++) {
		if(letterMatrix[y][x] == '.' || letterMatrix[y][x] != o.at(i)) return false;
		x-=1;
	}
	return true;
}

bool erGood(int i, int j, string o) {
	if(horisontaltHoyre(i,j,o)) return true;
	if(horisontaltVenstre(i,j,o)) return true;
	if(vertikalOpp(i,j,o)) return true;
	if(vertikalNed(i,j,o)) return true;
	if(diagNedHoy(i,j,o)) return true;
	if(diagOppHoy(i,j,o)) return true;
	if(diagNedVen(i,j,o)) return true;
	if(diagOppVen(i,j,o)) return true;
	return false;
}


void sjekkOrd(string o) {
	int minX = 30000*3000;
	int minY = 30000*3000;
		for(int i=1; i<=m; i++) {
			   for(int j=1; j<=n; j++) {
				 if(o.at(0) == letterMatrix[i][j]) {
					if(erGood(i,j,o)) {
						if(i <= minY) {
							if(i == minY) {
								if(j < minX) {
									minY = i;
									minX = j;
									}	
							} else {
								minY = i;
								minX = j;
							}
						}
					}
				}
			}
		}
		printf("%d %d", minY,minX);
}


int main(int argc, char *argv[]) {
	
	int tC;
	scanf("%d",&tC);
	REP(r, tC) {
		scanf("%d %d",&m,&n);
 		for(int i=0; i<=50; i++) {
	       		for(int j=0; j<=50; j++) {
	               letterMatrix[i][j] = '.';
	       		 }
			}

	        for(int i=1; i<=m; i++) {
	       		for(int j=1; j<=n; j++) {
	                char a;
	                scanf("%c", &a);
	                if(a == '\n'){
	                      scanf("%c", &a);
	                }
	        		letterMatrix[i][j] = tolower(a);
	       		 }
		}
		vector< pair< int, string> > ord[26];
		int t;
		scanf("%d",&t);
		string bull;
		getline(cin,bull);
		REP(i,t) {
			string in;
			getline(cin,in);
				string ordet;
				REP(j,in.length()) {
					ordet += tolower(in.at(j));
				}	
				sjekkOrd(ordet);
				printf("\n");
		}
		if(r<tC-1) printf("\n");
	}
return 0;
	
}