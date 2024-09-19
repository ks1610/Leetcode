#include<stdio.h>
#include<stdlib.h>

int uniquePaths(int m, int n) {
        //Initialize Result: Start with a result variable initialized to 1.
        long long result = 1;
        
        //Choose the Smaller of m−1 and n−1: Let k=min(m−1,n−1) to minimize the number of iterations.
        int k = (m-1 < n-1) ? m-1 : n-1;

        //Iteratively Compute the Binomial Coefficient: Use a loop to compute:
        int i;
        for(i = 1; i <= k; ++i){
            result = result*(m + n - 2 - i + 1)/i;
        }
        return result;            
}

int main(){
  int m = 3, n = 2;
  int result = uniquePaths(m, n);
  printf("%d\n", result);
  
  int m = 3, n = 7;
  int result = uniquePaths(m, n);
  printf("%d\n", result);
}
