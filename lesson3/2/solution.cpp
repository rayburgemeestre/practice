// you can use includes, for example:
#include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    if (A.size() <= 1) {
        return 0;
    }
    // write your code in C++11 (g++ 4.8.2)
    int total = 0;
    int cumulative = 0;
    for (auto &num : A) {
        //cout << " num = " << num << endl;
        cumulative += num;
        num = cumulative;
    }
    total = cumulative;
    size_t index = 0;
    size_t smallest_dist = std::numeric_limits<size_t>::max();
    for (auto &num : A) {
        
        if (index == A.size() - 1)
            break; // skip last element
        
        int remainder = total - num;
        size_t dist = abs(remainder - num);
        
        //cout << " total = " << total << " dist = " << dist << " value: " << num << endl;
        
        smallest_dist = min(smallest_dist, dist);
        
        index++;
    }
    return smallest_dist;
}
/*

cumulative = 3;
running_total = 13;

num: 3, 1,  2, 4, 3
     0  1   2  3  4
c:   3  4   6  10 13
t:   3  4   6  10 13
r:   10 9   7  3  0
     7  5   1  7  13
     */
