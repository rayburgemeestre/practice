// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++11 (g++ 4.8.2)
    if (!( X<= Y))
        return 0;
    
    int needed_jump_len = (Y - X);
    int needed_jumps = needed_jump_len / D;
    if ((needed_jump_len % D) != 0) {
        needed_jumps++;
    }
    return needed_jumps;
    
}
