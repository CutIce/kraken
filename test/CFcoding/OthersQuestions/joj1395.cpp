//
// Created by hsh on 2020/7/14.
//

// 线段树
#include <iostream>
#include <string.h>
using namespace std;

//long long tree[400010], up[400010];
//
//void bulid(int rt, int l, int r){
//    if (l == r){
//
//    }
//}
//
//string s;
//int dat[4000005],lazy[4000005],a[4000005];
//int n;
//void pushup(int rt)
//    {dat[rt]=dat[2*rt]+dat[2*rt+1];};
//void build(int l,int r,int rt)
//{
//    if (l==r-1)
//    {
//        dat[rt]=a[l];
//        return;
//    }
//    int mid=(l+r)>>1;
//    build(l,mid,rt<<1);
//    build(mid,r,rt<<1|1);
//    pushup(rt);
//}
//void pushdown(int rt,int l,int r)
//{
//    if (lazy[rt]!=-1)
//    {
//        lazy[2*rt]=lazy[2*rt+1]=lazy[rt];
//        dat[2*rt+1]=dat[2*rt]=lazy[rt]*(r-l)/2;
//        lazy[rt]=-1;
//    }
//}
//void update(int L,int R,int l,int r,int rt,int c)
//{
//    if (L<=l&&r<=R)
//    {
//        dat[rt]=c*(r-l);
//        lazy[rt]=c;
//        return;
//    }
//    int mid=(l+r)>>1;
//    pushdown(rt,l,r);
//    if (L<mid) update(L,R,l,mid,rt<<1,c);
//    if (R>mid) update(L,R,mid,r,rt<<1|1,c);
//    pushup(rt);
//}//更新pushup pushdown都需要
//int  query(int L,int R,int l,int r,int rt)
//{
//    if (L<=l&&r<=R)
//        return dat[rt];
//    int mid=(l+r)>>1;
//    pushdown(rt,l,r);//若更新只有点更新，不需要这句
//    int ANS=0;
//    if (L<mid) ANS+=query(L,R,l,mid,rt<<1);
//    if (R>mid) ANS+=query(L,R,mid,r,rt<<1|1);
//    return ANS;
//}//查询只需要pushdown
//int main()
//{
//    cin>>s;
//    int n_=s.size();
//    for(int i=1;i<=n_;i++)
//        a[i]=s[i-1]-'0';
//    n=1;
//    while(n<n_)
//        n*=2;
//    build(1,n+1,1);
//    memset(lazy,-1,sizeof(lazy));
//    int m;
//    scanf("%d",&m);
//    for(int i=1;i<=m;i++)
//    {
//        int l,r,flag;
//        scanf("%d %d %d",&l,&r,&flag);
//        int t=query(l,r+1,1,1+n,1);
//        if(flag==0)
//        {
//            update(l,r+1-t,1,1+n,1,0);
//            update(r-t+1,r+1,1,1+n,1,1);
//        }
//        else
//        {
//            update(l,l+t,1,1+n,1,1);
//            update(l+t,r+1,1,1+n,1,0);
//        }
//    }
//    for(int i=1;i<=n_;i++)
//        printf("%d",query(i,i+1,1,1+n,1));
//}
























// version 1:


