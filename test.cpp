#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int n, br = 0;
    ifstream datoteka("C:/Users/marti/OneDrive - CARNET/Dokumenti/GitHub/test_martin/imenik.txt");
    string *prezimeIme = new string[101];
    string linija;

    unordered_set<string> imenaSet;

    while (getline(datoteka, linija))
    {
        prezimeIme[br] = linija;
        cout << linija << endl;
        imenaSet.insert(linija);
        br++;
    }
    datoteka.close();

    cout << "Unesite broj osoba čije podatke želite unijeti: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n;)
    {
        cout << "Unesite prezime i ime osobe: ";
        getline(cin, linija);
        if (imenaSet.find(linija) == imenaSet.end())
        {
            prezimeIme[br + i] = linija;
            imenaSet.insert(linija);
            i++;
        }
        else
        {
            cout << "To ime je već uneseno. Molimo unesite drugo ime." << endl;
        }
    }
    br += n;

    sort(prezimeIme, prezimeIme + br);

    ofstream izlaznaDatoteka("C:/Users/marti/OneDrive - CARNET/Dokumenti/GitHub/test_martin/imenik.txt");
    for (int i = 0; i < br; i++)
    {
        izlaznaDatoteka << prezimeIme[i] << endl;
    }
    izlaznaDatoteka.close();

    delete[] prezimeIme;

    return 0;
}