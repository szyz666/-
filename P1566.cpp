#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
int fa[maxn];
char a[maxn][maxn];
int n,m;
int id(int x,int y){
    return n*(y-1)+x;
}
void init(int n,int m){
    for(int i=1;i<=n*m;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    init(n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='W'){
                int dx[]={-1,-1,-1,0,0,1,1,1};
                int dy[]={-1,0,1,1,-1,-1,0,1};
                for(int k=0;k<8;k++){
                    int nx=j+dx[k];
                    int ny=i+dy[k];
                    if(nx<1||nx>m||ny<1||ny>n){
                        continue;
                    }else if(a[ny][nx]=='W'){
                        unite(id(i,j),id(ny,nx));
                    }
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='W'&&find(id(i,j))==id(i,j)){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
