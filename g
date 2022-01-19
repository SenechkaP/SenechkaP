#include <iostream>
#include <vector>
using namespace std;
int answ = 0;

vector<pair<int,int>> times;
vector<pair<int,int>> heap;
void siftUp(int ind) {
    if (ind == 0) return;
    int p = (ind - 1) / 2;
    if (heap[ind].first < heap[p].first) {
        swap(heap[ind].first, heap[p].first);
        swap(heap[ind].second, heap[p].second);
        siftUp(p);
    }
}

void siftDown(int ind) {
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    if (left >= heap.size()) return;
    if (left == heap.size() - 1) {
        right = left;
    }
    int imin = heap[left].first < heap[right].first ? left : right;
    if (heap[imin].first < heap[ind].first) {
        swap(heap[imin].first, heap[ind].first);
        swap(heap[imin].second, heap[ind].second);
        siftDown(imin);
    }

}

void add(pair <int,int> pr) {
    heap.push_back(pr);
    siftUp(heap.size() - 1);
}

void extract() {
    pair<int,int> tmp = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    times.push_back(tmp);
    siftDown(0);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ti, li;
        cin >> ti >> li;
        pair <int, int> pr = {ti,li};
        add(pr);
    }
    cout << endl;
    while (heap.size() > 0) {
        extract();
    }
    for (int i = 0; i < times.size(); i++) {
        if (i + 1 < times.size()) {
            bool ifWas = false;
            for (int j = i + 1; j < times.size(); j++) {
                if (times[i].first + times[i].second <= times[j].first) {
                    ifWas = true;
                }
            }
            if (ifWas == false) {
                answ += 1;
            }
        }
        else {
            answ += 1;
        }
    }
    cout << answ;
    return 0;
}
