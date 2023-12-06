#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    auto start = chrono::steady_clock::now();
    bool part_one=0;
    string s,t;
	vector<ll> times,distances;
    while (getline(cin,s)) {
		stringstream ss(s);
        vector<string> inp;
        while (ss >> t) inp.pb(t);
		vector<string> to_parse;
		if (part_one)
			for (int i=1;i<inp.size();i++) to_parse.pb(inp[i]);
		else {
			t="";
			for (int i=1;i<inp.size();i++) t+=inp[i];
			to_parse.pb(t);
		}
		for (int i=0;i<to_parse.size();i++) {
			if (inp[0]=="Time:")
				times.pb(stoll(to_parse[i]));
			else
				distances.pb(stoll(to_parse[i]));
		}
    }
	ll ans=0;
	for (int r=0;r<times.size();r++) {
		ll t=times[r],d=distances[r],left=0,right=t;
		for (ll h=sqrt(d)*12/31;h<t;h++)
			if (h*(t-h)>d) { left=h; break; }
		for (ll h=t-sqrt(d)*12/31;h>0;h--)
			if (h*(t-h)>d) { right=h; break; }
		ll record=right-left+1;
		if (r) ans*=record;
		else ans+=record;
	}
    cout<<ans<<endl;
    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
    printf("%ld μs", elapsed.count());
    return 0;
}
