#include <bits/stdc++.h>
using namespace std;

int solve(int p, int q){
  if(p==q)
    return 0;
  if(q==1)
    return 1;
  int op1 = 100001, op2 =100001;
  if(q%2==0) op1 = 1+solve(p,q/2);
  if(sqrt(q)*sqrt(q)==q) op2 = 1 + solve(p,sqrt(q));
  int res = min(op1, op2);
  return res;
}


int main() {
  int t; cin >> t;
  while(t--){
    int p, q;
    cin >> p >> q;
    int res = solve(p,q);
    int ans = res>=100001 ? -1: res;
    cout<< ans <<endl;
  }
  return 0;
}