#define N 400001;
//class segTree{
//    struct node {
//        int start,end, sum;
//        node *left;
//        node *right;
//        node (int s, int e, int su, node* l = nullptr, node* r= nullptr): start(s), end(e), sum(su),left(l),right(r) {}
//    };
//
//private:
//    node *root;
//    void makeempty(node *r){
//        if (r == nullptr) return ;
//        if (r->left != nullptr) makeempty(r->left);
//        if (r->right!= nullptr) makeempty(r->right);
//        delete r;}
//
//public:
//    segTree (int d[] , int begin , int over){
//        int n = over - begin + 1;
//        int *s = new int [n];
//        s[0] = d[0];
//        for (int i=1; i<n; ++i)  { s[i] = d[i] + s[i-1]; }
//        root->sum = s[n-1];
//
//
//    }
//};
//long arr[400010];
//long tree[400010];
//int updata[400010]; //
//bool abd[400010];
//
//void buildtree(int arr[] , int tree[], int node, int start, int end){
//    if ( start == end) tree[node] = arr[start];
//    else {
//        int mid = (start + end) / 2;
//        int left_node = 2 * node + 1;
//        int right_node = 2 * node + 2;
//        buildtree(arr, tree, left_node, start, mid);
//        buildtree(arr, tree, right_node, mid, end);
//        tree[node] = tree[left_node] + tree[right_node];
//    }
//}
//
//void updata_x (int arr[], int tree[], int node, int start, int end, int idx_start, int idx_end, int val){
//    if (start == idx_start ==  end == idx_end) {arr[start] = val;}
//    int mid = (start + end) / 2;
//    int left_node = 2 * node + 1;
//    int right_node = 2 * node + 2;
//
//    if (idx_start < mid && idx_end > mid) {
//        updata_x(arr, tree, left_node, start, mid, idx_start,mid, val);
//        updata_x(arr, tree, right_node, mid+1, end, mid+1, idx_end, val);
//    }
//    else if ( idx_start < mid && idx_end <= mid ){updata_x(arr, tree, left_node,start, mid, idx_start,idx_end,val);}
//    else if ( idx_start > mid && idx_end <= end) {updata_x(arr, tree, right_node, mid+1, end ,idx_start,idx_end,val);}
//
//}
//
//void updata_abs (int arr[], int tree[], int node, int start, int end, int idx_start, int idx_end, int val){
//
//}
//
////262143
//int main(){
//    int cases;cin>>cases;
//    while(cases--){
//    int n;
//    cin>>n;
//    int h =1;
//    while(n!=0){ n/= 2; h*=2;}
//    cout<<2*h-1<<endl;
//    }
//    return 0;
//}
//
//
//void updata_x (int arr[], int tree[], int node, int start, int end, int idx, int val) {
//    if (start == end) {
//        arr[idx] = val;
//        tree[node] = val;
//    } else {
//        int mid = (start + end) / 2;
//        int left_node = 2 * node + 1;
//        int right_node = 2 * node + 2;
//        if (idx >= start && idx <= mid)
//            updata_x(arr, tree, left_node, start, mid, idx, val);
//        else updata_x(arr, tree, right_node, mid + 1, end, idx, val);
//
//        tree[node] = tree[left_node] + tree[right_node];
//    }
//
//}



int data[100010],add[100010];

struct node {
    int start,end;
    int sum;
    bool abs;
    bool up;
    int updata;
    node * left,* right;
    node (int s, int e){
        start = s;end = e;
        abs = false;
        up = false;
        updata = 0;
        if (s == e) {sum = data[s];left = nullptr; right = nullptr;}
        else {
        int mid = (start + end) / 2;
        left = new node(start, mid);
        right = new node(mid + 1, end);
        sum = left->sum + right->sum;
    }}
};

void display(node *r){
    if (r!= nullptr) cout<<r->sum<<"  s->e :"<<r->start<<" "<<r->end<<endl;
    if (r->left != nullptr) display(r->left);
    if (r->right != nullptr) display(r->right);
}


void updata_x (node *r, int idx_start, int idx_end,int val){
    if (idx_start == r->start && idx_end == r->end) {r->up = true; r->updata = val;}
    int mid = (r->start + r->end) / 2;
    if (idx_start <= mid && idx_end > mid){
        updata_x(r->left, idx_start, mid,val);
        updata_x(r->right, mid+1, idx_end, val);
    }
    else if (idx_start >= r->start && idx_start <= mid && idx_end <=mid )
    {updata_x(r->left, idx_start, idx_end, val);}
    else if (idx_start > mid && idx_end <= r->end)
    {updata_x(r->right, idx_start,idx_end,val);}
}



int main(){
    int n;cin>>n;
    for (int i=0;i<n;++i)cin>>data[i];
    node *root =new node (0,n-1);
    display(root);
    return 0;
}