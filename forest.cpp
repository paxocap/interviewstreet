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

int CountSubNodes(vvi G, int i, int N){
  int count = 0;
  for(int j=1; j<=N ;j++) {
    if(G[i][j]==1){
      count+= 1 + CountSubNodes(G,j,N); 
    }
    }
    return count;

}

int main()
{
    int N,M,v,w;
    cin>>N;
    cin>>M;
    vector< vector<int> > G(N+5, vector<int>(N+5,0)); 
    for(int i=0;i<M;i++){
       cin>>v;
       cin>>w;
       G[w][v]=1;
    }
    vi childCount(N+N+5);
    int idx=0;
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
	if(G[i][j]==1){
	  childCount[idx]= 1 + CountSubNodes(G,j,N);
	  idx++;
      }
      }
    }
    int even_count=0;
    for(int i=0;i<idx;i++){
      if(childCount[i]%2==0&&childCount[i]!=0) {
	  even_count++;
      }
    }
    cout<<even_count;
    return 0;
}