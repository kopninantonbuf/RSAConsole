#include <NTL/ZZ.h> // ѕодключаем библиотеку NTL к проекту. ZZ позвол€ет работать с большими целыми числами неограниченной длины.
#include <time.h> // «аголовочный файл time.h потребуетс€ дл€ генерации псевдослучайных чисел в зависимости от текущего времени.

using namespace std;
using namespace NTL;

bool isMod3(ZZ n)
{
	ZZ sum;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	if (sum % 3 == 0)
		return true;
	else return false;
}

ZZ Get_Random_Prime(long bits)
{
	ZZ Ret = RandomLen_ZZ(bits);
	if (Ret % 2 == 0 || Ret % 5 == 0 || isMod3(Ret) == true)
		return Get_Random_Prime(bits);
	else return Ret;
}

ZZ Get_Random(long bits)
{
	ZZ Ret = RandomLen_ZZ(bits);
	if (Ret <= 2)
		return Get_Random(bits);
	else return Ret;
}

ZZ Exp_Mod(ZZ& a, ZZ& n)
{
	ZZ e = PowerMod(a, (n - 1) / 2, n);
	if (e - n == -1)
		return (ZZ)-1;
	else return PowerMod(a, (n - 1) / 2, n);
}

ZZ SolovayStrassen(long bits, int count_of_tests)
{
	ZZ a, n;
	bool b = false;

	while (b == false)
	{
		n = Get_Random_Prime(bits);

		for (int i = 0; i < count_of_tests; i++)
		{
			ZZ a;
			a = Get_Random(rand() % bits + 1);
			while (a > n)
				a = Get_Random(rand() % bits + 1);

			if (GCD(a, n) > 1)
				break;

			if (Exp_Mod(a, n) != Jacobi(a, n))
				break;

			if (i == 1)
				b = true;
		}
	}
	return n;
}
