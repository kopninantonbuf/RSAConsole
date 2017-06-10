#include <NTL/ZZ.h> // ���������� ���������� NTL � �������. ZZ ��������� �������� � �������� ������ ������� �������������� �����.
#include <time.h> // ������������ ���� time.h ����������� ��� ��������� ��������������� ����� � ����������� �� �������� �������.
#include <fstream> // ������������ ����, ��������������� ��� ������ � �������.

using namespace std;
using namespace NTL;

//// � ���� ������� ������������ ��� ������� ����� p � q ���������� ���������� NTL (������� GenPrime), ����������� �� ������������ n � �������� ������� ������. �������� sz ��������� ������ ����������� ������ ������������ �����.
//void GenPrimes(ZZ& p, ZZ& q, ZZ& n, ZZ& eulerN, int sz)
//{
//	GenPrime(p, sz);
//	GenPrime(q, sz);
//	n = p * q;
//	eulerN = (p - 1) * (q - 1);
//}
//
//// ������� GenKeys ������ �������� ���������� e � ���������� �� ��� ��������� ���������� d.
//void GenKeys(ZZ& e, ZZ& d, ZZ& eulerN, long sz)
//{
//	do
//		GenPrime(e, sz);
//	while (e >= eulerN && GCD(e, eulerN) != 1);
//	InvMod(d, e, eulerN);
//}
//
//// ������ ��������� � ��������� ������ � ��������� �����.
//void SaveKey(ZZ& e, ZZ& d, ZZ& n)
//{
//	fstream fpublic, fprivate;
//	fpublic.open("PublicKey.txt", ios::out);
//	fprivate.open("PrivateKey.txt", ios::out);
//	if (!fpublic || !fprivate)
//	{
//		cout << "������ ������ � ����. " << endl;
//		system("pause");
//		exit(0);
//	}
//
//	fpublic << e << "\n\n" << n;
//	fprivate << d << "\n\n" << n;
//
//	fpublic.close();
//	fprivate.close();
//}
//
//// �������������� ������ � ���� ZZ.
//ZZ StringToZZ(string str)
//{
//	ZZ number = conv<ZZ>(str[0]);
//	long len = str.length();
//	for (long i = 1; i < len; i++)
//	{
//		number *= 128;
//		number += conv<ZZ>(str[i]);
//	}
//
//	return number;
//}
//
//// �������������� ���� ZZ � ������.
//string ZZToString(ZZ num)
//{
//	long len = ceil(log(num) / log(128));
//	char* str = new char[len];
//	for (long i = len - 1; i >= 0; i--)
//	{
//		str[i] = conv<int>(num % 128);
//		num /= 128;
//	}
//	str[len] = '\0';
//	return (string)str;
//}
//
//// ������� ����������.
//ZZ Encryption(string str, ZZ& e, ZZ& n)
//{
//	ZZ zz_from = StringToZZ(str);
//	return PowerMod(zz_from, e, n);
//}
//
//// ������� ������������.
//string Decryption(ZZ& cipherText, ZZ& d, ZZ& n)
//{
//	return ZZToString(PowerMod(cipherText, d, n));
//}
//
//const long SZ_PRIME = 512;
//const long SZ_E = 256;
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	SetSeed(to_ZZ((double)time(NULL))); // ������������� ���������� ��������������� �����.
//
//	ZZ p, q, n, eulerN, e, d, cipherText;
//	string plainText, decryptedCipherText;
//
//	cout << "��������� ��������� ������� ����� p � q. \n";
//	GenPrimes(p, q, n, eulerN, SZ_PRIME);
//	cout << "p: " << p << endl << endl;
//	cout << "q: " << q << endl << endl;
//	cout << "n: " << n << endl << endl;
//	cout << "euler(N): " << eulerN << endl << endl << "========================================" << endl;
//
//	cout << "��������� �������� � ��������� ����������. \n";
//	GenKeys(e, d, eulerN, SZ_E);
//	cout << "e: " << e << endl << endl;
//	cout << "d: " << d << endl << endl << "========================================" << endl;
//
//	// ���������� ������ � �����.
//	SaveKey(e, d, n);
//	
//	cout << "������� ���������, ������� ��������� ��������. \n";
//	cout << "plainText: ";
//	getline(cin, plainText, '\n');
//
//	// ����������� ���������.
//	cipherText = Encryption(plainText, e, n);
//	cout << endl << "cipherText: " << cipherText << endl << endl;
//
//	// ������������� ���������.
//	decryptedCipherText = Decryption(cipherText, d, n);
//	cout << "decryptedCipherText: " << decryptedCipherText << endl << endl;

#define base_dec_bit 9
#define base 0x40000000  // 2^30

int schet(ZZ& n)
{
	int c = 0;
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return c;
};

bool isMod3Eq0(ZZ& n)
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

ZZ Get_Random_Prime(const int bits)
{
	ZZ Ret;
	if (bits > 0)
		Ret = (rand() % 9 + 1);
	int i;
	for (i = 2; i + base_dec_bit - 1 < bits; i += base_dec_bit)
	{
		int k = 0;
		for (int j = 1; j <= base_dec_bit; ++j)
			k = k * 10 + rand() % 10;
		Ret = Ret * base + k;
	}
	for (int j = i; j < bits - 1; ++j)
		Ret = Ret * 10 + (rand() % 10);

		int k = rand() % 10;
		if (k > 0 && k <= 3)
			k = 1;
		else if (k > 3 && k <= 6)
			k = 3;
		else if (k > 6 && k <= 8)
			k = 7;
		else k = 9;
			
		
		Ret = Ret * 10 + k;

		/*if (isMod3Eq0(Ret) == true)
			Get_Random_Prime(bits);*/
		return Ret;
}



ZZ Get_Random(const int bits)
{
	ZZ Ret;
	if (bits > 0)
		Ret = (rand() % 9 + 1);
	int i;
	for (i = 2; i + base_dec_bit - 1 < bits; i += base_dec_bit)
	{
		int k = 0;
		for (int j = 1; j <= base_dec_bit; ++j)
			k = k * 10 + rand() % 10;
		Ret = Ret * base + k;
	}
	for (int j = i; j < bits; ++j)
		Ret = Ret * 10 + (rand() % 10);

	if (Ret == 2)
		Get_Random(bits);
	return Ret;
}

ZZ Exp_Mod(ZZ& a, ZZ& n)
{
	return PowerMod(a, (n - 1) / 2, n);
}

int main()
{
	srand(time(NULL));
	ZZ a, n;
	ZZ x =(ZZ)1024; //� �����
	x = power2_ZZ(10024);
	int r = schet(x);
	///!!cout << "r= " << r << endl;
	bool b = false;

	while (b == false)
	{
		//GenPrime(n ,r);
		n = Get_Random_Prime(r);
		//cout <<"n= "<< n << endl;
		cout << schet(n) << endl;


		for (int i = 0; i < 2; i++)
		{
			ZZ a;
			a = Get_Random(rand() % r + 1);
			while (a > n)
				a = Get_Random(rand() % r + 1);

			//cout << "a= "<< a << endl;


			if (GCD(a, n) > 1)
			{
				//cout << "Sost" << " " << i << endl;
				break;
			}


			//cout << "J " << Jacobi(a, n) << endl;
			//cout << "Exp " << Exp_Mod(a, n) << endl;

			if (Exp_Mod(a, n) != Jacobi(a, n))
			{
				//cout << "SostSr" << " " << i << endl;
				break;
			}
			if (i == 1)
				b = true;
			
		}
	}
	cout << n << endl;

	system("pause");
}
