#include "prelude.hpp"

#include <experimental/optional>

template <typename T, typename T2, int N=256>
class my_hash_map
{
public:
    my_hash_map()
        : data()
    {
        data.reserve(N);
    }

    void add(T key, T2 value)
    {
        size_t h = hash(key);
        if (!data[h]) {
            cout << " adding: " << key << " " << value << endl;
            data[h] = make_unique< vector<pair<T, T2>> >(1, make_pair(key, value));
        } else {
            data[h]->push_back(make_pair(key, value));
        }
    }

    experimental::optional<T2> get(T key) {
        experimental::optional<T2> ret;
        size_t h = hash(key);
        if (!data[h]) {
            return ret;
        }
        for (auto &p : *data[h]) {
            cout << "getting.. " << h << endl;
            if (p.first == key) {
                ret = p.second;
                break;
            }
        }
        return ret;
    }

private:

    size_t hash(T key)
    {
        size_t total = 1000;
        for (auto &i : key) {
            total *= static_cast<size_t>(i);
        }
        return (total % N);
    }

    vector< unique_ptr<vector<pair<T, T2>>> > data;
};



void reset_sstream(auto &t) {
    t.clear();
    t.str("");
}

int main()
{
    my_hash_map<string, string> hm;
    stringstream key, value;
    for (int i=0; i<1000; i++) {
        key   << "key" << i;
        value << "Some string i=" << i;

        hm.add(key.str(), value.str());
        
        reset_sstream(key);
        reset_sstream(value);
    }

    cout << "test: " << *hm.get("key11") << endl;
    cout << "test: " << *hm.get("key12") << endl;
}
