class ZigzagIterator {
public:
    vector<int> &a, &b;
    int i = 0, j = 0;
    bool turnA = true;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) : a(v1), b(v2) {
       if (a.empty()) turnA = false;
    }

    int next() {
        int val;
        if (turnA) {
            val = a[i];
            i++;
        } else {
            val = b[j];
            j++;
        }
        
        if (i >= a.size()) {
            turnA = false;
        } else if (j >= b.size()) {
            turnA = true;
        } else {
            turnA = !turnA;
        }
        return val;
    }

    bool hasNext() {
        return i < a.size() || j < b.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */