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
    int inputmenu(MENU M[], int n);
    int hapusmenu(MENU M[], int n);
    void editmenu(MENU M[], int n);
    //kamus yang nampung fungsi 
    int daftarinput;




//deskrip utama
int main()
{ //kamus lokal
  int batas = MAX - tampilmenu;
  int in;

    




        
return 0;}











//prosedur
void editmenu(MENU M[], int n)
{
    //kamus lokal
    string cari; 
    bool ketemu;

    //deskripsi
    cout <<"Masukan data yang mau di edit (kode) :";
        cin  >> cari;

    ketemu=false; // program belum menemukan yang mnau di edit 

    int i=0;
    do
    {
        if(M[i].kode == cari)
        {
        cout <<"Nama :"<<M[i].nama <<"\n" <<"Harga :" <<M[i].harga <<"\n";

                cout <<"Silakan masukan Nama baru :";
                cin.ignore();
                getline(cin, M[i].nama);      //edit nama

                cout <<"Silakan Masukan harga baru :" ; // edit harga harga
                    cin  >>M[i].harga;

        ketemu = true; // program berhasil 
        break; // menghentikan loop setelah mendapat hasil atau if berjalan 
        }
    i=i+1;
    }while(i < n);
    if(!ketemu){cout << "\ndata yang anda cari tidak ada\n";}
}






//fungsi 

int inputmenu(MENU M[], int n)  // input menu 
{ //kamus lokal
    int batas = MAX - tampilmenu; 

  //deskrip
    if(batas <=0)  // cek batas menu 
      {cout <<"Menu sudah penuh \n"; return 0 ;}

    int G=0;
    do
    {
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
    }while(G < n ); 
    
    cout << "\n PENAMBAHAN MENU BERHASIL \n";
    return n;
}

int hapusmenu(MENU M[], int n) // menghapus salah satu menu di array 
{
    //kamus lokal
    string cari; 
    int hapus=-1;

    //deskripsi
    cout <<"Masukan data yang mau di hapus (kode) :";
        cin  >> cari;

    int i=0;
    do
    {
        if(M[i].kode == cari)
            {hapus = i; //menghapus kode,nama,harga
            break;}
    i=i+1;
    }while(i < n);

    if(hapus ==-1)
      { cout <<"\nData tidak di temukan\n"; return n; } //jika data yang di cari tidak di temukan 

    do
    {
        M[i]=M[i+1];  // menggeser data array ke sebelahnya 
    i=i+1;    
    }while(i < n-1);

    n=n-1; // jumlah array berkurang 
    return n;
}




// penting  nanti kita pakai di main 
    do{
        cout <<"Mau berapa menu baru yang masuk (1~10)\n" ;
        cin >> in;
        cin.ignore();
        }while(in <1 || in >batas); //jumlah menu yang mau masuk 



