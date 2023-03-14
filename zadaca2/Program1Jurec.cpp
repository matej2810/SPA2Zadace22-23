#include <iostream>
#include <list>
#include <random>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> getDigits(int var) {

    vector<int> dig;

    if (var == 0)
        return {0};

    while (var > 0) {
        dig.push_back(var % 10);
        var /= 10;
    }

    return dig;
};

template<typename V>struct HashTable {
    HashTable();

    vector<list<pair<int, V>>> ct;
    vector<int> rv;

    void insert(int key, V value);
    pair<int, V> search(int key);

    int hash(int key);

};

template<typename V>HashTable<V>::HashTable() {
    default_random_engine generator(time(0));
    uniform_int_distribution<int> distribute(0, 6);

    for (int i = 0; i < 7; ++i)
        rv.push_back(distribute(generator));

    ct.resize(7);
}

template<typename V>int HashTable<V>::hash(int key) {
    vector<int> dig = getDigits(key);
    int sum = 0;

    for (int i = 0; i < dig.size(); ++i)
        sum += rv[i] * dig[i];

    return sum % 7;
}

template<typename V>void HashTable<V>::insert(int key, V value) {
    int k = hash(key);

    auto it = find_if(ct[k].begin(), ct[k].end(), [&key](const auto &p){ return p.first == key; });
    if (it != ct[k].end())
        it->second = value;
    else
        ct[k].push_front({key, value});
}

template<typename V>pair<int, V> HashTable<V>::search(int key) {
    int k = hash(key);

    auto it = find_if(ct[k].begin(), ct[k].end(), [&key](const auto &p){ return p.first == key; });
    if (it == ct[k].end()) {
        cout << "Not found"<< endl;
        return {};
    }
    else
        return *it;
}

int main() {
    HashTable<float> hashTable;

    vector<int> keys = {61, 551, 34, 65, 12, 0, 22, 124, 55, 666, 212};

    float value = 0.0f;
    for (auto key : keys) {
        hashTable.insert(key, value);
        value += 0.1f;
    }

    pair<int, float> p = hashTable.search(12);

    cout << p.first << ", " << p.second << endl;


    return 0;
}