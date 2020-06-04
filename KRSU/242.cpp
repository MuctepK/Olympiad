#include <bits/stdc++.h>
using namespace std;
class Tarif{
public:
    string name;
    double price;
    int type, priority;
    Tarif(string name, double price, int type, int priority){
        this->name =name;
        this->price = price;
        this->type = type;
        this->priority = priority;
    }

};

void insert_tarif(Tarif tarif);

vector <Tarif> vec, usual;
bool  used[500];
map <string, int> result_priority;
map <string, int> result_type;
string name; double price;
int N, depth, type, priority;
bool to_check;
int main(){
    cin >> N >> depth >> to_check;

    for (int i =0;i<N;i++){
        cin >> name >> price >> type >> priority;
        Tarif tarif(name, price, type, priority);
        result_type[name] = type;
        insert_tarif(tarif);
        vec.emplace_back(tarif);
    }
    sort(usual.begin(),usual.end(), [](const Tarif &a, const Tarif &b){
        return a.price < b.price ? true : a.name < b.name;
    });
    int start = 1;
    for (auto it : usual){
        while (used[start]){
            start++;
        }
        used[start] = true;
        if (start > depth)start=-1;
        result_priority[it.name] = start;
    }
    for (auto it: vec){
        cout << it.name << " " << it.price << " " << result_type[it.name] << " " << result_priority[it.name] << endl;

    }
}

void insert_tarif(Tarif tarif) {
    if (tarif.priority==0)
        return;


    if (tarif.priority==-1){
        usual.emplace_back(tarif);
        result_type[tarif.name] = 0;
        return;
    }
    if (tarif.type){
        if (!to_check) {
            usual.emplace_back(tarif);
        }

        else {
            used[tarif.priority] = true;
            if (tarif.priority>depth) tarif.priority = -1;
            result_priority[tarif.name] = tarif.priority;
        }
    }
    else{
        usual.emplace_back(tarif);
    }

}
