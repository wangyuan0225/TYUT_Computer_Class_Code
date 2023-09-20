#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,t_pl,t_re;
    cin>>n>>m>>k;
    int t_fd[200005];
    int t_do[m];
    memset(t_fd,0,sizeof(t_fd));
    for(int i = 0;i < n;i++){
        cin>>t_pl>>t_re;
        for(int j = (t_pl>=t_re)?(t_pl-t_re+1):1;j <= t_pl;j++)
            t_fd[j]++;
    }
    for(int i = 0;i < m;i++)
        cin>>t_do[i];
    for(int i = 0;i < m;i++)
        if(i != m-1) cout<<t_fd[t_do[i]+k]<<endl;
    cout<<t_fd[t_do[m-1]+k];
    return 0;
}