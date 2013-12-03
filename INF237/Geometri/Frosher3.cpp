#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <cstring>
#include <stack>


    
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
//Problem Algrotimen får problemer hvis alle punktene er på en linje.

using namespace std;
int n;
pair<double, double> start;
vector<pair<double, double> > pp;
vector<pair<double, double> >  pm;
vector<pair<double, double> >  mp;
vector<pair<double, double> > mm;

struct PairComparator {
	bool operator() (pair<double, double> p1, pair<double,double> p2){
     	   float diff = atan2l(p1.S-0.0,p1.F-0.0);
			float sec =  atan2l(p2.S-0.0,p2.F-0.0);
			if(diff != sec) return diff < sec;
			else {
			 	double res1 =  sqrt (pow((p1.F - 0), 2) + pow( (p1.S - 0),2));
			 	double res2 =  sqrt (pow((p2.F - 0), 2) + pow( (p2.S - 0),2));
				return res1 < res2;
				}				
    }
};

double vectorProduct(pair<double, double> p1,pair<double, double> p2,pair<double, double> p3) {
	
	return (p2.F-p1.F)*(p3.S-p1.S)-(p2.S-p1.S)*(p3.F-p1.F);
	
};

double specialCase() {
	if(n==0) return 0.0;
	 else {
			double x1,y1;
			scanf("%lf %lf", &x1,&y1);
			double tilO = sqrt (pow((x1 -0), 2) + pow( (y1 - 0),2));
	if(n==1) return tilO*2;
	else {
		double x2,y2;
		scanf("%lf %lf", &x2,&y2);
		double tila = sqrt (pow((x2 - x1), 2) + pow( (y2 - y1),2));
		double tilO2 = sqrt (pow((x2 -0), 2) + pow( (y2 - 0),2));
		return tilO+tila+tilO2;
		}
 	}
};	

void add(double x, double y) {
	if(x > 0.0 && y > 0.0) pp.PB(MP(x,y));
	else if(x < 0.0 && y < 0.0) mm.PB(MP(x,y)); 
	else if(x > 0.0 && y < 0.0) pm.PB(MP(x,y));
	else if(x < 0.0 && y > 0.0) mp.PB(MP(x,y)); 
	
	
	
}
vector<pair<double, double> > convexHull(){
	vector<pair<double,double> > A;
	int lowest = 0;
		REP(i, n) {
			double x, y;
			scanf("%lf %lf", &x,&y);
			add(x,y);
			A.PB(MP(x,y));
			if(y < A[lowest].S && x < A[lowest].F)
				lowest = i;
		}
		start = A[lowest];
		A.erase(A.begin() + lowest);
		sort(A.begin(), A.end(), PairComparator());
		vector<pair<double,double> > hull;
		hull.PB(start);
		REP(i, A.size()) {
			while(hull.size() > 1 && vectorProduct(A[i], hull[hull.size()-1],hull[hull.size()-2]) >= 0) {
				hull.pop_back();
			}
			hull.PB(A[i]);
		}
		return hull;
}



int main() {
	int tC;
	scanf("%d", &tC);
	REP(t, tC) {
		scanf("%d", &n);
		double total = 0.0;
		if(n <= 2) { 
			total = specialCase();
		}
		else {
			vector<pair<double,double> > outer = convexHull(); 
			double dist = 0.0;
			double minVal= 3000*3000*3000;;

			double tilOr1=0.0;
			double tilOr = 0.0;
			pair<double, double> minstePar;
			outer.PB(outer[0]);
			REP(i,outer.size()-1) { 
				double res = sqrt (pow((outer[i].F - outer[i+1].F), 2) + pow((outer[i].S - outer[i+1].S),2));
				double tilOr = sqrt (pow((outer[i].F -0), 2) + pow( (outer[i].S - 0),2));
				double tilOr1 = sqrt (pow((outer[i+1].F -0), 2) + pow( (outer[i+1].S - 0),2));
				if(tilOr+tilOr1-res< minVal){
					 minstePar = MP(i,i+1);
				     minVal = tilOr+tilOr1-res;
				}
				dist += res;
			}	
			dist += minVal;
			total = dist;
		  }
		printf("%.2lf\n", total+2);
		if(t < tC-1)printf("\n");
	}	
	return 0;
}
