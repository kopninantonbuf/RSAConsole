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



