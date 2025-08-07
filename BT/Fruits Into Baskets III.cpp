// https://leetcode.com/problems/fruits-into-baskets-iii/description/

class SegmentTree{
    int* tree;
    int size;
    public:
        SegmentTree(vector<int> baskets, int n){
            size = n;
            this->tree = new int[4*n];
            buildTree(1, 0, n-1, baskets);
        }

        void buildTree(int treeIdx, int left, int right, vector<int> baskets){
            if(left == right){
                tree[treeIdx] = baskets[left];
                return;
            }

            int mid = left + (right-left)/2;
            buildTree(2*treeIdx, left, mid, baskets);
            buildTree(2*treeIdx+1, mid+1, right, baskets);
            updateParent(treeIdx);
        }

        void updateParent(int treeIdx){
            tree[treeIdx] = max(tree[2*treeIdx], tree[2*treeIdx+1]);
        }

        bool placedFruit(int treeIdx, int left, int right, int size){
            if(tree[treeIdx] < size) return false;

            if(left == right){
                tree[treeIdx] = -1;
                return true;
            }

            int mid = left + (right-left)/2;
            bool placed = false;
            if(tree[2*treeIdx] >= size){
                placed = placedFruit(2*treeIdx, left, mid, size);
            }

            if(!placed && tree[2*treeIdx+1] >= size){
                placed = placedFruit(2*treeIdx+1, mid+1, right, size);
            }
            updateParent(treeIdx);
            return placed;
        }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree tree(baskets, baskets.size());
        int cnt=0;

        for(int fruit: fruits){
            bool placed = tree.placedFruit(1, 0, baskets.size()-1, fruit);
            if(!placed) cnt++;
        }
        return cnt;
    }
};