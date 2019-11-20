#pragma once
#include "Csomopont.h"
class LZWBinFa
{
public:
	LZWBinFa() :fa(&gyoker)
	{
	}
	~LZWBinFa()
	{
		szabadit(gyoker.egyesGyermek());
		szabadit(gyoker.nullasGyermek());
	}

	void insert(char b)
	{
		// Mit kell betenni éppen, '0'-t?
		if (b == '0')
		{
			/* Van '0'-s gyermeke az aktuális csomópontnak?
		   megkérdezzük Tõle, a "fa" mutató éppen reá mutat */
			if (!fa->nullasGyermek())	// ha nincs, hát akkor csinálunk
			{
				// elkészítjük, azaz páldányosítunk a '0' betû akt. parammal
				Csomopont* uj = new Csomopont('0');
				// az aktuális csomópontnak, ahol állunk azt üzenjük, hogy
				// jegyezze már be magának, hogy nullás gyereke mostantól van
				// küldjük is Neki a gyerek címét:
				fa->ujNullasGyermek(uj);
				// és visszaállunk a gyökérre (mert ezt diktálja az alg.)
				fa = &gyoker;
			}
			else			// ha van, arra rálépünk
			{
				// azaz a "fa" pointer már majd a szóban forgó gyermekre mutat:
				fa = fa->nullasGyermek();
			}
		}
		// Mit kell betenni éppen, vagy '1'-et?
		else
		{
			if (!fa->egyesGyermek())
			{
				Csomopont* uj = new Csomopont('1');
				fa->ujEgyesGyermek(uj);
				fa = &gyoker;
			}
			else
			{
				fa = fa->egyesGyermek();
			}
		}
	}
	void kiir(void)
	{
		melyseg = 0;
		// ha nem mondta meg a hívó az üzenetben, hogy hova írjuk ki a fát, akkor a
		// sztenderd out-ra nyomjuk
		kiir(&gyoker, std::cout);
	}

	int getMelyseg(void);
	double getAtlag(void);
	double getSzoras(void);

	friend std::ostream& operator<< (std::ostream& os, LZWBinFa& bf)
	{
		bf.kiir(os);
		return os;
	}
	void kiir(std::ostream& os)
	{
		melyseg = 0;
		kiir(&gyoker, os);
	}

private:


	/* Mindig a fa "LZW algoritmus logikája szerinti aktuális" csomópontjára mutat */
	Csomopont* fa;
	// technikai
	int melyseg, atlagosszeg, atlagdb;
	double szorasosszeg;
	// szokásosan: nocopyable
	LZWBinFa(const LZWBinFa&);
	LZWBinFa& operator= (const LZWBinFa&);

	/* Kiírja a csomópontot az os csatornára. A rekurzió kapcsán lásd a korábbi K&R-es utalást... */
	void kiir(Csomopont* elem, std::ostream& os)
	{
		// Nem létezõ csomóponttal nem foglalkozunk... azaz ez a rekurzió leállítása
		if (elem != NULL)
		{
			++melyseg;
			kiir(elem->egyesGyermek(), os);
			// ez a postorder bejáráshoz képest
			// 1-el nagyobb mélység, ezért -1
			for (int i = 0; i < melyseg; ++i)
				os << "---";
			os << elem->getBetu() << "(" << melyseg - 1 << ")" << std::endl;
			kiir(elem->nullasGyermek(), os);
			--melyseg;
		}
	}
	void szabadit(Csomopont* elem)
	{
		// Nem létezõ csomóponttal nem foglalkozunk... azaz ez a rekurzió leállítása
		if (elem != NULL)
		{
			szabadit(elem->egyesGyermek());
			szabadit(elem->nullasGyermek());
			// ha a csomópont mindkét gyermekét felszabadítottuk
			// azután szabadítjuk magát a csomópontot:
			delete elem;
		}
	}

protected:			// ha esetleg egyszer majd kiterjesztjük az osztályt, mert
	// akarunk benne valami újdonságot csinálni, vagy meglévõ tevékenységet máshogy... stb.
	// akkor ezek látszanak majd a gyerek osztályban is

	/* A fában tagként benne van egy csomópont, ez erõsen ki van tüntetve, Õ a gyökér: */
	Csomopont gyoker;
	int maxMelyseg;
	double atlag, szoras;

	void rmelyseg(Csomopont* elem);
	void ratlag(Csomopont* elem);
	void rszoras(Csomopont* elem);

};
