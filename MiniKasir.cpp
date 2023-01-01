#include<iostream>
#include<stdio.h>
#include<windows.h>
#define max 70
using namespace std;

    int kode[max];
    string nama[max];
    double harga[max],jumlah[max],total[max],tunai; 
	int keterangan[max];
    float totalharga,bayar;
	int diskon;
    float potongan;
    int i=0;
    char y;
    bool isok;
    string toko;
void nama_toko()
{
	
	cout<<"TOKO  : ";
	getline(cin,toko);
}
void input_barang()
{
	do {
        
        cout << "barang ke	        : " << i+1 <<endl;
        cout << "Kode Barang 		: ";
        cin >> kode[i];
        cout << "Nama Barang		: ";
        cin >> nama[i];
        cout << "Harga Satuan		: Rp ";
        cin >> harga[i];
        cout << "jumlah             : ";
		cin>>jumlah[i];
		total[i] = harga[i]*jumlah[i];
		
    

        cout << "Tambah data lagi? [Y/T] ";
        cin >> y;
        switch (y){
            case 'Y': isok = true; break;
            case 'y': isok = true; break;
            case 'T': isok = false; break;
            case 't': isok = false; break;
            default : isok = false;
        }
        i++;
    } while (isok);
}
void kepala_tabel()
{
	
	system("cls");
	cout<<"struck belanja"<<endl;
    cout <<"toko  "<<toko<<endl;
   	cout<<"----------------------------------------------------------------------------------------- \n";
	     //          1         2         3         4         5         6         7   
	     //012345678901234567890123456789012345678901234567890123456789012345678901
	cout<<"| No | Kode barang | Nama Barang                | Total harga satuan |jumlah|total harga | \n";
	cout<<"------------------------------------------------------------------------------------------ \n";
}
void output()
{
	 
    for(int x=0; x<i; x++){
    	
    	
    cout << x+1 << "    |" << kode[x] << "         |" << nama[x] << "                        |" << harga[x] << "               |" << jumlah[x] << "     |" << total[x] << "      |"<<endl;
    totalharga += total[x];
    potongan =total[x] * diskon;
     if (totalharga>=500000)
	{
		diskon=0.05*totalharga;
	}
	else if (totalharga>=250000)
	{
		 diskon = 0.025*totalharga;
	}
	else {
		 diskon = 0*totalharga;
	}
	bayar=totalharga-diskon;
    
    }
    cout<<"------------------------------------------------------------------------------------------ \n";
   
    cout<<endl;
    cout << "Total Belanja : Rp "<< totalharga << endl;
    cout << "Potongan      : Rp " <<diskon << endl;
    cout << "Total Bayar   : Rp "<<bayar<<endl;
    cout << "Tunai         : Rp ";
    cin>>tunai;
    cout << "Kembalian     : Rp "<<(tunai-bayar)<<endl;
}
int main()
{
	nama_toko();
	input_barang();
	kepala_tabel();
	output();
}
