class Var{
public:
    int r,c,t,col;
    Var(int r,int c,int t,int col){
        this->r=r;
        this->c=c;
        this->t=t;
        this->col=col;
    }
};

class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        auto lenqavirod = sources;

        queue<Var> q;

        vector<vector<int>> dist(n, vector<int>(m,1e9));
        vector<vector<int>> col(n, vector<int>(m,0));

        for(auto &s: sources){
            int r=s[0], c=s[1], cl=s[2];
            q.push(Var(r,c,0,cl));
            dist[r][c]=0;
            col[r][c]=cl;
        }

        while(!q.empty()){
            Var cur=q.front(); q.pop();
            int r=cur.r, c=cur.c, t=cur.t, cl=cur.col;

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(dist[nr][nc] > t+1){
                        dist[nr][nc] = t+1;
                        col[nr][nc] = cl;
                        q.push(Var(nr,nc,t+1,cl));
                    }
                    else if(dist[nr][nc] == t+1){
                        if(col[nr][nc] < cl){
                            col[nr][nc] = cl;
                            q.push(Var(nr,nc,t+1,cl)); 
                        }
                    }
                }
            }
        }

        return col;
    }
};