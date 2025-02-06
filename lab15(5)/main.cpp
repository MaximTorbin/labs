#include <iostream>
#include <algorithm>
class MyVector
{
private:
    int* data;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t new_capacity)
    {
        int* new_data = new int[new_capacity];
        for( size_t i=0;i<size_;++i)
            new_data[i]=data[i];
        delete [] data;
        data=new_data;
        capacity_=new_capacity;
    }
public:
    MyVector(): data{nullptr}, size_{0},capacity_(0){}

    MyVector(std::initializer_list<int> list): data{nullptr}, size_{0},capacity_(0)
    {
        reallocate(list.size());
        for (int value:list)
            push_back(value);

    }

    MyVector(const MyVector& other): data(nullptr),size_{0},capacity_(0)
    {
        data=new int[other.capacity_];
        size_=other.size_;
        capacity_=other.capacity_;
        for(size_t i=0;i<other.size_;++i)
            data[i]=other.data[i];
    }


    MyVector& operator =( MyVector other)
    {
        std::swap(size_,other.size_);
        std::swap(capacity_,other.capacity_);
        std::swap(data,other.data);
        return *this;

    }

    ~MyVector()
    {
        delete[] data;
    }

    void resize(size_t new_size, int value=0)
    {
        if(new_size>capacity_)
        {
            size_t new_capacity=std::max(new_size,capacity_*2);
            reallocate(new_capacity);
        }
        if(new_size>size_)
            std::fill(data + size_, data + new_size, value);
        size_=new_size;
    }

    void reserve(size_t new_capacity)
    {
        if(new_capacity>capacity_)
            reallocate(new_capacity);
    }

    void shrink_to_fit()
    {
        if (size_<capacity_)
            reallocate(size_);
    }

    int& front() const
    {
        if(size_==0)
            throw std::out_of_range("Vector is empty");
        return data[0];
    }

    int& back() const
    {
        if(size_==0)
            throw std::out_of_range("Vector is empty");
        return data[size_-1];
    }

    size_t size() const
    {
        return size_;
    }

    bool empty() const
    {
        return size_==0;
    }

    size_t capacity() const
    {
        return capacity_;
    }

    void push_back(int value)
    {
        if(size_==capacity_)
            reallocate(capacity_==0? 1: capacity_*2);
        data[size_++]=value;
    }

    void insert(size_t index, int value)
    {
        if (index>size_)
            throw std::out_of_range("Index out of range in insert");
        if (size_==capacity_)
            reallocate(capacity_==0 ? 1: capacity_*2);
        for( size_t i=size_;i>index;--i)
            data[i]=data[i-1];
        data[index]=value;
        ++size_;
    }

    void erase(size_t index)
    {
        if(index>size_-1)
            throw std::out_of_range("Index out of range in erase");
        for(size_t i=index; i<size_-1;++i)
            data[i]=data[i+1];
        --size_;
    }

    int& operator[](size_t index) const
    {
        if(index>=size_)
            throw std::out_of_range("Index out of range in operator []");
        return data[index];
    }
};


int main()
{
    try
    {
        MyVector vec={1,4,6,8};
        MyVector a(vec);
        for(int i=0;i<vec.size();i++)
            std::cout<<a[i]<<" ";
    }
    catch(const std::exception e)
    {
        std::cout<< e.what();
    }

}

