class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // Move the accessed entry to the front.
        cache.splice(cache.begin(), cache, mp[key]);

        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            cache.splice(cache.begin(), cache, mp[key]);
            return;
        }

        // Evict the least recently used entry.
        if (cache.size() == capacity) {
            int lruKey = cache.back().first;
            cache.pop_back();
            mp.erase(lruKey);
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};
