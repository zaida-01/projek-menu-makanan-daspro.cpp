#include<iostream>
#include<string>
#include<iomanip>
 using namespace std;
//kamus global
    //kamus biasa
    const int MAX=10;
    //kamus ADT dan strukture
    struct MENU{ string kode; 
                 string nama; 
                 int harga;
                };

    MENU menu[MAX];
    int tampilmenu=0;
    //kamsu memanggil fungsi dan prosedur 
    int inputmenu(MENU M[],int in);

//deskrip utama
int main()
{ //kamus lokal
  int batas = MAX - tampilmenu;
  int in;
  //kamus yang nampung fungsi 
   int daftarinput;
    




        
return 0;}

//fungsi 



//prosedur





int inputmenu( MENU M[], int in)  // input menu 
{ //kamus lokal
    int batas = MAX - tampilmenu; 

  //deskrip
    if(batas <=0)  // cek batas menu 
    {cout <<"Menu sudah penuh \n"; return 0 ;}

    int G=0;
    do{
        cout <<"Masukan Menu baru ke-"<<tampilmenu + 1<<"\n";

        cout <<"Masukan nama kode  :" ; // masukan kode 
            cin >> M[tampilmenu].kode;
            cin.ignore();
        cout <<"Masukan nama makanan :" ; // masukan nama makanan 
            getline(cin, M[tampilmenu].nama);

        cout <<"Masukan harga :" ; // masukan harga
            cin  >>M[tampilmenu].harga;

        tampilmenu=tampilmenu +1;
        G=G+1;
        }while(G < in ); 
    
    cout << "\n PENAMBAHAN MENU BERHASIL \n";
    return in;
}





