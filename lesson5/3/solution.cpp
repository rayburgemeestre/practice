//https://codility.com/demo/results/trainingXFRDRR-EXE/
//// (didn't really spent that much time on it)

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

struct ACGT {
    int A;
    int C;
    int G;
    int T;
};

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> ret(P.size(), 0); // I could also re-use P or Q...
    vector<ACGT> buffer(S.size(), {0, 0, 0, 0});
    
    
    /*
    0 1 2 3 4  5  6
    C A G C C  T  A
    2 1 3 2 2  4  1
    
A   0 1 1 1 1  1  2
C   1 1 1 2 3  3  3
G   0 1 1 1 1  1  1  
T   0 0 0 0 0  1  1
    
          1
          2
          1
          0
A + 
C  + 100.000
G  + 200.000
T  + 300.000
    
    */
    
    int A = 0;
    int C = 0;
    int G = 0;
    int T = 0;
    for (size_t i=0; i<S.size(); i++) {
        if (S[i] == 'A') A++;
        else if (S[i] == 'C') C++;
        else if (S[i] == 'G') G++;
        else if (S[i] == 'T') T++;
        
        buffer[i].A = A;
        buffer[i].C = C;
        buffer[i].G = G;
        buffer[i].T = T;
    }
    
    for (size_t M=0; M<P.size(); M++) {
        
        ACGT s_start = P[M] > 0 ? buffer[P[M] - 1] : ACGT{0, 0, 0, 0};
        ACGT s_end   = buffer[Q[M]];
        
        ACGT result;
        result.A = (s_end.A - s_start.A);
        result.C = (s_end.C - s_start.C);
        result.G = (s_end.G - s_start.G);
        result.T = (s_end.T - s_start.T);
        
        if (result.A > 0)
            ret[M] = 1;
        else if (result.C > 0)
            ret[M] = 2;
        else if (result.G > 0)
            ret[M] = 3;
        else if (result.T > 0)
            ret[M] = 4;
    }    
    
    return ret;
    
}
