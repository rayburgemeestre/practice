#include <algorithm>

int solution(vector<int> &A) {
    if (A.empty())
        return 0;
    sort(begin(A), end(A)); // this makes it n log(n) probably
    size_t possible_return = 0;
    for (auto &num : A) {
        
        if (static_cast<size_t>(num) == possible_return)
            possible_return = 0;
        else if (possible_return != 0) 
            return possible_return;
        else
            possible_return = num; 
        
    }
    return possible_return;
}
/*
previous_value = 0;

num: 1, 1, 2, 2, 3
     1, 0, 2, 0, 3, 

if (previous_value == 0) {
    previous_value = num;
}
else if (previous_value == num) {
    previous_value = 0;
}
else {
    return previous_value;
}

return previous_value;
*/
