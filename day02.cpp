#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto start = chrono::steady_clock::now(); //time start
    freopen("in","r",stdin);
    bool part_one=0;
    int cutoff[3]={12,13,14},ans=0;
    string s,t;
    while (getline(cin,s)) {
        stringstream ss(s);
        vector<string> inp;
        while (getline(ss,t,' ')) inp.push_back(t);
        int id = stoi(inp[1]),i=2, total[3]={0,0,0}, maxn[3]={0,0,0};
        bool poss=1;
        while (i+1<inp.size()) {
            string num=inp[i],col=inp[i+1];
            int clr_indx=0;
            if (col.at(0)=='g') clr_indx=1;
            else if (col.at(0)=='b') clr_indx=2;
            total[clr_indx]+=stoi(num);
            if (col.at(col.length()-1)!=',') {
                for (int i=0;i<3;i++) {
                    maxn[i]=max(maxn[i],total[i]);
                    if (total[i]>cutoff[i]) poss=0;
                }
                memset(total, 0, sizeof total);
            }
            i+=2;
        }
        if (part_one) ans+=(poss?id:0);
        else ans+=maxn[0]*maxn[1]*maxn[2];
    }
    cout<<ans<<endl;
    auto end = chrono::steady_clock::now(); //time end
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    printf("%f ns", elapsed.count() * 1e-9);
    return 0;
}
