class Solution {
public:
    bool removechar(string &senate,char c,int idx){
        bool checkleft=false;
        while(true){
            if(idx==0){
                checkleft=true;
            }
            if(senate[idx]==c){
                senate.erase(begin(senate)+idx);
                break;
            }
            idx=(idx+1)%senate.length();
        }
        return checkleft;
    }
    string predictPartyVictory(string senate) {
        int rcnt=count(senate.begin(),senate.end(),'R');
        int dcnt=senate.length()-rcnt;
        int i=0;
        while(rcnt>0&&dcnt>0){
            if(senate[i]=='R'){
                bool checkleft=removechar(senate,'D',(i+1)%senate.length());
                dcnt--;
                if( checkleft){
                    i--;
                }
            }else{
                bool checkleft=removechar(senate,'R',(i+1)%senate.length());
                rcnt--;
                if( checkleft){
                    i--;
                }
            }
            i=(i+1)%senate.length();
        }
        return rcnt==0?"Dire":"Radiant";
    }
};