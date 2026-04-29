#include <iostream> 
using namespace std; 
struct cubes
{
    bool Empty=true;
    int ne=0,nw=0,se=0,sw=0;
};
cubes cube[1002][1002];
void biubiu(int &x,int &y,int &dx,int &dy)
{
    if(cube[x+dx][y+dy].Empty) {x+=dx;y+=dy;}
    else if(cube[x+dx][y+dy].Empty==false&&cube[x+dx][y].Empty==false&&cube[x][y+dy].Empty==false )
	{dx=-dx;dy=-dy;}
    else if(cube[x+dx][y+dy].Empty==false&&cube[x+dx][y].Empty==false )
	{y+=dy;dx=-dx;}
    else if(cube[x+dx][y+dy].Empty==false&&cube[x][y+dy].Empty==false ) 
	{x+=dx;dy=-dy;}
    else
	{dx=-dx;dy=-dy;}
}
bool f(int &x,int &y,string &d)
{
    int dx,dy;
    if(d=="NE")
	{
        if(cube[x][y].ne!=0) return false;
        cube[x][y].ne=1;
        dx=1;dy=-1;
    }
    else if(d=="NW")
	{
        if(cube[x][y].nw!=0) return false;
        cube[x][y].nw=1;
        dx=dy=-1;
    }
    else if(d=="SE")
	{
        if(cube[x][y].se!=0) return false;
        cube[x][y].se=1;
        dx=dy=1;
    }
    else
	{
        if(cube[x][y].nw!=0) return false;
        cube[x][y].nw=1;
        dx=-1;dy=1;
    }
    biubiu(x,y,dx,dy);
    if(dx==-1 && dy==-1) {d="NW";}
    else if(dx==-1 && dy==1) {d="SW";}
    else if(dx==1 && dy==-1) {d="NE";}
    else {d="SE";}
    return true;
}
int main()
{
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<m+2;i++)
        cube[0][i].Empty=cube[n+1][i].Empty=false;
    for(int i=0;i<n+2;i++)
        cube[i][0].Empty=cube[i][m+1].Empty=false;
    for(int i=0;i<k;i++)
	{
        int x,y;cin>>x>>y;
        cube[x][y].Empty=false;
    }
    int x,y;string d;
    cin>>x>>y>>d;
    while(f(x,y,d));
    int sum=0;
    for(int i=0;i<n+2;i++)
    for(int j=0;j<m+2;j++)
        if(cube[i][j].ne==1||cube[i][j].nw==1||cube[i][j].se==1||cube[i][j].sw==1)
        	sum++;
    cout<<sum;
}
