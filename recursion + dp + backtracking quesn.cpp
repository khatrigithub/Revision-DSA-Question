 /// QUESTIONS BASED ON RECURSION + DP + BACKTRACKING ///

Q1 --> tower of hanoi quesn
https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Q2->  Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/

Q3--> Count the Number of Good Subarrays
https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

Q4 Make Number of Distinct Characters Equal
https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/

Q5 Partition String Into Substrings With Values at Most K
https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/

Q6  K-th Symbol in Grammar
https://leetcode.com/problems/k-th-symbol-in-grammar/description/

Q7 REMOVE Duplicates letters
https://leetcode.com/problems/remove-duplicate-letters/description/

Q8  permutations
https://leetcode.com/problems/permutations/description/

q9  find all the subsets 
https://leetcode.com/problems/subsets/submissions/739457025/

subset 2 -->
https://leetcode.com/problems/subsets-ii/description/

Q10  josesphus problem
https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

q11 unique paths
https://leetcode.com/problems/unique-paths-ii/submissions/754487892/

Q12 pow(x,n) implement by binary exponential method o(log n)
https://leetcode.com/problems/powx-n/description/

https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

//ist method give TLE as N <= 10^9 ONLY SUITED LOGN APPROACH //
// actual recursion calll ==> (N * func(N , R -`1)) //
    
    /* Time Complexity: O(R) as we are recursively calling the power function R time.
Space Complexity: O(R) because the stack will have R copies of the function call. 
*/
       
    long long power(int N,int R)
    {
       int MOD = 1e9 + 7;
       
        // step 1
        if (R == 0)
            return 1;
            
        // step 2
        long long ans = power(N, R - 1);
        
        // step 3 . note we need to do mod as the result may
        // overflow
        ans = (ans % MOD * N % MOD) % MOD;
        
        return ans;
        
    }

    //2nd method //
      // time com == space comp ==> O(R) as every time we are dividing R by 2 //
    
    long long power(int N,int R)
    {
       int MOD = 1e9 + 7;
        
        if (R == 0){
            return 1;
        }
    
        long long temp = power(N , R/2);
        
        if(R % 2 == 0){
            return (temp % MOD * temp % MOD);
        }
        return (N % MOD * temp % MOD * temp % MOD);
        
    }

Q13--> Pascal's Triangle 
https://leetcode.com/problems/pascals-triangle/submissions/880565289/

Q14--> Combination Sum 1 
https://leetcode.com/problems/combination-sum/

Combination Sum 2nd
https://leetcode.com/problems/combination-sum-ii/description/

Q15--> palindrome-partitioning
https://leetcode.com/problems/palindrome-partitioning/description/