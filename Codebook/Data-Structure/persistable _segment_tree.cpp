const int maxn=200001;
int n,m,ls[maxn<<5],rs[maxn<<5],sum[maxn<<5],a[maxn],b[maxn],c[maxn],cnt=0;
void build(int l,int r,int &o){
    o=++cnt;int mid=l+r>>1; sum[o]=0;
    if(l==r) return;
    build(l,mid,ls[o]);
    build(mid+1,r,rs[o]);
}
void add(int l,int r,int &o,int rt,int x){
    o=++cnt;int mid=l+r>>1;
    ls[o]=ls[rt],rs[o]=rs[rt],sum[o]=sum[rt]+1;
    if(l==r) return;
    if(x<=mid) add(l,mid,ls[o],ls[rt],x);
    else add(mid+1,r,rs[o],rs[rt],x);
}
int query(int L,int R,int l,int r,int k){
    if(l==r) return l;
    int x=sum[ls[R]]-sum[ls[L]],mid=l+r>>1;
    if(x>=k) return query(ls[L],ls[R],l,mid,k);
    else return query(rs[L],rs[R],mid+1,r,k-x);
}