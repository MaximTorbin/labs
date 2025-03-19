#include <iostream>
#include <string>
class BigInt
{
private:
    std::string digits;
    bool sign;
    static bool IsGreater(const std::string num1,const std::string num2)
    {
        if (num1.size()!=num2.size())
            return num1.size()>num2.size();
        return num1>num2;
    }
    static std::string subtract(const std::string num1,const std::string num2)
    {
        if(num1==num2) return "0";
        std:: string result;
        int borrow = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i>=0)
        {
            int digit1=num1[i--]-'0';
            int digit2=(j>=0) ? num2[j--]-'0': 0;
            int diff=digit1-digit2-borrow;
            if (diff<0)
            {
                diff+=10;
                borrow=1;
            }
            else
                borrow=0;
            result.push_back(diff+'0');
        }
        std::reverse(result.begin(),result.end());
        result.erase(0,result.find_first_not_of('0'));
        return result;
    }
    static std::string add(const std::string num1, const std::string num2)
    {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        std::string result; 
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        while(i>=0||j>=0||carry)
        {
            if(i>=0)
                carry+=num1[i--]-'0';
            if(j>=0)
                carry+=num2[j--]-'0';
            result.push_back(carry%10+'0');
            carry/=10;

        }
        std::reverse(result.begin(),result.end());
        return result;
    }

    static std::string multiply(const std::string& num1, const std::string& num2)
    {
        int len1=num1.size();
        int len2=num2.size();
        int* result = new int[len1+len2]{0};
        for(int i=len1-1;i>=0;i--)
        {
            for (int j=len2-1;j>=0;j--)
            {
                int digit1=num1[i]-'0';
                int digit2=num2[j]-'0';
                result[i+j+1]+=digit1*digit2;
                result[i+j]+=result[i+j+1]/10;
                result[i+j+1]%=10;
            }
        }
        std::string resultStr;
        for(int i=0;i<(len1+len2);i++)
        {
            if(!resultStr.empty()||result[i]!=0)
                resultStr.push_back(result[i]+'0');
        }
        delete[] result;
        return resultStr.empty() ? "0" : resultStr;
    }

public:
    BigInt(): digits("0"),sign(false){}

    BigInt(long long num)
    {
        sign=num<0;
        digits=std::to_string(abs(num));
    }

    BigInt(std::string num)
    {
        if(num[0]=='-')
        {
            sign=true;
            digits=num.substr(1);
        }
        else
        {
            digits=num;
            sign=false;
        }
        digits.erase(0, digits.find_first_not_of('0'));
        for(char ch:digits)
        {
            if(!isdigit(ch))
                throw std::runtime_error("invalid string");
        }
        if(digits.empty())
        {
            digits="0";
            sign=false;
        }
    }

    std::string get_value() const
    {
        return digits;
    }

    bool get_sign() const
    {
        return sign;
    }

    void set_sign(bool newsign)
    {
        sign=newsign;
    }

    BigInt operator + (const BigInt other) const
    {
        if(sign==other.get_sign())
        {
            std::string result=add(digits,other.digits);
            return BigInt(sign ? '-'+result: result);
        }
        if (IsGreater(digits,other.digits))
        {
            return BigInt(sign ? '-'+subtract(digits,other.digits): subtract(digits,other.digits));
        }
        return BigInt(other.get_sign() ? '-'+subtract(other.digits,digits): subtract(other.digits,digits));
    }

    BigInt operator += (const BigInt& other)
    {
        *this=*this+other;
        return *this;
    }

     BigInt operator - (const BigInt other) const
    {
        BigInt temp=other;
        temp.sign=other.sign ? false: true;
        return BigInt(*this+temp);

    }

    BigInt operator -= (const BigInt& other)
    {
        *this=*this-other;
        return *this;
    }

    BigInt operator * (const BigInt other) const
    {
        bool new_sign=sign!=other.sign;
        std::string num1=digits;
        std::string num2=other.digits;
        std::string result=multiply(num1,num2);
        if (result.empty())
            return "0";
        return BigInt(new_sign ? "-"+result : result);
    }

    BigInt operator *= (const BigInt other)
    {
        *this=*this*other;
        return *this;
    }


    BigInt operator < (const BigInt& other) const
    {
        if (sign<other.sign)
            return false;
        if (sign>other.sign)
            return true;
        if (sign)
            return IsGreater(digits,other.digits);
        return IsGreater(other.digits,digits);
    }

    BigInt operator > (const BigInt& other) const
    {
        if (sign<other.sign)
            return true;
        if (sign>other.sign)
            return false;
        if (sign)
            return IsGreater(other.digits,digits);
        return IsGreater(digits,other.digits);
    }

    BigInt operator >= (const BigInt& other) const
    {
        return !(digits<other.digits);
    }
        
    BigInt operator <= (const BigInt& other) const
    {
        return !(digits>other.digits);
    }

    BigInt operator == (const BigInt& other) const
    {
        return (sign==other.sign)&(digits==other.digits);
    }

    BigInt operator != (const BigInt& other) const
    {
        return (sign!=other.sign)||(digits!=other.digits);
    }

};

std::ostream& operator<<(std::ostream& os, const BigInt& num)
{
    if(num.get_sign())
        os<<"-";
    os<<num.get_value();
    return os;
}

std::istream& operator>>(std::istream& is, BigInt& num)
{
    std::string input;
    is >> input;
    num=BigInt(input);
    return is;
}
int main()
{
    try
    {
        BigInt a="-123";
        BigInt b=10;
        std::cout<<a*b<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout<< e.what();
    }

}

