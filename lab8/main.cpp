#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;


// // //№1

// bool IsSorted(string word)
// {
//     for (int i = 0; i < word.size(); ++i) {
//         for (int j = i + 1; j < word.size(); ++j) {
//             for (int k = j + 1; k < word.size(); ++k) {
//                 if (tolower(word[i]) < tolower(word[j]) && 
//                     tolower(word[j]) <tolower(word[k])){
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }
// void SortLenandWrite(set<string> arr)
// {
//     int n=0;
//     string* words=new string[arr.size()];
//     ofstream fout;
//     fout.open("SortedWords.txt");
//     for (string element : arr)
//     {
//         words[n]=element;
//         n++;
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(words[i].length()>words[j].length())
//             swap(words[i],words[j]);
//         }
//         fout << words[i] <<endl;
//     }
//     fout.close();
// }
// string removePunctuation(string str)
// {
//     string CleanStr;
//     for(char ch:str)
//     {
//         if(!ispunct(ch))
//         CleanStr+=ch;
//         else
//         CleanStr+=" ";
//     }
//     return CleanStr;
// }
// struct LengthComparator
// {
//     bool operator()(string a,string b)const
//     {
//         return a.length() < b.length();
//     }
// };
// int main()
// {
//     string path="English.txt";
//     ifstream fin;
//     fin.open(path);
//     if (!fin.is_open())
//     cout<<"ERROR";
//     else
//     {

//         string str,text;
//         while(!fin.eof())
//         {
//             getline(fin,str);
//             text+=str+" ";
//         }
//         fin.close();
//         set<string> uniqueWords;
//         text=removePunctuation(text);
//         istringstream iss(text);
//         string word;
//         int n=0;
//         while(iss >> word)
//         {
//             if(IsSorted(word))
//             {
//                 uniqueWords.insert(word);
//                 n+=1;
//             }
//         }
//         SortLenandWrite(uniqueWords);
//     }
// }



//№2

// string glasn="aeiou";

// string removePunctuation(string str)
// {
//     string CleanStr;
//     for(char ch:str)
//     {
//         if(!ispunct(ch))
//         CleanStr+=ch;
//         else
//         CleanStr+=" ";
//     }
//     return CleanStr;
// }
// string StrToLower( string a)
// {
//     string res=a;
//     transform(res.begin(),res.end(),res.begin(),::tolower);
//     return res;
// }
// int GlasnCount(string a)
// {
//     int n=0;
//     for(char ch:a)
//     {
//         if(glasn.find(ch)!=string::npos)
//         n++;
//     }
//     return n;
// }
// void SortandWrite(string* arr,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]>arr[j])
//             swap(arr[i],arr[j]);
//         }
//         cout<<arr[i]<<endl;     
//     }
// }
// int main()
// {
//     string path="w.txt";
//     ifstream fin;
//     fin.open(path);
//     if (!fin.is_open())
//     cout<<"ERROR";
//     else
//     {
//         string str,text;
//         while(!fin.eof())
//         {
//             getline(fin,str);
//             text+=str+" ";
//         }
//         fin.close();
//         text=removePunctuation(text);
//         int len=(text.length()/2)+1;
//         string* words=new string[len];
//         istringstream iss(text);
//         string word;
//         int n=0;
//         while(iss >> word)
//         {
//             words[n]=StrToLower(word);
//             n++;
//         }
//         bool fl=0;
//         for(int i=0;i<n;i++)
//         {
//             if(fl)
//                 break;
//             for(int j=i+1;j<n;j++)
//             {
//                 if (words[i]==words[j])
//                 {
//                     fl=1;
//                     break;
//                 }
//             }
//         }
//         string* newWords=new string[n];
//         if(fl)
//         {
//             for(int i=0;i<n;i++)
//             {
//                 for(char ch:words[i])
//                 {
//                     if (glasn.find(ch)==string::npos)
//                         newWords[i]+=ch;
//                 }
//             }
//         }
//         else
//         {
//              for(int i=0;i<n;i++)
//              {
//                 if( GlasnCount(words[i])<4)
//                 {
//                     for(char ch:words[i])
//                     {
//                         if (glasn.find(ch)==string::npos)
//                         {
//                             newWords[i]+=ch;
//                             newWords[i]+=ch;
//                         }
//                         else
//                             newWords[i]+=ch;
//                     }
//                 }
//                 else
//                 newWords[i]=words[i];
//              }
//         }
//         SortandWrite(newWords,n);
//     }
// }



// №3

struct Pair {
    std::string first;
    std::string second;
};

string StrToUpper( string a)
{
    string res=a;
    transform(res.begin(),res.end(),res.begin(),::toupper);
    return res;
}
Pair IsSorted(string word)
{
    string str="",newWord="";
    Pair a;
    a.first = "";
    a.second = "";
    
    //string a[2]={"",""};
    for (int i = 0; i < word.size(); ++i)
    {
        for (int j = i + 1; j < word.size(); ++j)
        {
            for (int k = j + 1; k < word.size(); ++k)
            {
                for (int m = k + 1; m < word.size(); ++m)
                {
                    if (tolower(word[i]) < tolower(word[j]) && 
                    tolower(word[j]) <tolower(word[k])&&
                    tolower(word[k]) <tolower(word[m]))
                    {
                        str+="(";
                        str+=toupper(word[i]);
                        str+=toupper(word[j]);
                        str+=toupper(word[k]);
                        str+=toupper(word[m]);
                        str+=")";
                        for (int f = 0; f < word.size(); ++f)
                        {
                            if(f==i||f==j||f==k||f==m)
                                newWord+=toupper(word[f]);
                            else
                                newWord+=word[f];

                        }
                        a.first=str;
                        a.second=newWord;
                        return a;
                    }
                }
            }
        }
    }
    return a;
}
int main()
{
    string path="input.txt";
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    cout<<"ERROR";
    else
    {
        string str,text,newtext;
        while(!fin.eof())
        {
            getline(fin,str);
            text+=str+" ";
        }
        fin.close();
        str="";
        for(int i=0;i<text.length();i++)
        {
            if((ispunct(text[i]))||(text[i]==' '))
            {
                Pair pair = IsSorted(str);

                if (pair.first!="")
                    newtext+=pair.second;
                else
                    newtext+=str;
                newtext+=pair.first;
                newtext+=text[i];
                str="";
            }
            else
            {
                str+=text[i];
            }
        }
        ofstream fout;
        fout.open("output.txt");
        fout<<newtext;
        fout.close();
    }
}
