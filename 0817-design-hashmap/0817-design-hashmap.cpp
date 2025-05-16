class MyHashMap {
public:
    vector<long long> arr = vector<long long>(1000001, -1);
    MyHashMap() { }
    void put(int key, int value) {
        arr[key] = value;
    }
    int get(int key) {
        return arr[key];
    }
    void remove(int key) {
        arr[key] = -1;
    }
};
