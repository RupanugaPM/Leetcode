class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0;
        int b=0;
        int c=0;
        int cur=0;
        for(int i=0;i<colors.size();i++){
            c=0;
            cur=i;
            while(i<colors.size() && colors[i]==colors[cur]){
                c++;
                i++;
            }
            if(colors[cur]=='A'){
                a+=max(c-2,0);
            }
            else{
                b+=max(c-2,0);
            }
            i--;
        }
        return a>b;
    }
};