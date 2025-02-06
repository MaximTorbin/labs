#include <iostream>
#include <vector>
template<typename T>
class Matrix
{
private:
	unsigned int m_n, m_m;
	T** m_mat;
public:
	Matrix(unsigned int n, unsigned int m)
	{
		m_n = n;
		m_m = m;
		m_mat = new T*[n];
		for (int i = 0; i < n; i++)
			m_mat[i] = new T[m];
	}

	Matrix(const Matrix& other) : Matrix(other.m_n, other.m_m)
	{
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = other.m_mat[i][j];
	}

    Matrix(const std::vector<std::vector<T>>& other)
    {
        m_n=other.size();
        m_m=other[0].size();
        m_mat=new T*[m_n];
        if (m_n==0||m_m==0)
            throw std::runtime_error("Invalid initializer list");
        for(int i=0;i<other.size();i++)
            {
                if(m_m!=other[i].size())
                    throw std::runtime_error("Invalid vector");
                m_mat[i]=new T[m_m];
                for (int j = 0; j < m_m; j++)
				    m_mat[i][j] = other[i][j];
            }

    }

    Matrix(const std::initializer_list<std::initializer_list<T>> list)
    {
        m_n=list.size();
        m_m=list.begin()->size();
        if (m_n==0||m_m==0)
            throw std::runtime_error("Invalid initializer list");
        m_mat = new T*[m_n];
        int i=0;
        for(const auto& row:list)
        {
            if (row.size()!=m_m)
                throw std::runtime_error("Invalid initializer list");
            m_mat[i]=new T[m_m];
            int j=0;
            for(const auto& elem:row)
            {
                m_mat[i][j]=elem;
                j++;
            }
            i++;
        }
    }

	Matrix& operator=(Matrix other) 
	{
		m_n = other.m_n;
		m_m = other.m_m;
        std::swap(m_mat,other.m_mat);
        return *this;
	}

    T& operator ()(unsigned int n,unsigned int m)
    {
        return m_mat[n][m];
    }

    Matrix& operator ++ ()
    {
        for(int i=0;i<m_n;i++)
        {
            for(int j=0;j<m_n;j++)
                m_mat[i][j]++;
        }
        return *this;
    }

    Matrix& operator + (const Matrix& other)
    {
        if(other.m_m!=m_m||other.m_n!=m_n)
            throw std::runtime_error("the dimensions of the matrices are different");
        for(int i=0;i<m_n;i++)
        {
            for(int j=0;j<m_n;j++)
                m_mat[i][j]+=other.m_mat[i][j];
        }
        return *this;
    }

    Matrix operator +=(const Matrix& other)
    {
        *this=*this+other;
        return *this;
    }

    Matrix operator * (const Matrix& other)
    {
        if(other.m_n!=m_m)
            throw std::runtime_error("the dimensions of the matrices are different");
        Matrix result=Matrix(m_n, other.m_m);
        for(int i=0;i<m_n;i++)
        {
            for(int j=0;j<other.m_m;j++)
            {
                T temp=0;
                for(int ind=0;ind<m_m;ind++)
                    temp+=m_mat[i][ind]*other.m_mat[ind][j];
                result.m_mat[i][j]=temp;
            }
        }
        return result;
    }

     Matrix operator *= (const Matrix& other)
    {
        *this=*this*other;
        return *this;
    }

    void print() const
    {
        for(int i=0;i<m_n;i++)
        {
            for(int j=0;j<m_m;j++)
                std::cout<<m_mat[i][j]<<" ";
            std::cout<<std::endl;
        }
    }

    T det() const
    {
        if(m_n!=m_m)
            throw std::runtime_error("the matrix is not square");
        if(m_m==1)
            return m_mat[0][0];
        T res=0;
        for(int j=0;j<m_m;j++)
        {
            Matrix Mi(m_n-1,m_m-1);
            int imi=0;
            for(int i=1;i<m_n;i++)
            {
                int jmi=0;
                for(int k=0;k<m_m;k++)
                {
                    if(k==j)
                        continue;
                    Mi.m_mat[imi][jmi]=m_mat[i][k];
                    jmi++;
                }
                imi++;
            }
            res+=(j%2==0 ? 1:-1)*m_mat[0][j]*Mi.det();
        }
        return res;
        
    }

    unsigned int getN() const
    {
        return m_n;
    }

    unsigned int getM() const
    {
        return m_m;
    }

	~Matrix()
	{
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete[] m_mat;
	}
};

template<typename T>
std::ostream& operator << (std::ostream& os,  Matrix<T>& Matr)
{
    for(int i=0;i<Matr.getN();i++)
    {
        for(int j=0;j<Matr.getM();j++)
            os<<Matr(i,j)<<" ";
        os<<std::endl;
    }
    return os;
}

int main()
{
    try
    {
        Matrix<int> A({  {1,2},
                         {3,4},
                         {5,0}  });
        std::vector<std::vector<int>> vec={  {6,5,0},
                                             {9,2,3} };
        Matrix B(vec);
        Matrix<int> C=A*B;
        std::cout<<C;
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what();
    }
}