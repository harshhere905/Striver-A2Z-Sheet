class MyHashSet {
public:
    vector<int>arr=vector<int>(1000001,-1); 
    MyHashSet() {
    }
    
    void add(int key) {
        if(arr[key]==-1){
            arr[key]=1;
        }
    }

    void remove(int key) {
         arr[key]=-1;
    }
    
    bool contains(int key) {
       if(arr[key]!=-1){
        return true;
       }
       else{
       return false;
       }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */