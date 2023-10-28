#include <iostream>

using namespace std;

int calculo(int& tab){
    tab = 6;
    cout << "NA FUNÇÂO: " << tab << endl;
    return tab;
}

int main()
{
    int tab;
    std::cin >> tab;
    calculo(tab);
    cout << "FORA: " << tab << endl;
    return 0;
}