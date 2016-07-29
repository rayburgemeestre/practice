// https://codility.com/demo/results/trainingH8GXET-QJK/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    vector<bool> count(100000, false);
    int already_found = 0;
    
    // 1 3 1 4 2 3 5 4
    // |
    
    size_t index = 0;
    for (const auto &num : A) {
        if (count[num] == true) {
            // we've already seen this guy
        }
        else {
            already_found++;
            count[num] = true;
        }
        if (already_found == X)
            return index;
        index++;
    }
    return -1;
    // write your code in C++11 (g++ 4.8.2)
}
