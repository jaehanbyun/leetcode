class PhoneDirectory {
public:
    vector<bool> dir;

    PhoneDirectory(int maxNumbers) {
        dir = vector<bool>(maxNumbers, true);
    }
    
    int get() {
        for (int i=0; i<dir.size(); ++i) {
            if (dir[i]) {
                dir[i] = false;
                return i;
            }
        }
        return -1;
    }
    
    bool check(int number) {
        return dir[number];
    }
    
    void release(int number) {
        dir[number] = true;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */