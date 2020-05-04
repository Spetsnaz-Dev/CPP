int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int res = INT_MAX, flag = 0;
        vector<int> arr;
        arr = binaryMatrix.dimensions();
        cout<<arr[0]<<" "<<arr[1]<<endl;
        
        int row = arr[0], col = arr[1];
        int x = 0, y = col-1;
        while(x < row and y >= 0) {
            if(binaryMatrix.get(x, y) == 0){
                x++;
                continue;
            }
            else
                if(res > y){
                    res = y;
                    flag = 1;
                }
                y--;
        }
        if(flag == 0) 
            return -1;
        return res;
    }