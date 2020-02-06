#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //No of test cases
  int s;
  cin >> s;
  while (s--) {
    //Bigger matrix
    long long int A, B, i, j;
    cin >> A >> B; //A*B matrix
    long long int H[A][B];
    //Input bigger matrix
    for (i = 0; i < A; ++i) {
      for (j = 0; j < B; ++j)
        cin >> H[i][j];
    }
    //Matrix to be searched
    long long int d, e;
    cin >> d >> e;
    long long int x;
    long long int arr[d][e];
    long long int patternHash = 0;
    for (i = 0; i < d; i++)
      for (j = 0; j < e; j++) {
        cin >> x;
        // arr[i].push_back(x);
        arr[i][j] = x;
        patternHash += x;
      }

    for (i = 0; i < d; ++i) {
      for (j = 0; j < e; ++j) {
          cout<<arr[i][j]<<" ";
      }
    }
    cout<<"\n";
    //cout << "PH: " << patternHash << "\n";

    //If Matrix cannot be searched due to size limitations then just throw error and continue to next test_case
    if (A < d || B < e) {
      cout << "Cannot be searched...!!\n";
      continue;
    }

    long long int hash[A - d][B - e]; //Stores hash value
    long long int col_hash[B];
    long long int col_hash_sum;
    //Now lets calculate and store hash
    for (i = 0; i <= A - d; ++i) {
      //Calculate hash for 1st matrix in a row
      col_hash_sum = 0; //Keeps col_hash total value
      for (int x = 0; x < e; ++x) {
        col_hash[x] = 0;
        for (int y = i; y < i + d; ++y)
          col_hash[x] += (H[y][x]);
        col_hash_sum += col_hash[x];
      }
      //Now store the 1st value in hash and roll for rest of the columns (rolling hash technique)
      hash[i][0] = col_hash_sum;
      //Iterate for rest of the columns
      for (long long int col = e; col < B; ++col) {
        col_hash[col] = 0;
        for (long long row = i; row < i + d; ++row)
          col_hash[col] += (H[row][col]);

        col_hash_sum -= col_hash[col - e];
        col_hash_sum += col_hash[col];
        hash[i][col - e + 1] = col_hash_sum;
      }
    }
    for (i = 0; i < d; ++i) {
      for (j = 0; j < e; ++j) {
          cout<<arr[i][j]<<" ";
      }
    }

    // //Now match this hash in the 2d hashTable and wherever match happens, we will match the entire matrix
    // bool isEqual = true;
    // for (int i = 0; i <= A - d; ++i) {
    //   for (int j = 0; j <= B - e; ++j) {
    //     if (patternHash == hash[i][j]) {
    //       isEqual = true;
    //       //then match the patternMatrix with the equiSized part of the main matrix
    //       for (long long int r = i; r < i + d; ++r) {
    //         for (long long int c = j; c < j + e; ++c) {
    //             cout<<arr[r-i][c-j]<<" is the element found\n";
    //           if (H[r][c] != arr[r - i][c - j]) {
    //             isEqual = false;
    //             goto abc;
    //           }
    //         }
    //       }
    //     }
    //     abc:
    //       if (isEqual) {
    //         cout << "Pattern found at row = " << i << " and col = " << j << "\n";
    //         //goto xyz;
    //       }
    //   }
    // }
    // if (!isEqual)
    //     cout << "NOT_FOUND...!!\n";
  }
  return 0;
}