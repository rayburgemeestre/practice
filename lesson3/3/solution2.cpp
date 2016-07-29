// better solution

#include <algorithm>

int solution(vector<int> &A) {
    int N = A.size() + 1;
    size_t total = (N * (N + 1)) / 2.; 
    //return total - accumulate(begin(A), end(A), 0);
    size_t in = 0; // force size_t for accumulate..
    size_t counted = accumulate(begin(A), end(A), in); 
    size_t diff = total - counted;
    return static_cast<int>(diff);
}

