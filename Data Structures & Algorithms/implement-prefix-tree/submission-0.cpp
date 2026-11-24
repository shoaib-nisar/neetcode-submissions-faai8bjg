struct Node{
    Node* arr[26];
    bool flag=false;
    bool containKey(char ch){
    return (arr[ch-'a']!=NULL);}
};

class PrefixTree {
public:

Node* root;
    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++)
        {
            if(!curr->containKey(word[i]))
            curr->arr[word[i]-'a']=new Node();

            curr=curr->arr[word[i]-'a'];
        }
        curr->flag=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++)
        {
            if(!curr->containKey(word[i])) return false;
            curr=curr->arr[word[i]-'a'];
        }
        if(curr->flag) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!curr->containKey(prefix[i])) 
            return false;
            curr=curr->arr[prefix[i]-'a'];
        }
        return true;
    }
};
