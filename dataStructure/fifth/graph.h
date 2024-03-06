#include <iostream>
#define UNVISITED 0
#define VISITED 1
using namespace std;

// 图的数据结构类
class  Graph {
private:
    int  numVertex{},  numEdge{};  // 结点个数，边个数
    int  **matrix{};  // 邻接矩阵
    int  *mark{};  // 用于标记结点是否被访问过

public:
    // 构造函数，初始化图
    explicit Graph(int numVert){
        Init(numVert);
    }

    // 析构函数，释放内存
    ~Graph(){
        delete [] mark;
        for(int i=0;i<numVertex;i++)
            delete [] matrix[i];
        delete [] matrix;
    }

    // 初始化图
    void  Init(int  n){
        int  i;
        numVertex=n;
        numEdge=0;

        // 初始化标记数组
        mark=new int[n];
        for(i=0;i<numVertex;i++)
            mark[i]=UNVISITED;

        // 初始化邻接矩阵
        matrix=(int**)new int*[numVertex];
        for(i=0;i<numVertex;  i++)
            matrix[i]  =  new  int[numVertex];

        for(i=0;i<numVertex;i++)
            for(int j=0;j<numVertex; j++)
                matrix[i][j]=0;
    }

    // 返回图的结点个数
    int n() const{
        return numVertex;
    }

    // 返回结点v的第一个邻接结点
    int first(int v){
        for(int i=0;i<numVertex;i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    // 获取与结点v相连的下一个结点
    int next(int v,int w){
        for(int i=w+1; i<numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    // 设置边权重
    void  setEdge(int  v1,  int  v2,  int  wt)  {
        if(wt<=0){
            cout<<"Illegal  weight  value"<<endl;
            exit(-1);
        }
        if (matrix[v1][v2]  ==  0)  numEdge++;
        matrix[v1][v2]  =  wt;
    }

    // 删除边
    void  delEdge(int  v1,  int  v2)  {
        if(matrix[v1][v2] != 0)  numEdge--;
        matrix[v1][v2] = 0;
    }

    // 判断两个结点之间是否有边
    bool isEdge(int i,int j)
    {
        return  matrix[i][j]  !=  0;
    }

    // 获取边权重
    int weight(int v1,int v2)
    {
        return matrix[v1][v2];
    }

    // 获取结点标记
    int  getMark(int v){
        return  mark[v];
    }

    // 设置结点标记
    void  setMark(int v,int val){
        mark[v]  =  val;
    }
};
