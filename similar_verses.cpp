#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void wyswietlWiersze(int pocz, int nast, int wsp)
{
	cout << "\n Współczynnik wierszy " << pocz << " oraz " << nast << " jest równy: " << wsp << endl;
}

int obl(int* tab, int size, int wiersz, int x)
{
	int suma = 0;
	bool powtarzaj = true;
	int y = wiersz * size;;
	int licznik = 0;

	while (licznik < size)
	{
		suma += pow(tab[x] - tab[y], 2);
		y++;
		x++;
		licznik++;
	}
	return suma;
}

int zestawienieWierszy(int* tab, int ROZMIAR, int& wiersz1, int& wiersz2)
{
	int i = 0;
	int x = 0;
	int nastepnyWiersz = 2;
	int poczatkowyWiersz = 1;
	int licznik = 0;
	bool powtorz = true, a = true;
	int wierszDoZestawienia = 1;
	int wsp;
	int najmniejsza;

	while (powtorz)
	{
		if (licznik == ROZMIAR - poczatkowyWiersz)	//zmiana początkowego wiersza
		{
			poczatkowyWiersz++;
			wierszDoZestawienia = poczatkowyWiersz;
			x += ROZMIAR;
			licznik = 0;
			nastepnyWiersz = poczatkowyWiersz + 1;
		}

		if (poczatkowyWiersz + 1 == ROZMIAR) //STOP pętli
		{
			powtorz = false;
		}

		wsp = obl(tab, ROZMIAR, wierszDoZestawienia, x);

		if (a) //jednorazowe nadanie wartości zmiennej najmniejsza
		{
			najmniejsza = wsp;
			a = false;
		}

		wyswietlWiersze(poczatkowyWiersz, nastepnyWiersz, wsp);

		wierszDoZestawienia++;
		licznik++;
		i++;

		if (licznik != 0 && wsp < najmniejsza)
		{
			swap(wsp, najmniejsza);
			wiersz1 = poczatkowyWiersz;
			wiersz2 = nastepnyWiersz;
		}
		nastepnyWiersz++;
	}
	return najmniejsza;
}

int main()
{
	setlocale(LC_ALL, "");
	constexpr int ROZMIAR = 4;
	int tab2D[ROZMIAR][ROZMIAR];
	int tab[ROZMIAR * ROZMIAR];
	int wiersz, kolumna, i = 0;
	int wiersz1 = 0, wiersz2 = 0;

	srand(time(0));

	for (wiersz = 0; wiersz < ROZMIAR; wiersz++)	//dobranie losowych wartosci do tablicy
	{
		for (kolumna = 0; kolumna < ROZMIAR; kolumna++)
		{
			tab2D[wiersz][kolumna] = rand() % 10;
		}
	}

	for (wiersz = 0; wiersz < ROZMIAR; wiersz++)	//przekształcenie tablicy 2D na tablice 1D
	{
		for (kolumna = 0; kolumna < ROZMIAR; kolumna++)
		{
			tab[i] = tab2D[wiersz][kolumna];
			i++;
		}
	}

	int wsp = zestawienieWierszy(tab, ROZMIAR, wiersz1, wiersz2);

	cout << endl << " Najmniejszy współczynnik różnicy wierszy wynosi " << wsp << " i wystepuje między wierszami " << wiersz1 << " oraz " << wiersz2 << endl;
}