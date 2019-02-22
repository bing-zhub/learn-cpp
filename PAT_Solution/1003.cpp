#include<bits/stdc++.h>
using namespace std;
int graph[505][505];//图

//每个城市救护队的数量、到达每个城市的最短距离、到达每个城市的最短路径的数量、到达每个城市的救护队数量
int city[505],dis[505],pathNum[505],teamNum[505];

//每个城市是否被访问过
bool visit[505];
int N,M,C1,C2;

void Dijkstra(){
	//如果终点城市还没有被访问，继续循环
    while(!visit[C2]){
    	//找出目前距离最短的还没有被访问的城市
        int MIN=INT_MAX,v=-1;
        
        for(int i=0;i<N;++i)
            if(!visit[i] && dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
            
        //标记为已访问
        visit[v]=true;
        for(int i=0;i<N;++i)
            if(!visit[i] && 
				graph[v][i]!=0 &&
				dis[v]+graph[v][i]<dis[i]){
					
                //更新最短路径长度
				dis[i] = dis[v] + graph[v][i];
				
				//更新最短路径数量
                pathNum[i]=pathNum[v];
                
                //更新城市的救护队数量
                teamNum[i]=teamNum[v]+city[i];
            }else if(graph[v][i]!=0 &&
					 dis[v]+graph[v][i] == dis[i]) {
            	//增加最短路径数量
                pathNum[i]+=pathNum[v];
                
                //找出能够召集最多的城市救护队数量
                teamNum[i]=max(teamNum[i],teamNum[v]+city[i]);
            }
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;++i)
        scanf("%d",&city[i]);
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b]=c;
        graph[b][a]=c;
    }
    
    //将最短路径均设置为最大值
    fill(dis,dis+N,INT_MAX);

	//C1城市是起点，最短路径为0
    dis[C1]=0;
	
	//C1城市是起点，能够召集的救护队数量为本城市的数量
    teamNum[C1]=city[C1];

	//C1城市是起点，最短路径数量为1
    pathNum[C1]=1;
    

    Dijkstra();
    printf("%d %d",pathNum[C2],teamNum[C2]);//输出
    return 0;
}
