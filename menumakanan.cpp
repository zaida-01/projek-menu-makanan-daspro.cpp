#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//======================================kamus global
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
    void TampilMenu();

    //kamus yang nampung fungsi 
    int daftarinput,hapusinput;




//=======================================deskrip utama
int main()
{ //kamus lokal

  int in,pilihan;
  //deskripsi


do{

TampilMenu();    

cout<<"\n======MENU======\n";   //MENAMPILKAN MENU OPTION 
cout<<"1. input menu baru \n";
cout<<"2. edit daftar menu\n";
cout<<"3. hapus menu\n";
cout<<"4. \n";
cout<<"0. keluar\n";
cout <<"Pilihan :";
cin >>pilihan; 

if(pilihan == 1) //input
{
    in=0;
    do{
        cout <<"Mau berapa menu baru yang masuk (1~10)\n" ;
        cin >> in;
        cin.ignore();
        }while(in <1 || in >10); //jumlah menu yang mau masuk 

daftarinput=inputmenu(menu, in);
cout << daftarinput;

}
else if(pilihan == 2)//edit
{
editmenu(menu, tampilmenu);
}
else if(pilihan == 3)// hapus
{
hapusinput=hapusmenu(menu,tampilmenu);
cout <<hapusinput;
}
else if(pilihan == 4)
{}




}while(pilihan != 0);


cout <<"\nPROGRAM TELAH SELESAI DI PAKAI\n" ;       
return 0;}











//=========================================prosedur
void editmenu(MENU M[], int n) //mengedit salah satu daftar menu dengan memasuan kode makanan
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


void TampilMenu(){
//kamus lokal
//deskrip
        if(tampilmenu == 0)
            {
             cout <<"\n\n\n\n\nDAFTAR MENU MASIH KOSONG\n\n\n\n\n";
            }  //cek bats menu masih kosong atau tidak


    int s=0;
    do{
    cout <<"=====DAFTAR MENU=====\n";
    cout <<right <<setw(5)  <<menu[s].kode
         <<left  <<setw(40) <<menu[s].nama
         <<right <<setw(3)  <<"Rp"
         <<left  <<setw(10) <<menu[s].harga; 
    s=s+1;
    }while(s < tampilmenu);

}



//===================================fungsi 

int inputmenu(MENU M[], int n)  // input menu baru
{ //kamus lokal
    int batas = MAX - tampilmenu; 

  //deskrip
    if(batas <=0)                   // cek batas menu 
      {cout <<"Menu sudah penuh \n"; return 0 ;}

        int G=0;
        do
        {
            cout <<"Masukan Menu baru ke-"<<tampilmenu + 1<<"\n";

            cout <<"Masukan kode makanan :" ; // masukan kode 
                cin >> M[tampilmenu].kode;
                cin.ignore();
            cout <<"Masukan nama makanan :" ; // masukan nama makanan 
                getline(cin, M[tampilmenu].nama);

            cout <<"Masukan harga :" ; // masukan harga
                cin  >>M[tampilmenu].harga;

            tampilmenu=tampilmenu +1;  // nominal tampilmenu bertambah
        G=G+1;
        }while(G < n ); 
    
    cout << "\n PENAMBAHAN MENU BERHASIL \n";
    return n;
}

int hapusmenu(MENU M[], int n) // menghapus salah satu menu di array dan memajukan daftar menu bawahnya  
{
    //kamus lokal
    string cari; 
    int hapus=-1;

    //deskripsi
    cout <<"Masukan data yang mau di hapus (kode) :";  //penginputan apa yang mau di cari
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

    int J=0;
    do
    {
        M[J]=M[J+1];  // menggeser data array ke sebelahnya 
    J=J+1;    
    }while(J < n-1);

    n=n-1; // jumlah array berkurang 
    return n;
}









