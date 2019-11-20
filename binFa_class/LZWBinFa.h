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
		// Mit kell betenni �ppen, '0'-t?
		if (b == '0')
		{
			/* Van '0'-s gyermeke az aktu�lis csom�pontnak?
		   megk�rdezz�k T�le, a "fa" mutat� �ppen re� mutat */
			if (!fa->nullasGyermek())	// ha nincs, h�t akkor csin�lunk
			{
				// elk�sz�tj�k, azaz p�ld�nyos�tunk a '0' bet� akt. parammal
				Csomopont* uj = new Csomopont('0');
				// az aktu�lis csom�pontnak, ahol �llunk azt �zenj�k, hogy
				// jegyezze m�r be mag�nak, hogy null�s gyereke mostant�l van
				// k�ldj�k is Neki a gyerek c�m�t:
				fa->ujNullasGyermek(uj);
				// �s vissza�llunk a gy�k�rre (mert ezt dikt�lja az alg.)
				fa = &gyoker;
			}
			else			// ha van, arra r�l�p�nk
			{
				// azaz a "fa" pointer m�r majd a sz�ban forg� gyermekre mutat:
				fa = fa->nullasGyermek();
			}
		}
		// Mit kell betenni �ppen, vagy '1'-et?
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
		// ha nem mondta meg a h�v� az �zenetben, hogy hova �rjuk ki a f�t, akkor a
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


	/* Mindig a fa "LZW algoritmus logik�ja szerinti aktu�lis" csom�pontj�ra mutat */
	Csomopont* fa;
	// technikai
	int melyseg, atlagosszeg, atlagdb;
	double szorasosszeg;
	// szok�sosan: nocopyable
	LZWBinFa(const LZWBinFa&);
	LZWBinFa& operator= (const LZWBinFa&);

	/* Ki�rja a csom�pontot az os csatorn�ra. A rekurzi� kapcs�n l�sd a kor�bbi K&R-es utal�st... */
	void kiir(Csomopont* elem, std::ostream& os)
	{
		// Nem l�tez� csom�ponttal nem foglalkozunk... azaz ez a rekurzi� le�ll�t�sa
		if (elem != NULL)
		{
			++melyseg;
			kiir(elem->egyesGyermek(), os);
			// ez a postorder bej�r�shoz k�pest
			// 1-el nagyobb m�lys�g, ez�rt -1
			for (int i = 0; i < melyseg; ++i)
				os << "---";
			os << elem->getBetu() << "(" << melyseg - 1 << ")" << std::endl;
			kiir(elem->nullasGyermek(), os);
			--melyseg;
		}
	}
	void szabadit(Csomopont* elem)
	{
		// Nem l�tez� csom�ponttal nem foglalkozunk... azaz ez a rekurzi� le�ll�t�sa
		if (elem != NULL)
		{
			szabadit(elem->egyesGyermek());
			szabadit(elem->nullasGyermek());
			// ha a csom�pont mindk�t gyermek�t felszabad�tottuk
			// azut�n szabad�tjuk mag�t a csom�pontot:
			delete elem;
		}
	}

protected:			// ha esetleg egyszer majd kiterjesztj�k az oszt�lyt, mert
	// akarunk benne valami �jdons�got csin�lni, vagy megl�v� tev�kenys�get m�shogy... stb.
	// akkor ezek l�tszanak majd a gyerek oszt�lyban is

	/* A f�ban tagk�nt benne van egy csom�pont, ez er�sen ki van t�ntetve, � a gy�k�r: */
	Csomopont gyoker;
	int maxMelyseg;
	double atlag, szoras;

	void rmelyseg(Csomopont* elem);
	void ratlag(Csomopont* elem);
	void rszoras(Csomopont* elem);

};
