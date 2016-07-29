#include "prelude.hpp"

void my_merge(auto &vec_in, auto &vec_out, size_t &offset, size_t &left, size_t &right)
{
    size_t index_left    = offset;
    size_t index_right   = left;
    size_t vec_out_index = offset;
    int left_val         = 0;
    int right_val        = 0;
    bool has_left_val    = false;
    bool has_right_val   = false;

    while (true) {
        has_left_val  = index_left < left;
        has_right_val = index_right < right;
        if (has_left_val) {
            left_val  = vec_in[index_left];
        }
        if (has_right_val) {
            right_val = vec_in[index_right];
        }

        if (has_left_val && has_right_val) {
            if (left_val < right_val) {
                vec_out[vec_out_index++] = left_val;
                index_left++;
            } else {
                vec_out[vec_out_index++] = right_val;
                index_right++;
            }
        }
        else if (has_left_val) {
            vec_out[vec_out_index++] = left_val;
            index_left++;
        }
        else if (has_right_val) {
            vec_out[vec_out_index++] = right_val;
            index_right++;
        }
        else {
            break;
        }
    }
    for (size_t i=offset; i<right; i++) {
        vec_in[i] = vec_out[i];
    }
}

void split(auto &vec_in, auto &vec_out, size_t &offset, size_t &right)
{
    auto span = right - offset;
    if (span == 1)
        return;

    size_t left = offset + (span / 2);    // 3, 2 + (3 / 2 = 1.5=) 1 , i.e, span = 3, (offset = 2, right=5)

    split(vec_in, vec_out, offset, left); // 2(inclusive)..3 (exclusive)
    split(vec_in, vec_out, left, right);  // 3(inclusive)..5(exclusive)

    my_merge(vec_in, vec_out, offset, left, right);
}

void merge_sort(auto &vec_in)
{
    vector<int> vec_out(vec_in.size(), 0);
    //vec_out.reserve(vec_in.size());
    size_t offset = 0;
    size_t left = vec_in.size() / 2;
    size_t right = vec_in.size();

    split(vec_in, vec_out, offset, left); // 0(inclusive)..2 (exclusive)
    split(vec_in, vec_out, left, right);  // 2(inclusive)..5(exclusive)

    my_merge(vec_in, vec_out, offset, left, right);
}
/*
 * 3 4  2 1 5 len = 5, left = 2, (right = 3)
 * ~~~  ~~~~~ 
 *      ~ ~~~
 */
int main()
{
    vector<int> numbers{4, 5, 9, 1, 6, 2, 7, 3, 8};
    for (auto &num : numbers) { cout << num << " "; }; cout << '\n';

    merge_sort(numbers);

    for (auto &num : numbers) { cout << num << " "; }; cout << '\n';
}
