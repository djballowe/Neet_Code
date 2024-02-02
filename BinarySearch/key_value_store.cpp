#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::string;

class TimeMap {
private:
    std::unordered_map<string, std::vector<std::pair<int, string>>> map;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!map.count(key)) {
            return "";
        }
        int l = 0;
        int r = map[key].size() - 1;
        string res = "";

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (map[key][m].first < timestamp) {
                res = map[key][m].second;
                l = m + 1;
            } else if (map[key][m].first > timestamp) {
                r = m - 1;
            } else {
                return map[key][m].second;
            }
        }

        if (r >= 0) {
            return map[key][r].second;
        }

        return res;
    }
};
