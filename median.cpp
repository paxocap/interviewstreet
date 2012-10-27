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
int n,b;
char c;
cin>>n;
multiset<int> s;
static multiset<int>::iterator it, prev,temp;
long long median=0;

for(int i=0;i<n;i++) {
    cin >> c; 
    cin >> b;
    if(c=='a') {
        s.insert(b);
        if(s.size()==1) prev = s.begin();
        else if(b >= *prev && s.size()%2 == 0) prev++;
        else if(b < *prev && s.size()%2 != 0) prev--; 
    }         
    
    else if(c=='r' && s.size() > 0) {
        it = s.find(b);
        if(it == s.end() || *it != b) { cout << "Wrong!\n"; continue;}
        else if(*prev == b) {
           if(s.size()%2 != 0) prev++;
           else {
              temp = prev; temp--;
              if(*temp != b) prev--;
           }   
        }
        else if(b>=*prev && s.size()%2 == 0) prev--;
        else if(b<=*prev && s.size()%2 != 0) prev++;
        s.erase(it);                      
    }
    
    if(s.size()==0) cout << "Wrong!\n";
    else if(s.size()%2!=0) cout << *prev << endl;
    else { 
          median = *prev;
          prev--;
          median = (median+*prev);
          if(median%2==0)
              printf("%.0lf\n", median/2.);
          else
              printf("%.1lf\n", median/2.);
          prev++;
    }
}
return 0;
}   