#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll x1,ll y1,ll x2,ll y2,ll xl,ll yl,ll R){
 if(x1 > x2) swap(x1,x2);
 if(y1 > y2) swap(y1,y2);
 long long ans = 0;
 for(int x = x1; x <= x2;x += 1){
     ll toRoot = R*R - (x - xl)*(x - xl);
     if(toRoot < 0) continue;
     ll root = sqrt(toRoot);
     ll y = yl - root, Y = yl + root;
     ll left = max(y1,y), right = min(y2,Y);// basically finding the range  
     ans += max(0ll,right - left + 1);
 }
 cout<<ans<<endl;
}
int main(){
 ll x1,y1,x2,y2,xl,yl,r;
 cin>>x1>>y1>>x1>>y2>>xl>>yl>>r;
 // make x1<x2 and y1<y2
 if(x1>x2)swap(x1,x2);
 if(y1>y2)swap(y1,y2);
 solve(x1,y1,x2,y2,xl,yl,r);
}