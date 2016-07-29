//https://codility.com/demo/results/trainingU54Y6A-VCF/

int solution(int A, int B, int K) {
/*
    6
    7
    8
    9
    10
    11
    
    6 % 2 = 0, 6 - 0 = 6; = 6 / 2 = 3.
    11 % 2 = 1, 11 - 1 = 10; = 10 / 2 = 5...
    
    6 % 2 = 0, 6 - 0 = 
    12 % 2 = 0, 12 - 0 = 12; = 12 / 2 = 6...
*/

    size_t rest_B = B % K;
    size_t rest_A = A % K;
    
    size_t result = 0;
    if (rest_A == 0) result++;
    
    size_t num_K_in_A = (A - rest_A) / K; // 3
    size_t num_K_in_B = (B - rest_B) / K; // 5
    
    result += num_K_in_B - num_K_in_A;
    return result;

}
