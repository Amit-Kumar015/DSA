// https://leetcode.com/problems/design-hashset/description/

class MyHashSet {
    private:
        struct Listnode{
            int key;
            Listnode* next;
            Listnode(int k): key(k), next(nullptr){}
        };
    
        vector<Listnode*> set;
    
        int hash(int key){
            return key % set.size();
        }
    
    public:
        MyHashSet() {
            set.resize(10000);
            for(auto& bucket: set){
                bucket = new Listnode(0);
            }
        }
        
        void add(int key) {
            int index = hash(key);
            Listnode* curr = set[index];
    
            while(curr->next){
                if(curr->next->key == key){
                    return;
                }
    
                curr = curr->next;
            }
    
            curr->next = new Listnode(key);
        }
        
        void remove(int key) {
            int index = hash(key);
            Listnode* curr = set[index];
    
            while(curr->next){
                if(curr->next->key == key){
                    Listnode* temp = curr->next;
                    curr->next = temp->next;
                    delete temp;
                    return;
                }
    
                curr = curr->next;
            }
        }
        
        bool contains(int key) {
            int index = hash(key);
            Listnode* curr = set[index];
    
            while(curr->next){
                if(curr->next->key == key){
                    return true;
                }
    
                curr = curr->next;
            }
            return false;
        }
    };
    
    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */