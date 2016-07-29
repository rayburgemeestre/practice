#include "prelude.hpp"

int main()
{
    // "if the number is less.. goes down the pile"
    priority_queue<int, vector<int>, std::less<int>> pq;

    for (int i : {1, 6, 3})
        pq.emplace(i);

    int x = pq.top();
    cout << "max: " << x << endl;

    x = pq.top();
    cout << "max: " << x << endl;

    pq.pop();
}
