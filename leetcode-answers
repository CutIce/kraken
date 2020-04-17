// #151. 翻转字符串里的单词
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();int l=0,r=0;int i=0;
        bool flag=false;
        string res="",tem;
        while (i<n){
        while (s[i]==' '&&i<n){++i;}
        if (i>=n) break;
        l=i;
        while (s[i]!=' '&&i<n){++i;}
        r=i;
        tem=s.substr(l,r-l);
        res.insert(0,tem);
        res.insert(0," ");
        }
        res.replace(0,1,"");
        return res;    
    }
};

// # 118. 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector <vector<int>> res(n);
        for (int i=0;i<n;++i){
            res[i].resize(i+1,1);
            for (int j=1;j<i;++j){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
}; 

// #  88. 合并两个有序数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector tem(nums1);
        int i=0;int l=0,r=0;
        while (i<m+n){
            if (l==m&&r<n) {nums1[i]=nums2[r];++r,++i;}
            else if (r==n&&l<m) {nums1[i]=tem[l];++l,++i;}
            else if (tem[l]<nums2[r]) {nums1[i]=tem[l];++l,++i;}
            else {nums1[i]=nums2[r];++r,++i;}
        }
        if (m!=0&&n!=0)
        nums1[m+n-1]=max(tem[m-1],nums2[n-1]);
    }
};

// # 面试题 16.03. 交点
class Solution {
private:
    const double E = 1e-6;
    bool inLine(double x, double s, double e) {   // 判断x是否在s->e或e->s之间
        if (abs(x-s) < E || abs(x-e) < E) return true;
        return (x-s>0 && e-x>0) || (x-e>0 && s-x>0);
    }

public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int x1 = start1[0], y1 = start1[1], x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1], x4 = end2[0], y4 = end2[1];
        int a11 = y2-y1, a12 = x1-x2, b1 = x1*y2-x2*y1;
        int a21 = y4-y3, a22 = x3-x4, b2 = x3*y4-x4*y3;
        int D = a11*a22-a12*a21, D1 = b1*a22-a12*b2, D2 = a11*b2-b1*a21;
        if (D == 0 && D1 == 0) {  //平行且共线
            if (min(x3, x4) > max(x1, x2) || min(x1, x2) > max(x3, x4)) return {};   //分离
            if (min(y3, y4) > max(y1, y2) || min(y1, y2) > max(y3, y4)) return {};   //分离
            vector<vector<int>> v{{x1, y1},{x2, y2},{x3, y3},{x4, y4}};
            sort(v.begin(), v.end());
            return {(double)v[1][0], (double)v[1][1]};  //取第二小的即所求交点
        }
        if (D != 0) {   //不平行
            double x0 = D1/(double)D, y0 = D2/(double)D;   //交点
            if (inLine(x0, x1, x2) && inLine(x0, x3, x4) && inLine(y0, y1, y2) && inLine(y0, y3, y4)) return {x0, y0};
        }
        return {};
    }
};

// # 56 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> tem;
        int numval=interval.size();
        vector<int> in(numval,0);                            // 判断第i个是否已经并入其他的，0-未并入，1-已并入


        for (int i=0;i<numval;++i){
            for (int j=i+1;j<numval;++j){
                if (in[j]==1) continue;                      // 如果第j个已经并入过了，跳过j
                if (interval[j][1]<interval[i][0]) continue; // 区间j在区间i前面   
                if (interval[j][0]>interval[i][1]) continue; // 区间j在区间i后面
                // j的尾在i的头后面 && j的头在i的尾前面
                if (interval[j][0]<interval[i][0]){     // 区间j夹住i的头，更新i的头
                    interval[i][0]=interval[j][0];
                }
                if (interval[j][1]>interval[i][1]){     // 区间j夹住i的尾，更新i的尾
                    interval[i][1]=interval[j][1];
                }
                in[j]=1;
            } 
        }
        int k=0;bool flag=true;
        while (k<numval){
            if (in[k]==0)
            {tem.push_back(interval[k]);}
            else flag=false;
            ++k;
        }
        if (flag) return interval;                     // 如果in数组里面都是0，代表没有一个并入其他，都是独立的区间，直接return

        tem.erase(unique(tem.begin(),tem.end()),tem.end());  // 去重

        vector<vector<int>> res;
        res=merge(tem);                                      // tem里面还有交叉区间，再洗一遍数据
        return res;
    }
};


// 55 跳跃游戏：
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        if (n==0) return true;

        int cur=nums[0],i=1;
        for (; cur!=0 && i<nums.size();++i){
            cur--;
            if (cur<nums[i])
                cur=nums[i];        }
        return i==nums.size();  
       }
};