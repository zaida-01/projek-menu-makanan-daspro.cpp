#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//======================================  kamus global  ============================
    //kamus biasa
    const int MAX       =20;  // jumlah maksimal  menu
    const int MAX_isi   =10;  // jumlah maksimal menu dalam paket 
    const int MAX_paket =10;  // jumlah maksimal paket di buat

    //kamus ADT dan strukture
    struct MENU{ string kode; 
                 string nama; 
                 int harga  ;
                };
        MENU menu[MAX]  ;
        int tampilmenu=0;
    
    struct PAKET{ string kodepaket ; // kode paketnya
                  string namapaket ; // nama paket
                  int isi[MAX_isi] ; // menu paket yang bisa masuk
                  int jumlahpaket  ; // jumlah paket yang terdaftar
                  int hargapaket   ; // harga untuk tiap paket
                  int diskon       ; // diskon
                };
    PAKET paket[MAX_paket]  ;
    int tampilpaket=0       ;

    //kamus memanggil fungsi dan prosedur 
    int inputmenu(MENU M[], int n);
    int hapusmenu(MENU M[], int n);
    int kasir(MENU M[], int n);
    int inputpaket( PAKET P[]);
    int carikode(MENU M[],int n, string kode);
    int hapuspaket(PAKET M[], int n);
    int kasirpaket(PAKET M[], int n);
    int carikodepaket(PAKET M[],int n, string kode);
    void editmenu(MENU M[], int n);
    void TampilMenu();
    

    //kamus yang nampung fungsi 
    int daftarinput,hapusinput,totalkasir;
    int hapusmenupaket;



//=======================================deskrip utama
int main()
{ 
 //kamus lokal

    int in,pilihan;
 //deskripsi


    do
    {
        cout <<"\n=====DAFTAR MENU=====\n";
            TampilMenu();    

     //MENAMPILKAN MENU OPTION 
        cout<<"\n======MENU======\n";   
        cout<<"1. input menu baru \n";
        cout<<"2. edit daftar menu\n";
        cout<<"3. hapus menu\n";
        cout<<"4. kasir\n";
        cout<<"5. input paket\n";
        cout<<"6. Hapus paket\n";
        cout<<"7. kasir paket\n";
        cout<<"0. keluar\n";
        cout <<"Pilihan :";
            cin >>pilihan; 

            if(pilihan == 1) //input menu
            {
                in=0;
                do
                {
                    cout <<"Mau berapa menu baru yang masuk (1~10)\n" ;
                        cin >> in;

                }while(in <1 || in >10); //jumlah menu yang mau masuk 

                daftarinput=inputmenu(menu, in);
                cout << daftarinput;

            }
            else if(pilihan == 2) //edit menu 
            {
                editmenu(menu, tampilmenu);
            }
            else if(pilihan == 3)// hapus menu
            {
                hapusinput=hapusmenu(menu,tampilmenu);
                    cout <<hapusinput;
            }
            else if(pilihan == 4) //kasir hitung harga
            { 
                kasir(menu, tampilmenu);   
            }
            else if(pilihan == 5) //buat paket dengan isi menu
            {
                inputpaket(paket);
            }
            else if(pilihan == 6) //hapsu paket
            {
                hapusmenupaket=hapuspaket(paket,tampilpaket);
                cout<<hapusmenupaket;
            }
            else if(pilihan == 7)
            {
                kasirpaket(paket, tampilpaket);

            }
    }while(pilihan != 0); //mengakhiri program pilihan

    cout <<"\n\nPROGRAM TELAH SELESAI DI PAKAI\n\n" ;
    return 0;
}











//=========================================prosedur=================================================
void editmenu(MENU M[], int n) //mengedit salah satu daftar menu dengan memasuan kode makanan
    {
      //kamus lokal
        string cari; 
        bool ketemu;

      //deskripsi
        if(n == 0){ cout <<"\n\n\n\n\nDAFTAR MENU MASIH KOSONG\n\n\n\n\n";
                    return;
                  }

        cout <<"Masukan data yang mau di edit (kode) :";
            cin  >> cari;

        ketemu=false; // program belum menemukan yang mau di edit 

            int i=0;
            do
            {
                if(M[i].kode == cari)
                {
                 cout <<"Nama :"<<M[i].nama <<"\n" <<"Harga :" <<M[i].harga <<"\n";

                        cout <<"\nSilakan masukan Nama baru :";
                        cin.ignore();
                            getline(cin, M[i].nama);      //edit nama

                        cout <<"\nSilakan Masukan harga baru :" ; // edit harga harga
                            cin  >>M[i].harga;

                 ketemu = true; // program berhasil 
                 break; // menghentikan loop setelah mendapat hasil atau if berjalan 
                }
             i=i+1;
            }while(i < n);

            if(!ketemu){cout << "\ndata yang anda cari tidak ada\n";}
    }


