#include <algorithm>
#include <bitset>

int solution(int N) {
    using namespace std;
    bool read_gap = false;
    int counted_zeros = 0;
    int max_counted_zeros = 0;

    // looping like this f.i., you will loop for each bit..
    //    for (int i=32 - 1; i>=0; i--) {

    // looping like this will stop as soon as only zeros remain
    // (because not all numbers use all 32 bits, you don't iterate for
    // all the prefix zeros..)
    while (N > 0) {
        bool on = (N & 1); // count the bit before we shift it out
        if (read_gap) {
            counted_zeros = (!on) ? counted_zeros + 1  : 0;
            max_counted_zeros = max(counted_zeros, max_counted_zeros); 
        }
        read_gap = read_gap || on;
        N = N >> 1;
    }
    return max_counted_zeros;
}

