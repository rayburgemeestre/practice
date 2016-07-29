// first solution https://codility.com/demo/results/trainingP5H9S6-DNN/
// failed for no legitime reason??
// EDIT: I think my solution was counting other directions as well,
// just going to assume only 0 -> 1, not 1 -> 0..
// confirmed: https://codility.com/c/run/trainingNZC3QA-JT8

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
    east = 2;
    counter = 5;
    0  1  0  1  1
             x  x
             
    east = 0
    counter = 0
    1  0  1  0  0
    0  
    
*/

int solution(vector<int> &A) {
    if (A.size() == 0)
        return 0;
    
    int first_car  = 0; // should always start with east
    
    size_t east    = 0; // can also be west, depending on first_car.. but the idea is the same.
    size_t counter = 0;
    for (const auto &num : A) {
        if (num == first_car) {
            east++;
        }   
        else {
            counter += east;
        }   
    }   
    if (counter > 1000000000l)
        return -1; 
    return counter;
}

