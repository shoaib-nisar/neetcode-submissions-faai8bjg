struct Node{
    Node* arr[26]={NULL};
    bool flag=0;
    bool containsKey(char ch)
    {
        return (arr[ch-'a']!=NULL);
    }
};

class WordDictionary {
public:
Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node*curr=root;
        for(int i=0;i<word.size();i++)
        {
            if(!curr->containsKey(word[i]))
            curr->arr[word[i]-'a']=new Node();

            curr=curr->arr[word[i]-'a'];
        }
        curr->flag=1;
    }
    bool searchy(string word,Node * curr,int idx)
    {
        bool res;
        for(int i=idx;i<word.size();i++)
        { 
            if(word[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(curr->arr[j])
                     if(searchy(word,curr->arr[j],i+1)) return true;
                }
                 return false;
            }
            else if(!curr->containsKey(word[i])) return false;  

            curr=curr->arr[word[i]-'a'];
        }
        if(curr->flag) return true; else return false;
    }
    bool search(string word) {
        Node*curr=root;
       return searchy(word,curr,0);
    }
};
