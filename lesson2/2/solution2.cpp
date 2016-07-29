#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // This is the solution using STL, although going to pretend rotate doesn't exist...    
    //rotate(A.rbegin(), A.rbegin() + K, A.rend());    
    vector<int> buffer;
    buffer.reserve(K);

    if (!A.size()) return A;
    
    K = K % A.size();

    for (int c=0; c<K; c++) {
// got bored..
        buffer.push_back();
    }
    
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

int main()
{
    std::cout << std::bitset<32>(1001) << std::endl;
    solution({1, 2, 3, 4, 5}, 2);
}
