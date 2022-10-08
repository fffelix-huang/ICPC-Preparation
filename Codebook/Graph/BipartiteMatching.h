vector<int> v[Nx];
bitset<Nx> vis;
int mp[Nx],mq[Mx];
bool dfs(int x){
    vis[x]=1;
    for(int i : v[x]) if(!~mq[i] || !vis[mq[i]] && dfs(mq[i])) return mq[ mp[x] = i ] = x, 1;
    return 0;
}
int matching(){
    int ans = 0;
    memset(mq, -1, sizeof(mq)), memset(mp, -1, sizeof(mp));
    for(int i = 0; i < n; ++i) {
    	vis.reset();
    	if(dfs(i)) ans += 1;
    }
    return ans;
}
