const int z=1e5+5;
int val[z],ch[z][2],n,cnt=0,pri[z],sz[z],rt=0;
int node(int x){
    sz[++cnt]=1;
    val[cnt]=x;
    pri[cnt]=rand();
    return cnt;
}
void up(int x){
    sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];
    
}
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(pri[a]<pri[b]){
        ch[a][1]=merge(ch[a][1],b);
        up(a);
        return a;
    }else{
        ch[b][0]=merge(a,ch[b][0]);
        up(b);
        return b;
    }
}
void split(int p,int &a,int &b,int k){
    if(!p) return a=b=0,void();
    if(val[p]<k){
        a=p;
        split(ch[p][1],ch[a][1],b,k);
    }else{
        b=p;
        split(ch[p][0],a,ch[b][0],k);
    }
    up(p);
}