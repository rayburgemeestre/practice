//https://codility.com/demo/results/trainingADJFJJ-Q2D/

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    vector<int> count(1000001, 0);
    for (const auto &num : A) {
        if (num < 1 || num > A.size())
            return 0;
        
        count[num] = 1;
    }
    return std::accumulate(count.begin(), count.end(), 0) == A.size() ? 1 : 0;
}

