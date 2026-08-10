class LRUCache {
public:
struct Node{
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int k,int v):key(k), val(v),next(nullptr),prev(nullptr) {};
        };
int len=0,cap;
unordered_map<int,Node*> mpp;
Node* head,* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
           Node* temp=mpp[key];
           temp->prev->next=temp->next;
           temp->next->prev=temp->prev;
           temp->prev=tail->prev;
           temp->next=tail;
           tail->prev->next=temp;
           tail->prev=temp;
            return mpp[key]->val;

        }
        return -1;

    }
    
    void put(int key, int value) {
        Node* temp=nullptr;
        if(mpp.find(key)!=mpp.end())
        {
           temp=mpp[key];
           temp->val=value;
           temp->prev->next=temp->next;
           temp->next->prev=temp->prev;
        }
        else
        {
            temp=new Node(key,value);
            mpp[key]=temp;
            if(len==cap)
            {
                Node* curr=head->next;
                head->next=curr->next;
                curr->next->prev=head;
                mpp.erase(curr->key);
                delete curr;
                curr=nullptr;
            } else len++;
        }
        temp->prev=tail->prev;
        temp->next=tail;
        tail->prev->next=temp;
        tail->prev=temp;

    }
};
