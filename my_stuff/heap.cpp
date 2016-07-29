/*
Heap
          20
      10     15
    8   9   7  12
   5 6

 0   1  2 3 4 5  6 7 8 ...
[20|10|15|8|9|7|12|5|6|...]

*/
#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    public:
        vector<int> data;

        void swap_recursive(int offset) {
            if (offset >= data.size()) return;
            int parent       = data[offset];
            int left_offset  = (offset*2) + 1;
            int right_offset = (offset*2) + 2;
            int left         = (left_offset < data.size()) ? data[left_offset] : -1;
            int right        = (right_offset < data.size()) ? data[right_offset] : -1;
            if (left < right) {
                if (parent < right) {
                    swap(data[offset], data[right_offset]);
                    swap_recursive(right_offset);
                }
            }
            else {
                if (parent < left) {
                    swap(data[offset], data[left_offset]);
                    swap_recursive(left_offset);
                }
            }
        }

        int pop_max() {
            int ret = -1;
            if (data.empty()) return ret;
            ret = data[0];
            if (data.size() == 1) {
                data.clear();
                return ret;
            }
            data[0] = data[data.size() - 1];
            data.erase(data.begin() + (data.size() - 1), data.end());
            swap_recursive(0);
            return ret;
        }
};

int main()
{
    Heap h;
    // inserted all the elements here
    h.data.push_back(20);
    h.data.push_back(10);
    h.data.push_back(15);
    h.data.push_back(8);
    h.data.push_back(9);
    h.data.push_back(7);
    h.data.push_back(12);
    h.data.push_back(5);
    h.data.push_back(6);
    std::cout << h.pop_max() << '\n'; // 20
    std::cout << h.pop_max() << '\n'; // 15
    while (true) {
        auto p = h.pop_max();
        if (p == -1) break;
        std::cout << p << '\n';
    }
    // ...
}
