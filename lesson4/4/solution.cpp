//https://codility.com/demo/results/trainingTMG5DH-DMC/

vector<int> solution(int N, vector<int> &A) {
    vector<int> counters(N, 0);
    int current_max = 0;
    int current_level = 0;
    
    for (const auto &num : A) {
        if (num <= 0)
            continue;
        if (num <= N) {
            counters[num - 1] = max(counters[num - 1], current_level);
            counters[num - 1]++;
            current_max = max(current_max, counters[num - 1]);
        }
        else if (num == N + 1) {
           current_level = current_max; // max out with current max. 
           // no need to actually do this on the entire array right now.
        }
    }
    for (auto &num : counters) {
        num = max(num, current_level);
    }
    return counters;
}
