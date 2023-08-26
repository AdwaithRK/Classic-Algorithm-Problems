

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;
};

TrieNode *getNode()
{
    struct TrieNode *temp = new TrieNode();
    temp->isEndOfWord = false;

    return temp;
}

bool search(string word, TrieNode *root)
{

    TrieNode *trieTraversal = root;

    for (auto character : word)
    {
        if (trieTraversal->children[character] == NULL)
            return false;

        trieTraversal = trieTraversal->children[character];
    }

    return trieTraversal->isEndOfWord;
}

void insert(string word, TrieNode *root)
{

    TrieNode *trieTraversal = root;

    for (auto character : word)
    {
        if (trieTraversal->children[character] == NULL)
        {
            trieTraversal->children[character] = getNode();
        }

        trieTraversal = trieTraversal->children[character];
    }

    trieTraversal->isEndOfWord = true;
}

    
bool startsWith(string prefix, TrieNode* root) {
    TrieNode* trieCrawler = root;


    for(auto character : prefix){
        if(trieCrawler->children[character] == NULL)
            return false;

        trieCrawler = trieCrawler -> children[character];
    }

    return true;
}

int main()
{
    string a = "cat";

    TrieNode *root = getNode();

    insert(a, root);
    insert("cartoon", root);
    insert("carboard", root);
    insert("adwaith", root);

    cout << search("cat", root) << "\n";

    cout << search("adwaith", root) << "\n";


    return 0;
}
