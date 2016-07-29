// first https://codility.com/demo/results/trainingA2RKQJ-MK7/
// https://codility.com/demo/results/trainingM7K9T3-66Y/

#include <algorithm>
#include <bitset>

int solution(vector<int> &A) {
    int extra = 0;
    int A_len = A.size();
    for (int i=0; i<A_len; i++) {
        auto num = abs(A[i]);
        if (num == (A_len + 1)) {
            extra = -1 * num;
        }   
        else {
            A[num - 1] *= -1; 
        }   
    }   
    /*for (int num=0; num<=A_len; num++) {
        if (num == A_len) {
            cout << extra << endl;
        }
        else {
            cout << A[num] << endl;;
        }
        
    }*/
    for (int num=0; num<=A_len; num++) {
        if (num == A_len && extra >= 0) {
            return num + 1;
        }   
        else if (A[num] >= 0) {
            return num + 1;
        }   
    }   
    return 0;
}
/*
;
   num: -2 -3 -1  5  extra
transl: 1   2  0  4

       1 2 3 4 5
       0 1 2 3 extra
       k k k k 
        
        */

