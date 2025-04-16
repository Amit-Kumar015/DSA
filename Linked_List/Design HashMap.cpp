// https://leetcode.com/problems/design-hashmap/description/

class MyHashMap {
    private:
        struct Listnode{
            int key, value;
            Listnode* next;
            Listnode(int key=-1, int value=-1, Listnode* next=nullptr):
                key(key), value(value), next(next){}
        };
    
        vector<Listnode*> map;
    
        int hash(int key){
            return key % map.size();
        }
    
    public:
        MyHashMap() {
            map.resize(1000);
            for(auto& bucket: map){
                bucket = new Listnode(0);
            }
        }
        
        void put(int key, int value) {
            int index = hash(key);
            Listnode* curr = map[index];
    
            while(curr->next){
                if(curr->next->key == key){
                    curr->next->value = value;
                    return;
                }
    
                curr = curr->next;
            }
    
            curr->next = new Listnode(key, value, nullptr);
        }
        
        int get(int key) {
            int index = hash(key);
            Listnode* curr = map[index];
    
            while(curr->next){
                if(curr->next->key == key){
                    return curr->next->value;
                }
    
                curr = curr->next;
            }
    
            return -1;
        }
        
        void remove(int key) {
            int index = hash(key);
            Listnode* curr = map[index];
    
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
    };
    
    /**
     * Your MyHashMap object will be instantiated and called as such:
     * MyHashMap* obj = new MyHashMap();
     * obj->put(key,value);
     * int param_2 = obj->get(key);
     * obj->remove(key);
     */