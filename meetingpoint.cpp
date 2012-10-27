#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <fstream>
#include <limits>



using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                        
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int DistancePoints(long long x1,long long y1, long long x2,long long y2){
     long long ydelta = abs(y2-y1);
     long long xdelta = abs(x2-x1);
    if(ydelta>=xdelta)
	ydelta=ydelta-xdelta;
    else
        xdelta=xdelta-ydelta;
     return xdelta+ydelta;
}

long long ComputeAllDistance(vector<vector<long long> > G, long long index,long long N) {
  
  long long sum=0;
  for(int i=0;i<N;i++){
    if(i!=index)
      sum+=DistancePoints(G[index][0],G[index][1],G[i][0],G[i][1]);
  }
  return sum;
}

int main()
{
    long long N,x,y;
    cin >> N;
    vector<vector<long long> > gridMap(N+5, vector<long long>(2));
    long long minDist;
    for(int i=0;i<N;i++){
      cin>>x;
      cin>>y;
      gridMap[i][0]=x;
      gridMap[i][1]=y;
    }
    minDist=ComputeAllDistance(gridMap,0,N);
    for(int i=1;i<N;i++) {
      minDist = min(minDist, ComputeAllDistance(gridMap,i,N));
    }
    cout<<minDist;
    return 0;
}