#include <iostream>
#include <string>

using namespace std;

bool sprawdzHaslo(string &);
void menu();

int main(){

    menu();

    return 0;
}

bool sprawdzHaslo(string & haslo){

/*
    duzeZnaki : 65 - 90
    maleZnaki : 97 - 122
    specjaln  : 33 - 47 + 58 - 64
    liczby    : 48 - 57
*/

bool duzeZnaki = false, maleZnaki = false, specjalneZnaki = false, liczby = false;
int sprawdzenie = 0;

    for(int i=0; i<haslo.length(); i++){
        if( haslo[i] >= 65 && haslo[i] <= 90 && !duzeZnaki ){
            duzeZnaki = true;
            sprawdzenie++;
        }

        if( haslo[i] >= 97 && haslo[i] <= 122 && !maleZnaki ){
            maleZnaki = true;
            sprawdzenie++;
        }

        if( ( ( haslo[i] >= 33 && haslo[i] <= 47 ) || ( haslo[i] >= 58 && haslo[i] <= 64 ) )  && !specjalneZnaki ){
            specjalneZnaki = true;
            sprawdzenie++;
        }

        if( haslo[i] >= 48 && haslo[i] <= 57 && !liczby ){
            liczby = true;
            sprawdzenie++;
        }
    }

    if( sprawdzenie == 4 && haslo.length() >= 8 )
        return true;
    else
        return false;
}

void menu(){

string haslo;
cout<<"Podaj bezpieczne haslo: ";
cin>>haslo;

    if( sprawdzHaslo(haslo) )
        cout<<"Haslo bezpieczne!";
    else
        cout<<"Haslo nie jest bezpieczne!";
}
