#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
	public:
		LRUCache(int capacity) {
			cap = capacity;
		}

		int get(int key) {
			if (pos.find(key) != pos.end()) {
				put(key,pos[key]->second);
				return pos[key]->second;
			}
		}

		void put(int key, int value) {


		}
	private:
		int cap;
		list<pair<int,int>> recent;
		unordered_map<int, list<pair<int,int>>:iterator> pos;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
	int capacity = 4;

	LRUCache* obj = new LRUCache(capacity);
	obj.put(1,1);
	obj.put(2,2);
	obj.put(3,3);
	obj.put(4,4);
	cout << "get lru key: 2 , value : " << obj.get(2) << endl;
}
