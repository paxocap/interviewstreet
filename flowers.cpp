#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <list>
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

int main()
{
  int N,K;
  long long sum=0;
  cin>>N>>K;
  vi c(N);
  for(int i=0;i<N;i++){
    cin>>c[i];
  }
  if(K>=N) {
    rep(i,N){
      sum+=c[i];
    }
    cout<<sum;
    return 0;
   }
  int x=0;    
  sort(c.rbegin(),c.rend());
  for(int i=0;i<N;i++){
    sum+=(x+1)*c[i];
    if((i+1)%K==0)
	x++;
  }
   cout<<sum; 

  return 0;
}   