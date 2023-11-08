#include <bits/stdc++.h> 
using namespace std;
class NStack
{
    vector<stack<int>>v;
    int s;
    int size;
public:
    NStack(int N, int S)
    {
        v.resize(N);
        size=0;
        this->s=S;
    }

    bool push(int x, int m)
    {
        if(size>s) return 0;
        v[m-1].push(x);
        size++;
        return 1;
    }

    int pop(int m)
    {
        if(size==0 or v[m-1].size()==0) return -1;
        int res=v[m-1].top();
        v[m-1].pop();
        size--;
        return res;
    }
};
int main(int argc, char const *argv[])
{
    int n,s,q;
    int a;
    int b,c;
    int ans;
    cin >> n >> s >> q;
    NStack stack(n,s);
    for(int i=0;i<q;i++){
        cin >> a;
        switch (a)
        {
        case 1:
            cin >> b >> c;
            ans = stack.push(b,c);
            if(ans) cout << "True" << endl;
            else cout << "False" << endl;
            break;
        case 2:
            cin >> b;
            cout << stack.pop(b) << endl;
            break;
        default:
            break;
        }

    }
    return 0;
}