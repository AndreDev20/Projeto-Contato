#include <iostream>
#include <string>
#include <ctime> 
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:

    Data() : dia(0), mes(0), ano(0) {}
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}


    int getDia() const { return dia; }
    void setDia(int d) { dia = d; }

    int getMes() const { return mes; }
    void setMes(int m) { mes = m; }

    int getAno() const { return ano; }
    void setAno(int a) { ano = a; }
};


class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() : email(""), nome(""), telefone(""), dtnasc() {}
    Contato(string e, string n, string t, Data d) : email(e), nome(n), telefone(t), dtnasc(d) {}

    string getEmail() const { return email; }
    void setEmail(string e) { email = e; }

    string getNome() const { return nome; }
    void setNome(string n) { nome = n; }

    string getTelefone() const { return telefone; }
    void setTelefone(string t) { telefone = t; }

    Data getDtnasc() const { return dtnasc; }
    void setDtnasc(Data d) { dtnasc = d; }
    
    int idade() const {
        time_t t = time(0);
        struct tm *now = localtime(&t);
        int anoAtual = now->tm_year + 1900;
        return anoAtual - dtnasc.getAno();
    }
};

int main() {
    Contato contatos[5];

    cout << "Cadastro de 5 Contatos:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nContato " << (i + 1) << ":" << endl;
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Email: ";
        getline(cin, email);

        cout << "Telefone: ";
        getline(cin, telefone);

        cout << "Dia de nascimento: ";
        cin >> dia;
        cout << "Mes de nascimento: ";
        cin >> mes;
        cout << "Ano de nascimento: ";
        cin >> ano;
        cin.ignore(); 
        Data dataNasc(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, dataNasc);
    }

    cout << "\nExibindo Contatos:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "---------------------------" << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
    }

    return 0;
}
