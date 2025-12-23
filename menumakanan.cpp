#include<iostream>
#include<string>
#include<iomanip>
 using namespace std;
//kamus global
    //kamus ADT dan strukture
    struct MENU{ string kode; 
                 string nama; 
                 int harga;
                };

    MENU menu[10];
    int tampilmenu=0;
    //kamsu memanggil fungsi dan prosedur 
    void inputmenu();

//deskrip utama
int main()
{
inputmenu();



return 0;}

//fungsi 



//prosedur
void inputmenu()
{ //kamus 


  //deskrip 

 if(tampilmenu >=10)
    {
        cout <<"Menu sudah penuh \n";
        return ;
    }

    cout <<"Masukan nama kode  " ;
    
    cin >> menu[tampilmenu].kode;

    cout <<"Masukan nama makanan" ;
    cin.ignore();
    getline(cin, menu[tampilmenu].nama);

    cout <<"Masukan harga " ;
    cin  >>menu[tampilmenu].harga;
    tampilmenu=tampilmenu +1;


}





