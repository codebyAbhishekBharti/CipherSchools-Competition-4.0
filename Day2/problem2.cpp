#include<bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int>&v){
    int left,right;
    int max_area=-1;
    for(int i=0;i<v.size();i++){
      left=i;
      right=i;
      for(int j=left-1;j>=0;j--) if(v[j]>=v[i]) left=j; else break;
      for(int j=right+1;j<v.size();j++) if(v[j]>=v[i]) right=j; else break;
      int area = (right-left+1)*v[i];
      // cout << left << " " << right << " " << v[i] << endl;
      (max_area<area)?(max_area=area):(max_area);
    }
  return max_area;
}
int main() {
  /* 
  Sample Input
  2
  10
  1 0 1 2 2 2 2 1 0 2
  10
  1 2 1 0 1 1 0 0 2 2
  */
    int n,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        vector<int>v(x);
        for(int j=0;j<x;j++) cin >> v[j];
        cout << largestRectangle(v) << endl;
    }
    return 0;
}
