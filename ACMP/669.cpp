// Произведение цифр - 3
// (Время: 1 сек. Память: 16 Мб Сложность: 39%)
// Найти наименьшее и наибольшее натуральные числа, произведение цифр в которых равно заданному натуральному числу M или сообщить, что таких чисел не существует. Для записи искомых чисел нельзя использовать цифры 0 и 1.

// Входные данные
// В единственной строке входного файла INPUT.TXT записано натуральное число M (2 ≤ M ≤ 1000).

// Выходные данные
// В единственную строку выходного файла OUTPUT.TXT нужно вывести два натуральных числа в неубывающем порядке. Если таких чисел не существует, то вывести -1 -1.
#include <bits/stdc++.h>
using namespace std;
int first[10];
int second[10];
int main() {
    
    long N;
    cin >> N;
   long temp = N;
    for (int i =9;i>1;i--){
        while (temp%i==0){
            temp/=i;
            first[i]++;
        }
    }
    for (int i =2;i<10;i++){
        while (N%i==0){
            N/=i;
            second[i]++;
        }
    } 
    if (N!=1){
        cout << -1 << " " << -1;
        return 0;
    }
    else{
    for (int i =2;i<10;i++){
        while (first[i]){
            cout << i;
            first[i]--;
        }
    }
    cout << " ";
    for (int i =9;i>1;i--){
        while (second[i]){
            cout << i;
            second[i]--;
        }
    }
    }
}
