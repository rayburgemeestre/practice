#include <algorithm>
#include <bitset>

int solution(int N) {
    using namespace std;
    bitset<32> bits(N);
    // Note-to-self: not sure if it's possible to do a non linear search for the first active bit in the set... 
    // This probably cannot work because the bits are not sorted (and it's not available for bitsets) 
    // auto lb = upper_bound(begin(bits), end(bits), true);
    bool in_padding = true;
    int used_bits = 32; 
    int counted_zeros = 0;
    int max_counted_zeros = 0;
    for (int i=32 - 1; i>=0; i--) {
        //if (bits.test(i)) cout << "_"; else cout << "!";
        if (!in_padding) {
            if (bits.test(i)) {
                max_counted_zeros = max(counted_zeros, max_counted_zeros);
                // optimization: we already found a set that's more than 50% of all used bits
                if (max_counted_zeros > (used_bits / 2))
                    return max_counted_zeros;
                counted_zeros = 0;
            } else {
                counted_zeros++;
            }   
            // optimization: remaining bits cannot hold a longer set than we already found
            int remaining_bits = i + 1;
            if (max_counted_zeros >= remaining_bits) {
                return max_counted_zeros;
            } 
        } else if (bits.test(i)) {
            in_padding = false;
            used_bits = i + 1;
            // cout << "bits = " << bits << " used = " << used_bits << endl;
        }   
    }   
    //cout << "bits = " << bits << endl;
    //cout << "N = " << N << " and ret = " << max_counted_zeros << endl;
    return max_counted_zeros;
}

