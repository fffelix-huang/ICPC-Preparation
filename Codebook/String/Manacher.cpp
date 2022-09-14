char ch[22200005];
int p[22200005],idx=0,ans=0;
void read(){
    char c=getchar(); ch[0]='.',ch[++idx]='|';
    while(c<'a'||c>'z') c=getchar();
    while(c>='a'&&c<='z') ch[++idx]=c,ch[++idx]='|',c=getchar();
}
int main(){
    read();
    for(int i=1,r=0,mid=0;i<=idx;++i){
        if(i<=r) p[i]=min(p[(mid<<1)-i],r-i+1);
        while(ch[i-p[i]]==ch[i+p[i]]) ++p[i];
        if(p[i]+i>r) r=p[i]+i-1,mid=i;
        ans=max(ans,p[i]);
    }
    printf("%d\n",ans-1);
    return 0;
}