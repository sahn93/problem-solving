class MedianFinder {
public:
    /** initialize your data structure here. */
    // Use BST to store the list. (STL set)
    // Move median iterator as adding numbers.
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        bst.insert(num);
        
        if (bst.size() == 1) {
            midl = midr = bst.begin();
        } else {
            if (midl == midr) {
                if (num >= *midl) {
                    midr++;
                } else {
                    midl--;
                }
            } else {
                if (num >= *midr) {
                    midl++;
                } else if (num < *midl) {
                    midr--;
                } else {
                    midl++;
                    midr--;
                }
            }
        }
    }
    
    double findMedian() {
        return (double) (*midl + *midr) / 2;
    }
private:
    multiset<int> bst;
    multiset<int>::iterator midl, midr;
    double mid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
