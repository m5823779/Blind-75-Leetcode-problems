class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int, int> mp;

public:
    RandomizedSet() { }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        else {
            mp[val] = arr.size();
            arr.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        else {
            arr[mp[val]] = arr.back();
            mp[arr.back()] = mp[val];
            mp.erase(val);
            arr.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */