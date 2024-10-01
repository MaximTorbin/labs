#include <iostream>
#include <algorithm>
using namespace std;
bool simp(int x){
    for(int i=2;i<(sqrt(x)+1);i++){
        if (x % i == 0) {
            return true;
        }
    }
    if (x <= 0) {
        return true;
    }
}
//
//int main(){
//    setlocale(LC_ALL, "Russian");
//    cout<<"������� ������ �������:\n";
//    int l;
//    bool fl=0;
//    cin>>l;
//    int* ar=new int[l];
//    for(int i=0;i<l;i++){
//        cin>>ar[i];
//        if (simp(ar[i]) == 0) {
//            fl = 1;
//        }
//    }
//    if (fl==0) {
//        sort(ar, ar + l);
//        cout << "��������������� �������� �������:" << endl;
//        for (int i = 0; i < l; i++) {
//            cout << ar[i] << " ";
//        }
//    }
//    else cout << "� ������� ���� ������� �������";
//    return 0;
//    
//}



//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//struct NumberProperties {
//    int number;
//    int digitSum;
//    int digitProduct;
//
//    NumberProperties(int num) : number(num), digitSum(0), digitProduct(1) {
//        int temp = num;
//        while (temp > 0) {
//            int digit = temp % 10;
//            digitSum += digit;
//            digitProduct *= digit;
//            temp /= 10;
//        }
//    }
//};
//
//// ���������� ��� ����������
//bool compare(const NumberProperties& a, const NumberProperties& b) {
//    if (a.digitSum != b.digitSum) {
//        return a.digitSum < b.digitSum;
//    }
//    if (a.digitProduct != b.digitProduct) {
//        return a.digitProduct < b.digitProduct;
//    }
//    return a.number < b.number;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    int n;
//
//    std::cout << "������� ���������� ����������� ����� (n <= 1000): ";
//    std::cin >> n;
//
//    if (n <= 0 || n > 1000) {
//        std::cout << "������: n ������ ���� � �������� �� 1 �� 1000." << std::endl;
//        return 1;
//    }
//
//    std::vector<NumberProperties> numbers;
//
//    // ���� �����
//    std::cout << "������� " << n << " ����������� �����:" << std::endl;
//    for (int i = 0; i < n; ++i) {
//        int num;
//        std::cin >> num;
//
//        // �������� �� �������������
//        if (num <= 0) {
//            std::cout << "������: ����� ������ ���� �����������." << std::endl;
//            return 1;
//        }
//
//        numbers.emplace_back(num); // ������� ������ � ��������� � ������
//    }
//
//    // ���������� �����
//    std::sort(numbers.begin(), numbers.end(), compare);
//
//    // ����� ��������������� �����
//    std::cout << "��������������� �����:" << std::endl;
//    for (const auto& numProp : numbers) {
//        std::cout << numProp.number << std::endl;
//    }
//
//    return 0; // �������� ���������� ���������
//}
int main() {
    setlocale(LC_ALL, "Russian");

    int m, n, pr, prm=0, str=0,a;
    cout << "���������� �����:";
    cin >> m;
    cout << "���������� ��������:";
    cin >>n;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        pr = 1;
        for (int j=0; j < n; j++) {
            cout << "������� ������� " << i+1 << " ������ " << j+1 << " �������:";
            cin >> matrix[i][j];
            pr = pr * matrix[i][j];
            if (pr > prm) {
                prm = pr;
                str = i;
            }
        }
    }
    for (int i = 0; i < n;i++) {
        matrix[str][i] = prm;
    }

    cout << "������������ ������������:" << prm << endl;
    cout << "�������:";

    for (int i = 0; i < m; i++) {
        cout << endl;
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j]<<" ";

        }
    }

    return 0;
}