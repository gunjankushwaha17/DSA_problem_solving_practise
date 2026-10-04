class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int m = part.length();

        for (char c : s) {
            res.push_back(c);

            // Check if the current end of res matches part
            if (res.length() >= m && res.compare(res.length() - m, m, part) == 0) {
                res.erase(res.length() - m, m);
            }
        }

        return res;
    }
};