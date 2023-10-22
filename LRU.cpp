#include <list>
#include <iostream>

// Using typedef to make things easier to understand

// We will use a linkedlist of a pair of integers
// where the first integer will be the key
// and the second integer will be the value

typedef std::list<std::pair<int, int>> KeyValuePairLL;

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        // Write your code here
    }

    int Get(int key)
    {
        // Replace this placeholder return statement with your code
        return -1;
    }

    void Set(int key, int value)
    {
        // Write your code here
    }
    void Print()
    {
        std::cout << "Cache current size: " << cacheList.size() << ", ";
        std::cout << "Cache contents: {";
        for (auto it = cacheList.cbegin(); it != cacheList.cend();)
        {
            std::cout << "{" << (*it).first << ": " << (*it).second << "}";
            ++it;
            if (it != cacheList.cend())
            {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
};

int main()
{
    int cacheCapacity = 2;
    LRUCache cache(cacheCapacity);
    std::cout << "Initial state of cache" << std::endl;
    std::cout << "Cache capacity: " << cacheCapacity << std::endl;
    cache.Print();

    std::vector<int> keys = {10, 10, 15, 20, 15, 25, 5};
    std::vector<std::string> values = {"20", "Get", "25", "40", "Get", "85", "5"};

    for (int i = 0; i < keys.size(); i++)
    {
        if (values[i] == "Get")
        {
            std::cout << "Getting by Key: " << keys[i] << std::endl;
            std::cout << "Cached value returned: " << (cache.Get(keys[i])) << std::endl;
        }
        else
        {
            std::cout << "Setting cache: Key: " << keys[i] << ", Value: " << values[i] << std::endl;
            cache.Set(keys[i], stoi(values[i]));
        }
        cache.Print();
    }
}

== == == == == == == == == == == == == == == == == == == == == == == == == == == = Solution == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
                                                                                   // Using typedef to make things easier to understand
                                                                                   // We will use a linkedlist of a pair of integers
                                                                                   // where the first integer will be the key
                                                                                   // and the second integer will be the value

                                                                                   typedef std::list<std::pair<int, int>> KeyValuePairLL;

class LRUCache
{
    size_t cacheCapacity;
    // Our hashmap will store a keys and interators to the LinkedList nodes
    std::unordered_map<int, KeyValuePairLL::iterator> cacheMap;
    // The cacheMap will contain a pair. The first element of the pair
    // will be the key and the second one will be the list iterator;
    KeyValuePairLL cacheList;
    // The cacheList will contain key-value pairs which can be accessed
    // with the first and second keywords.
public:
    LRUCache(size_t size) : cacheCapacity(size) {}
    int Get(int key)
    {
        auto foundIter = cacheMap.find(key);

        if (foundIter == cacheMap.end())
        {
            return -1;
        }

        auto listIterator = foundIter->second;

        cacheList.splice(
            cacheList.begin(),
            cacheList,
            listIterator);

        return listIterator->second;
    }

    void Set(int key, int value)
    {
        auto foundIter = cacheMap.find(key);
        if (foundIter != cacheMap.end())
        {
            auto listIterator = foundIter->second;
            cacheList.splice(cacheList.begin(), cacheList, listIterator);
            listIterator->second = value;
            return;
        }
        if (cacheMap.size() == cacheCapacity)
        {
            int key = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(key);
        }
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

    void Print()
    {
        std::cout << "Cache current size: " << cacheList.size() << ", ";
        std::cout << "Cache contents: {";
        for (auto it = cacheList.cbegin(); it != cacheList.cend();)
        {
            std::cout << "{" << (*it).first << ": " << (*it).second << "}";
            ++it;
            if (it != cacheList.cend())
            {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
};

int main()
{
    int cacheCapacity = 2;
    LRUCache cache(cacheCapacity);
    std::cout << "Initial state of cache" << std::endl;
    std::cout << "Cache capacity: " << cacheCapacity << std::endl;
    cache.Print();

    std::vector<int> keys = {10, 10, 15, 20, 15, 25, 5};
    std::vector<std::string> values = {"20", "Get", "25", "40", "Get", "85", "5"};

    for (int i = 0; i < keys.size(); i++)
    {
        if (values[i] == "Get")
        {
            std::cout << "Getting by Key: " << keys[i] << std::endl;
            std::cout << "Cached value returned: " << (cache.Get(keys[i])) << std::endl;
        }
        else
        {
            std::cout << "Setting cache: Key: " << keys[i] << ", Value: " << values[i] << std::endl;
            cache.Set(keys[i], stoi(values[i]));
        }
        cache.Print();
    }
}