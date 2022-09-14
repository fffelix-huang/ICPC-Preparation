#define IT set<chtholly>::iterator
struct chtholly{
    int l,r;
    mutable int v;
    chtholly(int il,int ir=-1,int iv=0):l(il),r(ir),v(iv){};
    bool operator<(const chtholly &x)const{return l<x.l;}
};
set<chtholly> odt;
IT split(int x){
    IT it=--odt.upper_bound(chtholly(x));
    if(it->l==x) return it;
    int l=it->l,r=it->r,v=it->v;
    odt.erase(it);
    odt.insert(chtholly(l,x-1,v));
    return odt.insert(chtholly(x,r,v)).F;
}
void assign(int l,int r,int v){
    IT itr=split(r+1),it=split(l);
    odt.erase(it,itr);
    odt.insert(chtholly(l,r,v));
}// odt.insert(chtholly(0,maxn)); before start solving problem 