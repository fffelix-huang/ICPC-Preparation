int n;
double a[105][105];
void gauss_jorgan(){
	for(int i=0;i<n;++i){
		int mx=i;
		for(int j=i+1;j<n;++j) if(fabs(a[j][i])>fabs(a[mx][i])) mx=j;
		if(mx!=i) swap(a[i],a[mx]);
		if(a[i][i] < EPS) return cout<<"No Solution\n",void();
		for(int j=0;j<n;++j){
			if(i==j) continue;
			double df=a[j][i]/a[i][i];
			for(int k=i+1;k<=n;++k) a[j][k]-=a[i][k]*df;
		}
	}
	for(int i=0;i<n;++i) cout<<fixed<<setprecision(2)<<a[i][n]/a[i][i]<<"\n";
}
