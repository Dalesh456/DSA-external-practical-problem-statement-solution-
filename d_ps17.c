/*17.  Write a program to perform the Breadth First Search using adjacency list or 
adjacency matrix, use the map of the historical places around Pune city as the 
graph, and identify the famous landmarks as nodes.  (Shaniwar Wada, Aga 
Khan Palace, Pataleshwar Cave Temple, Lal Mahal, Shinde Chhatri, Sinhagad 
Fort, Parvati Hill Temple, Vishrambaug Wada, Bhide Wada) */

#include<stdio.h>
#define MAX 9
int adj[MAX][MAX]={
    {0,0,1,1,0,0,0,1,1},     //sw
    {0,0,1,0,1,0,0,0,0},     //Ak
    {1,1,0,0,0,0,1,0,0},     //pc
    {1,0,0,0,0,0,0,1,0},     //Lal m
    {0,1,0,0,0,0,1,0,0},     //SC
    {0,0,0,0,0,0,1,0,0},     //SF
    {0,0,1,0,1,1,0,0,0},     //PH
    {1,0,0,1,0,0,0,0,1},     //VW
    {1,0,0,0,0,0,0,1,0}      //BW
};
char *places[MAX]={
    "Shaniwar Wada",
    "Aga Khan Palace",
    "Pataleshwar Caves Temple",
    "Lal Mahal",
    "Shinde Chhatri",
    "Sinhgad Fort",
    "Parvati Hill Temple",
    "Vishrambaug Wada",
    "Bhide Wada"
};
int visited[MAX];

void BFS(int start){
    int queue[MAX],front=0,rear=0;
    for(int i=0;i<MAX;i++)
        visited[i]=0;
        
        visited[start]=1;
        queue[rear++]=start;
    printf("BFS traversal starting from %s\n",places[start]);
    while(front <rear){
        int node=queue[front++];
        printf("%s\n",places[node]);
        
        for(int i=0;i<MAX;i++){
            if(adj[node][i]==1 &&  visited[i]==0){
                  queue[rear++]=i;
                  visited[i]=1;
            }
        }
    }
    
}
int main(){
    int start;
    
    printf("The list of Landmarks are:\n");
    for(int i=0;i<MAX;i++){
        printf("%d. %s\n",i,places[i]);
    }
    printf("Enter the starting point(inde 0-8):");
    scanf("%d",&start);
    
    if(start<0||start>=MAX){
        printf("Invalid starting value..");
        return 0;
    }
    BFS(start);
    return 0;
}