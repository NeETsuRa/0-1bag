// 01nahrbtnik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Vnesi volumen: ";
	int V;
	cin >> V;

	cout << endl << "Koliko bo predmetov? ";
	int n;
	cin >> n;

	double * pol[3];
	for (int i=0; i<3; i++)
		pol [i]=new double [n];

	for (int i=0; i<n; i++){
		cout << "vnesi volumen " << i+1 << "-tega predmeta: ";
		cin >> pol [0][i];
		cout << "vnesi ceno " << i+1 << "-tega predmeta: ";
		cin >> pol [1][i];
		pol [2][i]=(pol[1][i]/pol[0][i]);
	}

	//urejanje

	int* res = new int [n];

	for (int i=0; i<n; i++){
		if (pol[0][i]<=V){
			res [i]=1;
			V-=pol[0][i];}
		else
			res [i]=0;
	}

	int skup = 0;
	for (int i=0; i<n; i++)
		skup+=(res[i]*pol[1][i]);

	cout << "elementi si sledijo kot:" << endl;
	for (int j=0; j<3; j++){
		for (int i=0; i<n; i++){
			cout << pol [j][i] << " ";
		}
		cout << endl;
	}



	cout << "vstavimo elemente: " << endl;
		for (int i=0; i<n; i++)
			cout << res [i] << " ";
		cout << endl;

	cout << "skupna vrednost v nahrbtniku je: " <<  skup << endl;;




	for (int i=0; i<3; i++)
		delete [] pol[i];
	delete [] res;



	cin.ignore();
	cin.get();

	return 0;
}

