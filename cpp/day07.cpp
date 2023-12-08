#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
bool part_one=0;

int rep_card(char c) {
	if (isdigit(c)) return c-'1';
	switch (c) {
		case 'T': return 9;
		case 'J': return (part_one?10:0);
		case 'Q': return 11;
		case 'K': return 12;
	}
	return 13;
}

struct hand {
	int r, b; //rank, bet
	string h; //hand
	
	bool operator < (const hand &t) const {
		if (r==t.r) { //tie
			for (int i=0;i<h.size();i++) {
				int a=rep_card(h.at(i)),b=rep_card(t.h.at(i));
				if (a==b) continue;
				if (a<b) return 1;
				return 0;
			}
		}
		if (r<t.r) return 1;
		return 0;
	}
};

int main()
{
    auto start = chrono::steady_clock::now();
    string s,t;
	ll ans=0;
	vector<hand> bets;
    while (getline(cin,s)) {
        stringstream ss(s);
		int wager,count_score=1;
		ss >> t >> wager;
		unordered_map<char,int> cards;
		hand new_h={0,wager,t};
		for (auto &c:t) cards[c]++;
		for (auto &card:cards) count_score*=card.second;
		int n=cards.size();
		if (n==1) new_h.r=7;
		else if (n==2) new_h.r=(count_score==4?6:5); 
		else if (n==3) new_h.r=(count_score==3?4:3);
		else if (n==4) new_h.r=2;
		else new_h.r=1;
		if (!part_one&&cards['J']>0&&new_h.r<7) {
			if (new_h.r>=5) new_h.r=7;
			else if (new_h.r==3) new_h.r+=(cards['J']==1?2:3);
			else if (new_h.r==1) new_h.r++;
			else new_h.r+=2;
		}
		bets.pb(new_h);
    }
	sort(bets.begin(),bets.end());
	for (int i=0;i<bets.size();i++) ans+=bets[i].b*(i+1);
	cout<<ans<<endl;
    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
    printf("%ld μs", elapsed.count());
    return 0;
}
