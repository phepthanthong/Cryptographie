#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc,char** argv) {
  
  ifstream file;
  string cle;
  if(argc<3) {
    cout<<"Usage: "<<argv[0]<<" <fichier> <cle (un caractere en minuscule)> "<<endl;
    return -1;
  }
  
  //Nhan biet argument
  file.open(argv[1],ios::in);
  if(file.bad()) {
    cout << "Impossible d'ouvrir le fichier!!! "<<argv[1]<<endl;
    return -1;
  }
  cle=argv[2];
  int chenhlech=cle[0]-'a';

  int entree;
  cout << "Entrer 1 pour chiffrer ou 2 pour dechiffrer" << endl;
  cin >> entree;
  switch (entree){
  case 1:
    { 
      ofstream sauvegarde("cesar_chiffre.txt");     
      
      //Doc tung ky tu trong file
      while(true) {
	char kytu;
	int codekytu;
	char kytumahoa;
	int codeKytumahoa;
	
	//Doc 1 ky tu
	file >> kytu;
	
	//dieu kien thoat vong lap
	if(file.eof()) {
	  break;
	}
	
	//Chuyen doi ky tu sang so nguyen trong khoang 0 va 25
	//voi 'a'=0 ... z='25'
	codekytu=kytu-'a';
	
	//Tinh cai cle
	codeKytumahoa=(codekytu+chenhlech)%26;	
	
	//Chuyen lai code da ma hoa thanh ky tu 
	kytumahoa=codeKytumahoa + 'a';    
	
	cout << kytumahoa;
	sauvegarde << kytumahoa;
      }
      sauvegarde.close();      
    }
    break;  
  case 2:
    {
      ofstream sauvegarde("cesar_dechiffre.txt");      
     
      while(true) {
	char kytu;
	int codekytu;
	char kytumahoa;
	int codeKytumahoa;       

	file >> kytu;	

	if(file.eof()) {
	  break;
	}
	
	codekytu=kytu-'a';

	codeKytumahoa=(codekytu-chenhlech)%26;       

	kytumahoa=codeKytumahoa + 'a';    
	
	cout << kytumahoa;
	sauvegarde << kytumahoa;          
      }
      sauvegarde.close();      
    }
    break;       
  }
}
