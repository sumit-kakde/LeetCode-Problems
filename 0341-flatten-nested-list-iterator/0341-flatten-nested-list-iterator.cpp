class NestedIterator {
public:
    vector<int> v;
    int index;

    void Recursion(vector<NestedInteger>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i].isInteger()){
                v.push_back(nums[i].getInteger());
            }
            else{
                Recursion(nums[i].getList());
            }
            i++;
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        index=0;
        Recursion(nestedList);
    }
    int next() {
        if(hasNext()){
            return v[index++];
        }
        return -1;
    }
    bool hasNext() {
        if(index<v.size()){
            return true;
        }
        return false;
    }

};