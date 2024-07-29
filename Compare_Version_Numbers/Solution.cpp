#include<bits/stdc++.h>

#define WHILE_VER1(ver1, q1, i)  while(i < ver1.size() && ver1[i] != '.'){ q1.push_back(ver1[i]); i++;}
#define WHILE_VER2(ver2, q2, j)  while(j < ver2.size() && ver2[j] != '.'){ q2.push_back(ver2[j]); j++;}

class Solution {
public:
    //convert a string representation of a number into a long long integer
    long long solve(std::string s){
        long long n = 0;
        int i = 0;
        while(i < s.size()){
            n += n*10 + (s[i]-'0');
            i++;
        }
        return n;
    }
    //make a compare
    int compareVersion(std::string ver1, std::string ver2) {
        int i = 0, j = 0;
        std::string q1 = "", q2 = "";
        //int i = 0, j = 0;
        //compare version 1 and version2
        while(i < ver1.size() && j < ver2.size()){
            std::string q1 = "", q2 = "";
            
            WHILE_VER1(ver1, q1, i)
            WHILE_VER2(ver2, q2, j)
            
            int p = solve(q1);
            int q = solve(q2);
            
            if(p < q) return -1;
            else if(p > q) return 1;
            i++;
            j++;
        }   
      
        //checks if there are any remaining segments in version1
        while( i < ver1.size() )
        {
            std::string q1 = "" ;
            
            WHILE_VER1(ver1, q1, i)
            
            int p = solve( q1 ) ; int s = 0 ;
            if( p > s )         return 1 ;
            else if( p < s )    return -1 ;
            i++ ;
        }

        //checks if there are any remaining segments in version2.
        while( j < ver2.size() ) 
        {
            std::string q2 = "" ;
            
            WHILE_VER2(ver2, q2, j)
            
            int p = 0 ; int s = solve( q2 ) ;
            if( p > s )         return 1 ;
            else if( p < s )    return -1 ;
            j++ ;
        }
        return 0;
    }
};

int main(){
    std::string a = "1.001", b = "1.01";
    Solution s;
    std::cout << "before compare: " <<std::endl;
    std::cout << s.solve(a) << " " << s.solve(b) << std::endl;
    std::cout << "compare version: ";
    std::cout << s.compareVersion(a, b) << std::endl;
}
