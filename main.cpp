#include <vector> 
template <class T>

class matrix{
    vector<vector<T>> array;
    T identity;
    const int MATH_ERROR = -1, SUCCESS = 0, UNDEFINED=-2, TOO_BIG=1;
    public:
    long long m,n;
    matrix(long long n) : m(n), n(n) {
        array=vector<vector<T>>(m,vector<T>(n));
    }
    matrix(long long m, long long n) : m(n), n(n) {
        array=vector<vector<T>>(m,vector<T>(n));
    }
    matrix(const matrix &mat){
        m=mat.m;
        n=mat.n;
        array=vector<vector<T>>(m,vector<T>(n));
        for(long long i=1;i<=m;i++){
            for(long long j=1;j<=n;j++) array[i-1][j-1]=mat(i,j);
        }
    }
    void identity_is(T identity) : identity(identity) {}
    T& operator [] (long long i, long long j){
        return array[i-1][j-1];
    }
    void fill(T element){
        for(long long i=0;i<m;i++){
            for(long long j=0;j<n;j++){
                array[i][j]=element;
            }
        }
    }
    matrix operator * (const matrix &mat){
        matrix ret(m,mat.n);
        for(long long i=1;i<=m;i++){
            for(long long j=1;j<=mat.n;j++){
                ret[i][j]=(*this)[i][1]*mat[1][j];
                for(long long k=2;k<=n;k++){
                    ret[i][j]=ret[i][j]+(*this)[i][k]*mat[k][j];
                }
            }
        }
        return ret;
    }
    matrix operator () (long long i, long long j){
        matrix ret(m-1,n-1);
        for(long long r=1;r<i;r++){
            for(long long c=1;c<j;c++){
                ret[r][c]=(*this)[r][c];
            }
            for(long long c=j+1;c<=n;c++){
                ret[r][c-1]=(*this)[r][c];
            }
        }
        for(long long r=i+1;r<=m;r++){
            for(long long c=1;c<j;c++){
                ret[r-1][c]=(*this)[r][c];
            }
            for(long long c=j+1;c<=n;c++){
                ret[r-1][c-1]=(*this)[r][c];
            }
        }
        return ret;
    }
    pair<T,int> determinant(){
        if(n!=m) return {(*this)[1][1],MATH_ERROR};
        if(n==1) return {(*this)[1][1],SUCCESS};
        T ret=(*this)(1,1);
        int w=-1;
        for(long long i=2;i<=m;i++){
            ret=ret+w*(*this)(1,i);
        }
        return ret;
    }
}
