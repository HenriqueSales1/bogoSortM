#include <iostream>
#include <windows.h>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

#define INSTANCE_A 10
#define INSTANCE_B 11
#define INSTANCE_C 12
#define INSTANCE_D 15

void menu();
void create_vector(vector<int> &vet, int size);
void shuffle(vector<int> &vet);
bool is_sorted(vector<int> &vet);
void bogoSort(vector<int> &vet);
void print_vector(vector<int> &vet);

int main(){
    vector<int> vet;
    int op;
    menu();
    cout << "\nOption: ";
    cin >> op;

    if(op == 1){
        create_vector(vet, INSTANCE_A);
        steady_clock::time_point t1 = steady_clock::now();
        bogoSort(vet);
        steady_clock::time_point t2 = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>> (t2-t1);
        print_vector(vet);
        cout << "\nETS: " << time_span.count() << "s";
    }

    if(op == 2){
        create_vector(vet, INSTANCE_B);
        steady_clock::time_point t1 = steady_clock::now();
        bogoSort(vet);
        steady_clock::time_point t2 = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>> (t2-t1);
        print_vector(vet);
        cout << "\nETS: " << time_span.count() << "s";
    }

    if(op == 3){
        create_vector(vet, INSTANCE_C);
        steady_clock::time_point t1 = steady_clock::now();
        bogoSort(vet);
        steady_clock::time_point t2 = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>> (t2-t1);
        print_vector(vet);
        cout << "\nETS: " << time_span.count() << "s";
    }

    if(op == 4){
        create_vector(vet, INSTANCE_D);
        steady_clock::time_point t1 = steady_clock::now();
        bogoSort(vet);
        steady_clock::time_point t2 = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>> (t2-t1);
        print_vector(vet);
        cout << "\nETS: " << time_span.count() << "s";
    }
}

void menu()
{
    cout << "1. Sort 10\n"
            "2. Sort 11\n"
            "3. Sort 12\n"
            "4. Sort 15\n";
}

void create_vector(vector<int> &vet, int size){
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        vet.push_back(rand()%10);
    }
}

void shuffle(vector<int> &vet){
    int pos, random;
    for (int i = 0; i < vet.size(); i++){
        pos = vet[i];
        random = rand()%vet.size();
        vet[i] = vet[random];
        vet[random] = pos;
    }
}

bool is_sorted(vector<int> &vet){
    int n = vet.size();
    while(--n >= 1){
        if (vet[n] < vet[n-1]){
            return false;
        }
    }
    return true;
}

void bogoSort(vector<int> &vet){
    while(!is_sorted(vet)){
        shuffle(vet);
    }
}

void print_vector(vector<int> &vet){
    for(int i = 0; i < vet.size(); i++){
        cout << vet[i] << " ";
    }
}
