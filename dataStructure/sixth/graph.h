#include <iostream>
#define UNVISITED 0
#define VISITED 1
using namespace std;

// ͼ�����ݽṹ��
class  Graph {
private:
    int  numVertex{},  numEdge{};  // ���������߸���
    int  **matrix{};  // �ڽӾ���
    int  *mark{};  // ���ڱ�ǽ���Ƿ񱻷��ʹ�

public:
    // ���캯������ʼ��ͼ
    explicit Graph(int numVert){
        Init(numVert);
    }

    // �����������ͷ��ڴ�
    ~Graph(){
        delete [] mark;
        for(int i=0;i<numVertex;i++)
            delete [] matrix[i];
        delete [] matrix;
    }

    // ��ʼ��ͼ
    void  Init(int  n){
        int  i;
        numVertex=n;
        numEdge=0;

        // ��ʼ���������
        mark=new int[n];
        for(i=0;i<numVertex;i++)
            mark[i]=UNVISITED;

        // ��ʼ���ڽӾ���
        matrix=(int**)new int*[numVertex];
        for(i=0;i<numVertex;  i++)
            matrix[i]  =  new  int[numVertex];

        for(i=0;i<numVertex;i++)
            for(int j=0;j<numVertex; j++)
                matrix[i][j]=0;
    }

    // ����ͼ�Ľ�����
    int n() const{
        return numVertex;
    }

    // ���ؽ��v�ĵ�һ���ڽӽ��
    int first(int v){
        for(int i=0;i<numVertex;i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    // ��ȡ����v��������һ�����
    int next(int v,int w){
        for(int i=w+1; i<numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    // ���ñ�Ȩ��
    void  setEdge(int  v1,  int  v2,  int  wt)  {
        if(wt<=0){
            cout<<"Illegal  weight  value"<<endl;
            exit(-1);
        }
        if (matrix[v1][v2]  ==  0)  numEdge++;
        matrix[v1][v2]  =  wt;
    }

    // ɾ����
    void  delEdge(int  v1,  int  v2)  {
        if(matrix[v1][v2] != 0)  numEdge--;
        matrix[v1][v2] = 0;
    }

    // �ж��������֮���Ƿ��б�
    bool isEdge(int i,int j)
    {
        return  matrix[i][j]  !=  0;
    }

    // ��ȡ��Ȩ��
    int weight(int v1,int v2)
    {
        return matrix[v1][v2];
    }

    // ��ȡ�����
    int  getMark(int v){
        return  mark[v];
    }

    // ���ý����
    void  setMark(int v,int val){
        mark[v]  =  val;
    }
};
