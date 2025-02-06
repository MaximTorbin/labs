#include <iostream>
#include <vector>
class VectorBool
{
    std::vector<unsigned int> data;
    size_t bit_count;
public:
    VectorBool(): bit_count(0) {}

    void push_back(bool value)
    {
        size_t data_index=bit_count/(sizeof(unsigned int)*8);
        size_t bit_pos=bit_count%(sizeof(unsigned int)*8);
        if(bit_pos==0)
            data.push_back(0);
        if(value)
            data[data_index]|=(1<<bit_pos);
        else
            data[data_index]&=~(1<<bit_pos);
        bit_count++;  
    }

    bool get_value(size_t ind) const
    {
        if(ind>bit_count)
            throw std::out_of_range("Index out of range");
        size_t data_index=ind/(sizeof(unsigned int)*8);
        size_t bit_pos=ind%(sizeof(unsigned int)*8);
        return (data[data_index]>>bit_pos)&1;
    }

    void print()
    {
        for(int i=0;i<bit_count;i++)
            std::cout<<get_value(i)<<" ";
        std::cout<<std::endl;
    }
    
    void set_value(size_t ind,bool val)
    {
        if(ind>=bit_count)
            throw std::out_of_range("Index out of range");
        size_t data_index=ind/(sizeof(unsigned int)*8);
        size_t bit_pos=ind%(sizeof(unsigned int)*8); 
        if(val)
            data[data_index]|=(1<<bit_pos);
        else
            data[data_index]&=~(1<<bit_pos);    
    }

    size_t size()
    {
        return bit_count;
    }

    void insert(size_t ind, bool val)
    {
        if(ind>bit_count)
            throw std::out_of_range("Index out of range");
        push_back(0);
        for(size_t i=bit_count-1;i>ind;i--)
            set_value(i,get_value(i-1));
        size_t data_index=ind/(sizeof(unsigned int)*8);
        size_t bit_pos=ind%(sizeof(unsigned int)*8); 
        if(val)
            data[data_index]|=(1<<bit_pos);
        else
            data[data_index]&=~(1<<bit_pos);
    }

    void erase(size_t ind)
    {
        if(ind>=bit_count)
            throw std::out_of_range("Index out of range");
        for(size_t i=ind;i<bit_count;i++)
            set_value(i,get_value(i+1));
        bit_count--;
        if(bit_count%(sizeof(unsigned int)*8)==0)
            data.pop_back();
    }

    bool operator[](size_t ind) const
    {
        if(ind>bit_count)
            throw std::out_of_range("Index out of range");
        size_t data_index=ind/(sizeof(unsigned int)*8);
        size_t bit_pos=ind%(sizeof(unsigned int)*8);
        return (data[data_index]>>bit_pos)&1;
    }
};


int main()
{
    try
    {
        VectorBool vec;
        vec.push_back(true);
        vec.push_back(true);
        vec.print();
        vec.erase(1);
        std::cout<<vec.size();
    }
    catch(const std::exception e)
    {
        std::cout<< e.what();
    }

}