void TampilMenu()
    {
     //kamus lokal
     //deskrip
            if(tampilmenu == 0)
                {
                    cout <<"\n\n\n\n\nDAFTAR MENU MASIH KOSONG\n\n\n\n\n";
                }  //cek bats menu masih kosong atau tidak

            else if(tampilmenu >= 1)
                    {
                     cout << "\n===== DAFTAR MENU =====\n";
                     cout <<left  <<setw(7)  <<"KODE"
                          <<left  <<setw(40) <<"MAKANAN"
                          <<left  <<setw(13) <<"HARGA";
                     cout <<"\n"<< string(55, '-') << "\n";

                        int s=0;
                        do
                        {
                            cout <<left <<setw(7)  <<menu[s].kode
                                <<left  <<setw(40) <<menu[s].nama
                                <<left  <<setw(3)  <<"Rp"
                                <<left  <<setw(10) <<menu[s].harga<<"\n"; 
                         s=s+1;
                        }while(s < tampilmenu);
                    }
                    
                if(tampilpaket > 0 )
                    {
                        cout << "\n===== DAFTAR PAKET =====\n";

                            int g=0;
                            do
                            {
                                cout <<left <<setw(7)  << paket[g].kodepaket 
                                     <<left <<setw(20) <<paket[g].namapaket ;
                                
                                cout << "\n Harga paket :"
                                     <<left  <<setw(3)  <<"Rp"
                                     <<left  <<setw(10) <<paket[g].hargapaket ;

                                    cout <<"\n Isi paket :\n";
                                    int f=0;
                                    do
                                    {
                                        int dex = paket[g].isi[f];

                                     cout <<left  <<setw(40) <<menu[dex].nama
                                          <<left  <<setw(3)  <<"Rp"
                                          <<left  <<setw(10) <<menu[dex].harga<<"\n"; 

                                    f=f+1;
                                    }while(f < paket[g].jumlahpaket); //total isi paket

                                    cout <<"Diskon :"<< paket[g].diskon <<"%";

                                g=g+1;    
                            }while(g < tampilpaket); // total paket

                        cout <<"\n"<< string(55, '-') << "\n";
                    }
    }



//===================================fungsi================================================= 

