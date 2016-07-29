#include <algorithm>

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++11 (g++ 4.8.2)    
    using namespace std;

    // This is the solution using STL, although going to pretend rotate doesn't exist...    
    //rotate(A.rbegin(), A.rbegin() + K, A.rend());    

    if (!A.size()) return A;
    
    K = K % A.size();
    
    for (int c=0; c<K; c++) {
        size_t i = A.size() - 1;
        int temp = A[0];
        size_t other_index = 0;
        while (true) {
            other_index = (i + 1) % A.size();
            A[other_index] = A[i];

            if (!i) break;
            i--;
        }
        A[other_index] = temp;
    }   
    
        
    return A;
}

