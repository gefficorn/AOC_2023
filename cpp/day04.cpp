#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    auto start = chrono::steady_clock::now();
    freopen("in","r",stdin);
    bool part_one=0;
    string s,t;
    int ans=0,card_id=0;
    vector<vector<int>> copies;
    while (getline(cin,s)) {
        stringstream ss(s);
        vector<int> cur_copies;
        vector<string> inp;
        while (getline(ss,t,' ')) inp.pb(t);
        int n_match=0;
        unordered_set<int> scratch_cards;
        bool rolled=0;
        if (card_id)
            cur_copies=copies[card_id-1];
        if (cur_copies.size()>card_id)
            cur_copies[card_id]++; //current scratch_card
        else cur_copies.pb(1);
        for (int i=0;i<inp.size();i++) {
            if (inp[i]=="Card") {
                i++;
                continue;
            } else if (inp[i]=="|") {
                rolled=1;
                continue;
            }
            if (rolled) {
                if (!scratch_cards.insert(stoi(inp[i])).second) {
                    n_match++;
                    if (cur_copies.size()>card_id+n_match) cur_copies[card_id+n_match]+=cur_copies[card_id];
                    else cur_copies.pb(cur_copies[card_id]);
                }
            } else
                scratch_cards.insert(stoi(inp[i]));
        }
        copies.pb(cur_copies);
        card_id++;
        if (part_one) if (n_match) ans+=pow(2,n_match-1);
    }
    if (!part_one) ans=std::accumulate(copies[card_id-1].begin(),copies[card_id-1].end(),0);
    cout<<ans<<endl;
    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
    printf("%ld μs", elapsed.count());
    return 0;
}