int inputmenu(MENU M[], int n)  // input menu baru
    { 
      //kamus lokal
        int batas = MAX - tampilmenu; 

      //deskrip
        if(batas <=0 || n > batas)                   // cek batas menu 
          {cout <<"Menu sudah penuh \n"; return 0 ;}

            int G=0;
            do
            {
                cout <<"Masukan Menu baru ke-"<<tampilmenu + 1<<"\n";

                cout <<"Masukan kode makanan :" ; // masukan kode 
                    cin >> M[tampilmenu].kode;
                cout <<"Masukan nama makanan :" ; // masukan nama makanan 
                    cin.ignore();
                    getline(cin, M[tampilmenu].nama);

                cout <<"Masukan harga :" ; // masukan harga
                    cin  >>M[tampilmenu].harga;
                cout<<"\n";
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

        int f=0;
      
                int i=0;
                do
                {
                    if(M[i].kode == cari)
                        {
                        hapus = i; //menghapus kode,nama,harga
                        break;
                        }
                i=i+1;
                }while(i < n);

            if(hapus == -1)
                { 
                    cout <<"\nData tidak di temukan\n"; return n; 
                } //jika data yang di cari tidak di temukan 

            int J=hapus;
                do
                {
                    M[J]=M[J+1];  // menggeser data array ke sebelahnya 
                
                J=J+1;    
                }while(J < n-1);

            n=n-1; // jumlah array berkurang 
            tampilmenu=n;
        
        return n;
    }

int carikode(MENU M[],int n, string kode)
    {
        int p=0;
        do
        {
            if(M[p].kode == kode)
            {
            return p;
            }

            p=p+1;    
        }while(p < n);

     return -1;
    }

int carikodepaket(PAKET M[],int n, string kode)
    {
        int p=0;
        do
        {
            if(M[p].kodepaket == kode)
            {
            return p;
            }

            p=p+1;    
        }while(p < n);

     return -1;
    }

int kasir(MENU M[], int n)
    {
      //kamus
        string kode;
        int nominal,total=0;

      //deskripsi
            int k=0;
            do
            {
                cout <<"\nMasukan kode : (0 untuk akhiri pesanan)";
                    cin >> kode;

                if(kode =="0")
                {break;}

                nominal=carikode(M,n,kode);

                if(nominal != -1)
                    {   
                        total += M[nominal].harga;

                        cout <<"\n+ "<<M[nominal].nama
                             <<": Rp "<<M[nominal].harga;
                    }
                else
                    {
                    cout <<"kode tidak ditemukan, pesan diabaikan";
                    }

            }while(true);

        cout << "\n========================\n";
        cout <<"Total pesanan : Rp."<<total;
        return total;
    }

int inputpaket( PAKET P[])
    {  
      //kamus lokal 
        string kode;

      //deskripsi
        if(tampilmenu == 0) {
                            cout <<"\n\n\n\n\nDAFTAR MENU MASIH KOSONG\n\n\n\n\n";
                            return -1;
                            }  //cek bats menu masih kosong atau tidak
                            
        if(tampilpaket >= MAX_paket){
                                    cout <<" \n\n DAFTAR PAKET SUDAH PENUH \n\n";
                                    return -1; //langsung berhenti dan menampilkan ini
                                    } //cek apakah paket sudah penuh


      //penginputan kode dan nama paket
        cout <<"Masukan kode paket :" ;
            cin >>paket[tampilpaket].kodepaket;

        cin.ignore();
        cout <<"\nMasukan Nama paket :" ;
            getline(cin,paket[tampilpaket].namapaket);

        cout << "\n========== Menu ===========\n";
            TampilMenu();  // tampil menu
        
        cout <<"\n==============================\n";

      //penginputan paket
        int w=0;
        int total=0;
        int potongan ; 
        do
        {   
            if(tampilmenu == 0)
                    {
                        cout << "Paket harus berisi minimal 1 menu!\n";
                        return tampilpaket;
                    }
                    
            cout <<"Masukan kode : (0 untuk akhiri pesanan)";
                cin >> kode;

            if(kode =="0")
            {   
                 do
                 {
                    cout <<"Mau kasih diskon berapa : (0 ~50%)";
                        cin >>P[tampilpaket].diskon;

                            if(P[tampilpaket].diskon < 0 || P[tampilpaket].diskon > 50)
                                {
                                cout <<"diskon terlalu banyak, dimohon untuk di kurangi";  
                                }

                    potongan = total * P[tampilpaket].diskon/100 ;
                    total =total - potongan; 

                 }while(P[tampilpaket].diskon < 0 || P[tampilpaket].diskon > 50);
                
                break;
            }

        int nominal=carikode(menu,tampilmenu,kode) ;  // memakai fungsi kode 
            if(nominal != -1)
                {   
                    if(w < MAX_isi)
                        {
                            P[tampilpaket].isi[w]= nominal;
                            total += menu[nominal].harga;
                            w=w+1;
                        }
                    else 
                        {
                        cout <<"Isi menu paket sudah penuh\n";  
                        }
                }
            else
                {
                    cout <<"kode tidak ditemukan, menu tidak masuk ke paket\n";
                }
                
        }while(true);

        P[tampilpaket].jumlahpaket = w     ; //membuat jumlah kosong kembali
        P[tampilpaket].hargapaket  = total ; //membuat jumha harga kosing kembali
        tampilpaket=tampilpaket+1;

        return tampilpaket;
    }

int hapuspaket(PAKET M[], int n) // menghapus salah satu paket  di array dan memajukan daftar menu bawahnya  
    {
        //kamus lokal
        string cari; 
        int hapus=-1;

        if(n == 0 )
                {
                cout << "Daftar paket masih kosong\n";
                return n; 
                }

        //deskripsi
        cout <<"Masukan data yang mau di hapus (kode) :";  //penginputan apa yang mau di cari
            cin  >> cari;

            int i=0;
            do
            {
                if(M[i].kodepaket == cari)
                    {
                    hapus = i; //menghapus kode,nama,harga
                    break;
                    }
            i=i+1;
            }while(i < n);

        if(hapus == -1)
            { 
                cout <<"\nData tidak di temukan\n"; return n; 
            } //jika data yang di cari tidak di temukan 

            int J=hapus;
            do
            {
                M[J]=M[J+1];  // menggeser data array ke sebelahnya 
            
            J=J+1;    
            }while(J < n-1);

        n=n-1; // jumlah array berkurang 
        tampilpaket=n;
        return n;
    }
int kasirpaket(PAKET M[], int n)
    {
      //kamus
        string kode;
        int nominal,total=0;

      //deskripsi
            int k=0;
            do
            {
                cout <<"\nMasukan kode : (0 untuk akhiri pesanan)";
                    cin >> kode;

                if(kode =="0")
                {break;}

                nominal=carikodepaket(M,n,kode);

                if(nominal != -1)
                    {   
                        total += M[nominal].hargapaket;

                        cout <<"\n+ "<<M[nominal].namapaket
                             <<": Rp "<<M[nominal].hargapaket;
                    }
                else
                    {
                    cout <<"kode tidak ditemukan, pesan diabaikan";
                    }

            }while(true);

cout << "\n========================\n";
cout << "Total pesanan : Rp " << total << endl;

        return total;
    }
