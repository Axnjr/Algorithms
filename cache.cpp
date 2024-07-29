#include <list>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ip_cache {
    // constant time insertion and constant time erase, can work as stack / queue.
    // Methods: pop_back, pop_front, push_back, push_back
    public:
    static list<string> lru;
    // lru_map has a pair that stores the iterator in the lru and the corresponding index in the ip_pool
    static unordered_map<string, pair<list<string>::iterator, int>> lru_map;
    static int cap;

    void show_cache() {
        cout << endl << "THE CACHE: [ ";
        for (auto ip : lru){
            cout << ip << " , ";
        }
        cout << " ]" << endl;
    }

    void add(string ip, int ip_pool_index) {
        // auto ip_ref = lru_map.find(ip);
        if (lru.size() == cap) {
            lru_map.erase(lru.front());
            lru.pop_front();
        }
        lru.push_front(ip);
        lru_map[ip] = make_pair(lru.begin(), ip_pool_index);
    }

    void update_cache(string ip) {
        lru.remove(ip);
        lru.push_back(ip);
        lru_map[ip].first = prev(lru.end()); // Returns an iterator pointing to the element that it would be pointing to if advanced -n positions.
    }

    int find_ip(string ip, int &ip_pool_index) {
        if (lru_map.find(ip) == lru_map.end()) {
            add(ip, ip_pool_index);
            return -1;
        }
        else { // ip is repeated
            update_cache(ip);
            return lru_map[ip].second; 
        }
    }

    void show_cache_analysis(vector<string> ip_pool) {
        cout << endl
             << "Client and Server IP's mapping: " << endl;
        for (auto &ci : lru_map) {
            cout << "Client Ip: " << ci.first << " Maps to Server Ip: " << ip_pool[ci.second.second] << "|||| " << *ci.second.first << endl;
        }
    }
};

list<string> ip_cache::lru;
unordered_map<string, pair<list<string>::iterator, int>> ip_cache::lru_map;
int ip_cache::cap = 5;

static int REQUEST_COUNT = 0;
static int PORT;
static vector<string> IP_POOL;

ip_cache cache;

// Sticky Session to be implmented
string map_clientIp_to_serverIp(string ip)
{
    int r = cache.find_ip(ip, REQUEST_COUNT);
    if (r != -1)
    {
        cout << "IP CACHE ME MIL GYA: --> " << IP_POOL[r] << endl;
        return IP_POOL[r];
    }
    else if (REQUEST_COUNT >= IP_POOL.size())
    {
        REQUEST_COUNT = 0;
        cout << "REQUEST COUNT RESET !!" << endl;
    }
    // cout << "REQUEST COUNT: " << REQUEST_COUNT << endl;
    // cout << IP_POOL[REQUEST_COUNT] << endl;
    return IP_POOL[REQUEST_COUNT++];
}

int main()
{

    IP_POOL = {
        "192.168.1.1",
        "192.168.1.2",
        "192.168.1.3",
        "192.168.1.4",
        "192.168.1.5"};

    vector<string> clientIps = {
        "12.34.56.34",
        // "34.44.55.66",
        "3.4.5.66",
        "3.4.5.66",
        "3.4.5.66",
        "3.4.5.66",
        // "12.34.56.34",
        // "12.34.56.34",
        // "99.98.97.2",
        // "23.67.71.39",
        // "23.67.71.39",
        // "3.4.5.66",
        // "3.4.5.66",
        // "3.4.5.66",
        // "3.4.5.66",
        // "3.4.5.66",
        // "12.34.56.34",
        // "4.4.5.66",
        // "3.4.5.66",
        // "59.1.3.88",
        // "55.2.44.1",
        // "98.9.3.1"
    };

    cout << "SERVER IP's:" << endl;
    for (auto clientIp : clientIps)
    {
        cout << map_clientIp_to_serverIp(clientIp) << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
    cache.show_cache_analysis(IP_POOL);
    cache.show_cache();
    return 0;
}