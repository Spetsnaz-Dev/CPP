int solve(int A[], int B[], int C[], int i, int j, int k) 
{  
        int min_diff, current_diff, max_term; 
  
        // calculating min difference from last 
        // index of lists 
        min_diff = abs(max(A[i], max(B[j], C[k]))  
                     - min(A[i], min(B[j], C[k]))); 
  
        while (i != -1 && j != -1 && k != -1)  
        { 
            current_diff = abs(max(A[i], max(B[j], C[k]))  
                            - min(A[i], min(B[j], C[k]))); 
  
            // checking condition 
            if (current_diff < min_diff) 
                min_diff = current_diff; 
  
            // calculating max term from list 
            max_term = max(A[i], max(B[j], C[k])); 
  
            // Moving to smaller value in the 
            // array with maximum out of three. 
            if (A[i] == max_term) 
                i -= 1; 
            else if (B[j] == max_term) 
                j -= 1; 
            else
                k -= 1; 
        } 
          
        return min_diff; 
    } 