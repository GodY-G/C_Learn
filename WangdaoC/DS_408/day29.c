#define maxsize 100
//二叉树结构体
typedef struct BiTree{
  int data;
  struct BiTree* lchild;
  struct BiTree* rchild;
}BiTree,*BitNode;


//邻接表结构体
typedef struct ArcNode{
  int adjvex;
  struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
  int data;
  ArcNode *firstarc;
}VNode,ADjList[maxsize];

typedef struct{
  ADjList vertices;
  int vexnum,arcnum;
}ALGraph;

//邻接矩阵结构体
typedef struct{
  int vexnum,arcnum;
  int edges[maxsize][maxsize];
}MGraph;

//快排算法
int partition(int a[],int low,int high){
  int pivot = a[low];
  while(low < high){
    while(low < high && a[high] >= pivot)high--;
    a[low] = a[high];
    while(low < high && a[high] <= pivot)low++;
    a[high] = a[low];
  }
  a[low] = pivot;
  return low;
}

void quick_sort(int a[],int low,int high){
  if(low < high){
    int position = partition(a,low,high);
    quick_sort(a,low,position - 1);
    quick_sort(a,position + 1,high);
  }
}