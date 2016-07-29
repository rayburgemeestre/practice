// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {    
    for (const auto &num : A) {
        if (num < 1 || num > A.size())
            return 0;
    }
    return 1;
}
