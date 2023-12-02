#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto start = chrono::steady_clock::now();
    freopen("in","r",stdin);
    string s,m;
    int ans,n,k;
    bool part_one=0;
    vector<string> digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (cin>>s) {
        n=s.length();
        vector<int> nums;
        for (int i=0;i<n;i++) {
            char c = s.at(i);
            if (part_one) { if (!isalpha(c)) nums.push_back(c-'0'); }
            else {
                if (!isalpha(c)) nums.push_back(c-'0');
                else {
                    for (int j=0;j<9;j++) {
                        m=digits[j];
                        k=m.size();
                        if (i+k<=n&&s.substr(i,k)==m) nums.push_back(j+1);
                    }
                }
            }
        }
        ans+=10*nums[0]+nums.back();
    }
    cout<<ans<<endl;
    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    printf("%f ns", elapsed.count() * 1e-9);
    return 0;
}
