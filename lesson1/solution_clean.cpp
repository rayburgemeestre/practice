#include <algorithm>
#include <bitset>
#include <iostream>

int solution(int N) {
    using namespace std;
    bitset<32> bits(N);
    bool in_padding = true;
    int used_bits = 32; 
    int counted_zeros = 0;
    int max_counted_zeros = 0;
    for (int i=32 - 1; i>=0; i--) {
        if (!in_padding) {
            if (bits.test(i)) {
                max_counted_zeros = max(counted_zeros, max_counted_zeros);
                counted_zeros = 0;
            } else {
                counted_zeros++;
            }   
        } else if (bits.test(i)) {
            in_padding = false;
            used_bits = i + 1;
        }   
    }   
    cout << "bits = " << bits << endl;
    cout << "N = " << N << " and ret = " << max_counted_zeros << endl;
    return max_counted_zeros;
}


int main() {
    std::cout << solution(1001) << std::endl;
    std::cout << solution(1001 / 2) << std::endl;
}
