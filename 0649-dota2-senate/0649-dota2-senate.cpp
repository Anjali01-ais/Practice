class Solution {
public:
int n;
    void removechar(string &senate,vector<bool>&removed,char c,int idx){
        
        while(true){
            if(senate[idx]==c && removed[idx]==false){
               removed[idx]=true;
                break;
            }
            idx=(idx+1)%senate.length();
        }
        
    }
    string predictPartyVictory(string senate) {
        n=senate.length();
        int rcnt=count(senate.begin(),senate.end(),'R');
        int dcnt=senate.length()-rcnt;
        vector<bool>removed(n,false);
        int i=0;
        while(rcnt>0&&dcnt>0){
            if(removed[i]==false){
            if(senate[i]=='R'){
                removechar(senate,removed,'D',(i+1)%senate.length());
                dcnt--;
            }else{
                removechar(senate,removed,'R',(i+1)%senate.length());
                rcnt--;
            }
            }
            i=(i+1)%senate.length();
        }
        return rcnt==0?"Dire":"Radiant";
    }
};