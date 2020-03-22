#include<iostream>
#include<map>

using namespace std;

int main(){
  int N;
  cin>>N;
  int X[N],A[N],B[N];
  map<int,int> m;
  for(int i=0;i<N;i++){
    cin>>X[i]>>A[i]>>B[i];
    m[X[i]]=i;
  }
  map<int,int> dp;
  for(int i=0;i<N;i++){
    dp[X[i]]=A[i];
    auto it=dp.find(X[i]);
    int l=0;
    while(true){
      if(it==dp.begin())break;
      it--;
      l+=B[m[it->first]];
      dp[X[i]]=max(dp[X[i]],it->second-l+A[i]);
    }
    it=dp.find(X[i]);
    int r=0;
    while(true){
      it++;
      if(it==dp.end())break;
      r+=B[m[it->first]];
      dp[X[i]]=max(dp[X[i]],it->second-r+A[i]);
    }
  }
  int ans=0;
  for(auto it=dp.begin();it!=dp.end();it++){
    ans=max(ans,it->second);
  }
  cout<<ans<<endl;
}
