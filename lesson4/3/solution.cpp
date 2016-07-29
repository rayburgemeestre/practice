//https://codility.com/demo/results/trainingEYJZJX-N4G/

//first failure: https://codility.com/demo/results/trainingJY5EMS-T8E/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
// +1 so I don't have to do - 1 everywhere,
// +2 because if 1..100000 is present, there is one check for 100.001!
    vector<bool> count(100002, false);
    
    for (const auto &num : A) {
        if (num < 0 || num > 100000)
            continue;
        count[num] = true;
    }
    // second failure, off by one: (https://codility.com/demo/results/trainingV39UG5-EG4/)
    //for (size_t i=1; i<=100000; i++) {
    for (size_t i=1; i<=100001; i++) {
        if (!count[i])
            return i;
    }
    return 0;
}
