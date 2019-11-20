#pragma once
class Csomopont
{
public:
	Csomopont(char b = '/') :betu(b), balNulla(0), jobbEgy(0)
	{
	};
	~Csomopont()
	{
	};
	// Aktu�lis csom�pont, mondd meg n�kem, ki a bal oldali gyermeked
	// (a C verzi� logik�j�val m�xik ez is: ha nincs, akkor a null megy vissza)
	Csomopont* nullasGyermek() const
	{
		return balNulla;
	}
	// Aktu�lis csom�pon,t mondd meg n�kem, ki a jobb oldali gyermeked?
	Csomopont* egyesGyermek() const
	{
		return jobbEgy;
	}
	// Aktu�lis csom�pont, �mhol legyen a "gy" mutatta csom�pont a bal oldali gyereked!
	void ujNullasGyermek(Csomopont* gy)
	{
		balNulla = gy;
	}
	// Aktu�lis csom�pont, �mhol legyen a "gy" mutatta csom�pont a jobb oldali gyereked!
	void ujEgyesGyermek(Csomopont* gy)
	{
		jobbEgy = gy;
	}
	// Aktu�lis csom�pont: Te milyen bet�t hordozol?
	// (a const kulcssz�val jelezz�k, hogy nem b�ntjuk a p�ld�nyt)
	char getBetu() const
	{
		return betu;
	}

private:
	// friend class LZWBinFa; /* mert ebben a valtozatban az LZWBinFa met�dusai nem k�zvetlen�l
	// a Csomopont tagjaival dolgoznak, hanem be�ll�t�/lek�rdez� �zenetekkel �rik el azokat */

	// Milyen bet�t hordoz a csom�pont
	char betu;
	// Melyik m�sik csom�pont a bal oldali gyermeke? (a C v�ltozatb�l "�r�k�lt" logika:
	// ha hincs ilyen csermek, akkor balNulla == null) igaz
	Csomopont* balNulla;
	Csomopont* jobbEgy;
	// nem m�solhat� a csom�pont (�k�rszab�ly: ha van valamilye a szabad t�rban,
	// letiltjuk a m�sol� konstruktort, meg a m�sol� �rt�kad�st)
	Csomopont(const Csomopont&); //m�sol� konstruktor
	Csomopont& operator= (const Csomopont&);
};