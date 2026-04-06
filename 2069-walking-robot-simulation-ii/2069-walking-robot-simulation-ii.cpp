class Robot {
public:
    int w,h;
    int d;
    int x,y;

    Robot(int width, int height) {
        w=width;
        h=height;
        d=1; // East
        x=0; y=0;
    }
    
    void step(int num) {
        int per = 2*(w + h) - 4;

        if(per > 0){
            num %= per;
            if(num == 0) num = per;
        }

        while(num){
            if(d==0){ // North
                if(y+1 < h){
                    y++;
                    num--;
                }else{
                    d = (d-1+4)%4;
                }
            }
            else if(d==1){ // East
                if(x+1 < w){
                    x++;
                    num--;
                }else{
                    d = (d-1+4)%4;
                }
            }
            else if(d==2){ // South
                if(y-1 >= 0){
                    y--;
                    num--;
                }else{
                    d = (d-1+4)%4;
                }
            }
            else{ // West
                if(x-1 >= 0){
                    x--;
                    num--;
                }else{
                    d = (d-1+4)%4;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(d==0) return "North";
        else if(d==1) return "East";
        else if(d==2) return "South";
        else return "West";
    }
};