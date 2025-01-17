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




// #include <iostream>
// #include <fstream>
// #include <string>
// #include <algorithm>
// #include <vector>

// const int ROWS = 100;
// const int COLS = 100;

// void nextStep(int stepCount, int y, int x, char (*mas)[COLS], int* minSteps) {
//     // Проверка выхода за границы массива
//     if (y < 0 || y >= ROWS || x < 0 || x >= COLS) {
//         return;
//     }

//     // Проверка, является ли текущая ячейка конечной точкой
//     if (mas[y][x] == 'E') {
//         if (*minSteps == -1 || stepCount < *minSteps) {
//             *minSteps = stepCount;
//         }
//         return;
//     }

//     // Пометка текущей ячейки как посещенной
//     mas[y][x] = '#';

//     // Перебор всех соседних ячеек
//     for (int i = -1; i <= 1; i++) {
//         for (int j = -1; j <= 1; j++) {
//             if (i != 0 || j != 0) { // Пропуск текущей ячейки
//                 int newY = y + j;
//                 int newX = x + i;

//                 // Проверка выхода за границы массива
//                 if (newY >= 0 && newY < ROWS && newX >= 0 && newX < COLS) {
//                     // Проверка, является ли соседняя ячейка допустимой
//                     if (mas[newY][newX] == '.' || mas[newY][newX] == 'E') {
//                         nextStep(stepCount + 1, newY, newX, mas, minSteps);
//                     }
//                 }
//             }
//         }
//     }
// }

// int main() {
//     int iStart = -1;
//     int jStart = -1;
//     char mas[ROWS][COLS];
//     std::fill(&mas[0][0], &mas[0][0] + ROWS * COLS, '.'); // Инициализация всеми точками

//     std::string str;
//     std::ifstream in("input.txt");
//     int i = 0;
//     while (std::getline(in, str)) {
//         for (int j = 0; j < str.length(); j++) {
//             if (i < ROWS && j < COLS) {
//                 mas[i][j] = str[j];
//                 if (str[j] == 'S') {
//                     iStart = i;
//                     jStart = j;
//                 }
//             }
//         }
//         i++;
//     }
//     in.close();

//     // Проверка нахождения начальной точки
//     if (iStart == -1 || jStart == -1) {
//         std::cout << "-1";
//         return 0;
//     }

//     int minSteps = -1;
//     nextStep(0, iStart, jStart, mas, &minSteps);

//     std::cout << (minSteps != -1 ? std::to_string(minSteps) : "-1");

//     return 0;
// }