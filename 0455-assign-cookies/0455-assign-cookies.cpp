class Solution {
public:
#define SORT(a) sort(a.begin(), a.end())
    int findContentChildren(vector<int>& g, vector<int>& s) {
        SORT(g);
        SORT(s);
        int satisfied=0;
        auto greed = g.begin(), cookie = s.begin();
        while (greed < g.end() && cookie < s.end()) {
            while(cookie<s.end()&&*cookie<*greed){
                cookie++;
            }
            // cookie can be exhausted or big enough by now.
            if(cookie<s.end()){
                satisfied++;
                greed++;
                cookie++;
            }
        }
        return satisfied;
    }
};