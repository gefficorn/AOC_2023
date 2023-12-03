#include <bits/stdc++.h>
using namespace std;

bool in_bounds(int x, int y, vector<vector<char>>& schematic) {
    int rows=schematic.size(),cols=schematic[x].size();
    if (x>=0&&x<rows&&y>=0&&y<cols) return true;
    return false;
}

int render_number(int x, int y, vector<vector<char>>& schematic,vector<vector<bool>>& visited) { //given is a digit
    char c=schematic[x][y];
    visited[x][y]=1;
    string num=string(1,c);
    bool left_end=0,right_end=0;
    for (int i=1;i<3&&num.length()<=3;i++) {
        char left_c=schematic[x][y-i],right_c=schematic[x][y+i];
        if (in_bounds(x,y-i,schematic)&&!visited[x][y-i]&&!left_end) {
            if(isdigit(left_c)) {
                num = left_c+num;
                visited[x][y-i]=1;
            } else left_end=1;
        }
        if (in_bounds(x,y+i,schematic)&&!visited[x][y+i]&&!right_end) {
            if (isdigit(right_c)) {
                num = num+right_c;
                visited[x][y+i]=1;
            } else right_end=1;
        }
    }
    return stoi(num);
}

vector<int> find_parts(int i, int j, vector<vector<char>>& schematic,vector<vector<bool>>& visited) {
    vector<int> ret;
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    for (auto &x:dx) {
        for (auto &y:dy) {
            int nx=i+x,ny=j+y;
            if (in_bounds(nx,ny,schematic)&&!visited[nx][ny]&&isdigit(schematic[nx][ny])) {
                ret.push_back(render_number(nx,ny,schematic,visited));
            }
        }
    }
    return ret;
}

int main()
{
    auto start = chrono::steady_clock::now();
    freopen("in","r",stdin);
    bool part_one=0;
    int ans=0,rows=0,cols=0;
    vector<vector<char>> schematic;
    string s;
    while (getline(cin,s)) {
        vector<char> c_row(s.length());
        for (int i=0;i<s.length();i++) c_row[i]=s.at(i);
        schematic.push_back(c_row);
        rows++;
    }
    cols = s.length();
    vector<vector<bool>> visited(rows,vector<bool>(cols));
    vector<int> part_numbers;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            char c=schematic[i][j];
            if (isdigit(c)||c=='.') continue;
            vector<int> cur_parts=find_parts(i,j,schematic,visited);
            if (!part_one && (cur_parts.size()==2&&c=='*'))
                ans+=accumulate(cur_parts.begin(),cur_parts.end(),1,std::multiplies<int>());
            for (auto &x:cur_parts) part_numbers.push_back(x);
        }
    }
    if (part_one) ans=accumulate(part_numbers.begin(), part_numbers.end(), 0);
    cout<<ans<<endl;
    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    printf("%f ns", elapsed.count() * 1e-9);
    return 0;
}
