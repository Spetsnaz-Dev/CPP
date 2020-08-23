int find(int a, vector<int> &parent){
    if(parent[a]<0) return a;
    int x=find(parent[a], parent);
    parent[a]=x;
    return x;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> parent(A+1, -1);
    
    sort(B.begin(), B.end(), [](vector<int> v1, vector<int> v2){
        return v1[2]<v2[2];
    });
    
    int sum=0;
    for(int i=0; i<B.size(); i++){
        int x=find(B[i][0], parent);
        int y=find(B[i][1], parent);
        if(x!=y){
            sum+=B[i][2];
            parent[x]=y;
        }
    }
    return sum;
}   