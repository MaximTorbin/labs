// #include <iostream>
// #include <algorithm>
// #include <string>
// int main()
// {
//     bool fl=true;
//     std::string strInput;
//     std::cin>>strInput;
//     int lenStr=strInput.length();
//     for (int i=0;i<lenStr/2;i++)
//     {
//         if (strInput[i]!=strInput[lenStr-1-i])
//         {
//             fl=false;
//             std::cout<<"is not a palindrom";
//             break;
//         }

//     }
//     if(fl)
//         std::cout<<"is a palindrom";
// }



#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


void nextStep(int stepCount,int y,int x,char (*mas)[100],int (*steps)[100], std::vector<int>* answers)
{
    if (mas[y][x]=='E')
    {
        answers->push_back(stepCount);
        return;
    }
    if (stepCount>steps[y][x]&&steps[y][x]!=-1)
        return;
    else
        steps[y][x]=stepCount;
    for(int i=-1;i<2;i++)
    {
        for(int j=-1;j<2;j++)
        {
            if(i!=0 || j!=0)
            {
                int newY = y + j;
                int newX = x + i;
                if (newY >= 0 && newY < 100 && newX >= 0 && newX < 100)
                {
                    if (mas[newY][newX] == '.' || mas[newY][newX] == 'E')
                    {
                        nextStep(stepCount + 1, newY, newX, mas,steps, answers);
                    }
                }
            }
        }
    }
}
int main()
{
    int iStart;
    int jStart;
    std::vector<int> answers;
    char mas[100][100];
    std::fill(&mas[0][0], &mas[0][0]+100*100,0);
    std::string str;
    std::ifstream in("input.txt");
    int i=0;

    while(!in.eof())
    {
        getline(in,str);
        for (int j=0; j<(str.length());j++ )
        {
            mas[i][j]=str[j];
            if (str[j]=='S')
            {
                iStart=i;
                jStart=j;
            }
        }
        i++;
    }
    int steps[100][100];
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            steps[i][j] = -1;
        }
    }
    nextStep(0, iStart, jStart, mas,steps, &answers);
    if(answers.empty())
        std::cout<<"-1";
    else
        std::cout << *std::min_element(answers.begin(), answers.end());
    in.close();
    return 0;
}
