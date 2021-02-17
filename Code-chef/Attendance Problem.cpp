/////////////////////// Attendance Problem Code: ATTND
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    string f[n];
    string l[n];
    int compararr[n] = {0};
    for(int i=0; i<n; i++){
        cin>>f[i];cin>>l[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(f[i] == f[j]){
                compararr[i]++;
                compararr[j]++;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(compararr[i]){
            cout<<f[i]<<" "<<l[i]<<endl;
        }else{
            cout<<f[i]<<endl;
        }
    }
  }
}
