/*
 * @lc app=leetcode id=3753 lang=cpp
 *
 * [3753] Total Waviness of Numbers in Range II
 */

// @lc code=start
class Solution {
public:
    struct Node{
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node solve(int pos,int prev2,int prev1,bool started,bool tight){
        if(pos==s.size()){
            return {1,0};
        }

        if(!tight && vis[pos][prev2][prev1][started]){
            return dp[pos][prev2][prev1][started];
        }

        int lim=tight?(s[pos]-'0'):9;

        long long totalCnt=0;
        long long totalWav=0;

        for(int d=0;d<=lim;d++){

            bool nTight=(tight && d==lim);

            if(!started && d==0){
                Node nxt=solve(pos+1,10,10,0,nTight);

                totalCnt+=nxt.cnt;
                totalWav+=nxt.wav;
            }
            else{

                if(!started){
                    Node nxt=solve(pos+1,10,d,1,nTight);

                    totalCnt+=nxt.cnt;
                    totalWav+=nxt.wav;
                }
                else{

                    long long add=0;

                    if(prev2!=10){
                        if((prev1>prev2 && prev1>d) ||
                           (prev1<prev2 && prev1<d)){
                            add=1;
                        }
                    }

                    Node nxt=solve(pos+1,prev1,d,1,nTight);

                    totalCnt+=nxt.cnt;
                    totalWav+=nxt.wav + add*nxt.cnt;
                }
            }
        }

        Node ans={totalCnt,totalWav};

        if(!tight){
            vis[pos][prev2][prev1][started]=1;
            dp[pos][prev2][prev1][started]=ans;
        }

        return ans;
    }

    long long calc(long long x){
        if(x<0) return 0;

        s=to_string(x);
        memset(vis,0,sizeof(vis));

        return solve(0,10,10,0,1).wav;
    }

    long long totalWaviness(long long num1,long long num2) {
        return calc(num2)-calc(num1-1);
    }
};
// @lc code=end

