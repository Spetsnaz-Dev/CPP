int rotOranges(vector<vector<int> > arr, int R, int C)
{
    if(arr.empty())
        return 0;
        
    queue<pair<int, int> q;
    int counter{0};
    
    for(int i=0; i<R; i++)
        for(int j=0; i<C; j++)
            if(arr[i][j] == 2)
                q.push(make_pair(i, j));
            else if(arr[i][j] == 1)
                counter++;
                
    if(!counter)
        return 0;
    
    // DFS
    int count = 0;
    while(!q.empty()) {
        ++count;
        int s = q.size();
        
        while(s--) {
            pair<int, int> p = q.front();
            q.pop();
            
            if(p.first < R-1 and arr[i+1][j] == 1){
                arr[i+1][j] = 2;
                q.push(make_pair(i+1, j));
                counter--;
            }
            if(p.first > 0 and arr[i-1][j] == 1){
                arr[i-1][j] = 2;
                q.push(make_pair(i-1, j));
                counter--;
            }
            if(p.second < C-1 and arr[i][j+1] == 1){
                arr[i][j+1] = 2;
                q.push(make_pair(i, j+1));
                counter--;
            }
            if(p.second > 0 and arr[i][j-1] == 1){
                arr[i][j-1] = 2;
                q.push(make_pair(i, j-1));
                counter--;
            }
        }
    }
    if(!counter)
        return count-1;
    else
        return -1;
}