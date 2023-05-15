#include <iostream>
#include <string>

using namespace std;

struct Aluno
{
    string nm;
    int matr{0}, id{0};
    char sexo;
    float alt{0.0};
    float nota[4];
};

int main()
{
    int N;
    cout << "\nInforme a quantidade de alunos: ";
    cin >> N;

    struct Aluno vec[N];

    for (int i{0}; i < N; i++)
    {
        cout << "\n\nDADOS: ";
        cin >> vec[i].nm >> vec[i].matr >> vec[i].id >> vec[i].sexo >> vec[i].alt;
        cout << "\nNotas: ";
        for (int j{0}; j < 4; j++)
        {
            cin >> vec[i].nota[j];
        }
    }

    cout << "\n\n";
    for (int i{0}; i < N; i++)
    {
        cout << vec[i].nm << "  " << vec[i].id << "  " << vec[i].matr << "  " << vec[i].sexo << "  " << vec[i].alt << "  ";
        cout << "Notas: ";
        for (int j{0}; j < 4; j++)
        {
            cout << vec[i].nota[j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    return 0;
}
