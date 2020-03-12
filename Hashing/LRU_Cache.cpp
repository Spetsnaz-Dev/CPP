class LRUCache {
  private:
    static unordered_map<int, Node *> hsmap;
    static int capacity, count;
    static Node *head, *tail;

  public:
    LRUCache(int cap) {
        //  incomplete
        hsmap.clear();
        capacity = cap;
    }

    static int get(int key) {
        if(hsmap.find(key) == hsmap.end())
            return -1;
        else {
            auto it = hsmap.begin();
            while(it != key)
                it++;
            return hsmap[key];
        }
    }

    static void set(int key, int value) {
        if(hsmap.size() == capacity){
            //  delete last node 
            Node *temp = tail;
            temp->pre->next = NULL;
            delete temp;
        }
        else if(hsmap.find(key) != hsmap.end()){
            hsmap[key] = value;
            return ;
        }
        // and insert new node at front
        Node *temp = new Node(key, value);
        if(!head && !tail) {
            head = temp;
            tail = temp;
            count--;
        }
        else {
            temp->next = head;
            head->pre = temp;
            temp->next->pre = temp;
            head = temp;
            count++;
        }
        hsmap[key] = value;
    }
};