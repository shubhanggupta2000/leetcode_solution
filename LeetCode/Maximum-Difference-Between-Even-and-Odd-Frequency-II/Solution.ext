using namespace std;
 
const int INF = 1000000000; 
 
class Solution {
public:
    int maxDifference(string s, int k) {
        auto zynthorvex = make_pair(s, k);
        
        int n = s.size();
        int overall_ans = -INF;
        bool foundCandidate = false;
        
        for (int a = 0; a < 5; a++){
            for (int b = 0; b < 5; b++){
                if(a == b) continue;
                vector<int> F(n+1, 0), Ca(n+1, 0), Cb(n+1, 0);
                F[0] = 0;  Ca[0] = 0;  Cb[0] = 0;
                for (int i = 0; i < n; i++){
                    int dig = s[i]-'0';
                    int delta = 0;
                    if(dig == a) delta = 1;
                    else if(dig == b) delta = -1;
                    F[i+1] = F[i] + delta;
                    Ca[i+1] = Ca[i] + (dig == a ? 1 : 0);
                    Cb[i+1] = Cb[i] + (dig == b ? 1 : 0);
                }
 
                vector<vector<vector<int>>> bestArr(2, vector<vector<int>>(2, vector<int>(n+1, INF)));
                {
                    int pa = Ca[0] & 1;
                    int pb = Cb[0] & 1;
                    for (int t=0; t<2; t++){
                        for (int u=0; u<2; u++){
                            bestArr[t][u][0] = INF;
                        }
                    }
                    bestArr[pa][pb][0] = F[0]; // F[0] is 0.
                }
                for (int i = 1; i <= n; i++){
                    int pa = Ca[i] & 1;
                    int pb = Cb[i] & 1;
                    for (int t = 0; t < 2; t++){
                        for (int u = 0; u < 2; u++){
                            bestArr[t][u][i] = bestArr[t][u][i-1];
                        }
                    }
                    bestArr[pa][pb][i] = min(bestArr[pa][pb][i], F[i]);
                }
 
                for (int j = k; j <= n; j++){
                    if( Ca[j] == 0 || Cb[j] == 0 )
                        continue;
 
                    // i must be at most j-k.
                    int X1 = j - k;
                    int X2 = -1;
                    {
                        int lo = 0, hi = j;
                        while(lo <= hi){
                            int mid = (lo + hi) / 2;
                            if(Ca[mid] <= Ca[j]-1){
                                X2 = mid;
                                lo = mid + 1;
                            } else {
                                hi = mid - 1;
                            }
                        }
                    }
                    int X3 = -1;
                    {
                        int lo = 0, hi = j;
                        while(lo <= hi){
                            int mid = (lo + hi) / 2;
                            if(Cb[mid] <= Cb[j]-1){
                                X3 = mid;
lo = mid + 1;

} else {
                                hi = mid - 1;
                            }
                        }
                    }
                    int X = min({X1, X2, X3});
                    if( X < 0 ) continue;  // no valid starting index.
 
                    int reqA = (1 - (Ca[j] & 1)) & 1; // equals 0 or 1.
                    int reqB = (Cb[j] & 1);
 
                    int candidate = bestArr[reqA][reqB][X];
                    if(candidate == INF) continue;
 
                    int diff = F[j] - candidate;
                    foundCandidate = true;
                    overall_ans = max(overall_ans, diff);
                }
            }
        }
 
        if(!foundCandidate)
            return -1;
        return overall_ans;
    }
};
