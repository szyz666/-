#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6;
int fa[maxn];
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x){
        return x;
    }
    return find(fa[x]);
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
    int n,m,p;
    cin >> n >> m >> p;
    init(n);
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        unite(x,y);
    }
    for(int i=1;i<=p;i++){
        int x,y;
        cin >> x >> y;
        if(same(x,y)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}