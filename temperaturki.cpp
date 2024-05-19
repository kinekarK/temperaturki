#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

float CelToKel(float st_Cel);
float CelToFahr(float st_Cel);
void Logowanie();

int main()
{

    Logowanie();

    
    float T_MIN{}, T_MAX{}, wartosc{};
    cout << "\n\tWitaj w programie 'zapis oraz wyswietlanie tabeli temperatur'";
    cout << "\n\t(Temperatura najnizsza nie moze byc wieksza niz temperatura najwyzsza!)";
    do // sprawdzamy czy temperatura minimalna jest mniejsza niz maksymalna
    {
        cout << "\n\n\tPodaj najmniejsza wartosc ktora chcesz przedstawic w tabeli: ";
        cin >> T_MIN;
        cout << "\n\n\tPodaj najwieksza temperature ktora chcesz przedstawic w tabeli: ";
        cin >> T_MAX;
    } while (T_MAX < T_MIN);
    cout << "\n\n\tPodaj o ile chcesz zwiekszac swoja wartosc przedstawiona w tabeli";
    do // sprawdzamy czy wartosc ktora pokazuje nam o co ile wyswietlamy temperatura jest wieksza od 0
    {
        cout << "\n\n\t(wartosc nie moze byc mniejsza niz 0!): ";
        cin >> wartosc;
    } while (wartosc < 0);

    cout << "\tT [st.C]  T[K]       T[st.F]" << endl;
    cout.setf(ios::fixed | ios::right);

    ofstream plik("wyniki.txt");                        //tworzymi plik "wyniki.txt"
    plik.setf(ios::fixed);
    plik << "\tT [st.C]  T[K]       T[st.F]" << endl;
    plik.setf(ios::fixed | ios::right);                 //wyrównujemy pozycje tekstu do prawej
    for (T_MIN; T_MIN <= T_MAX; T_MIN += wartosc)
    {
        cout << "\t"
            << setw(3) << setprecision(0) << T_MIN << "    "             //Ustawiamy ile miejsc po przecinku
            << setw(8) << setprecision(2) << CelToKel(T_MIN) << "    "   //chcemy aby nasza temperatura nam 
            << setw(6) << setprecision(1) << CelToFahr(T_MIN) << endl;   // wyswietlala

        plik << "\t"
            << setw(3) << setprecision(0) << T_MIN << "    "
            << setw(8) << setprecision(2) << CelToKel(T_MIN) << "    "
            << setw(6) << setprecision(1) << CelToFahr(T_MIN) << endl;
    }
        plik.close();
        cout << "\n\n\tDANE ZOSTALY ZAPISANE DO PLIKU!"; 
    
}

float CelToKel(float st_Cel)
{
    float st_Kel{};
    st_Kel = st_Cel - 273.15;
    return st_Kel;
}
float CelToFahr(float st_Cel) 
{
    float st_Fahr{};
    st_Fahr = (9.0/5) * st_Cel + 32;
    return st_Fahr;
}
void Logowanie()
{
    string poprawne, haslo;
    ifstream autoryzacja("autoryzacja.txt"); // otwarcie pliku
    if (autoryzacja.is_open())
    {
        autoryzacja >> poprawne;
    }
    autoryzacja.close();

    
    cout << "\n\tWitaj w programie pt. 'Temperaturki'." << "\n\tAby przejsc dalej, musisz podac haslo!";
    cout << "\n\t Haslo znajduje sie w pliku udostepnionym ci przez autoryzowanego czlonka personelu!";
    do
    {
        cout << "\n\tHaslo: "; cin >> haslo;
    } while (haslo != poprawne);
}