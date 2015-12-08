#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc,char** argv) {
  
  ifstream file;
  string cle;

  if(argc<3) {
    cout<<"Usage: "<<argv[0]<<" <fichier> <cle (chaine de caracteres minuscules)>"<<endl;
    return -1;
  }
  //Nhan biet argument
  file.open(argv[1],ios::in);
  if(file.bad()) {
    cout << "Impossible d'ouvrir le fichier!!! "<<argv[1]<<endl;
    return -1;
  }  
  cle=argv[2];
  int dodaiCle=cle.size();  
  
  int vitri=0;
  int entree;
  cout << "Entrer 1 pour chiffrer ou 2 pour dechiffrer" << endl;
  cin >> entree;
  switch (entree){
  case 1:{
    ofstream sauvegarde("vig_chiffre.txt");
    while(true) {
      char kytu;
      int codekytu;
      char kytumahoa;
      int codeKytumahoa;    
      
      file >> kytu;
      
      if(file.eof()) {
	break;
      }
      //Chon lua ky tu cua cle de su dung theo vi tri trong file
      char charCle=cle[vitri%dodaiCle];    
      int chenhlech=charCle-'a';   
    
      codekytu=kytu-'a';
      
      codeKytumahoa=(codekytu+chenhlech)%26;
      
      kytumahoa=codeKytumahoa+'a';
      
      cout << kytumahoa;
      vitri++;
      //cout << endl;
      sauvegarde << kytumahoa;
    }
    sauvegarde.close();
  }
    break;
  case 2: {
    ofstream sauvegarde("vig_dechiffre.txt");
    while(true) {
      char kytu;
      int codekytu;
      char kytumahoa;
      int codeKytumahoa;    
      
      file >> kytu;
      
      if(file.eof()) {
	break;
      }
      //Chon lua ky tu cua cle de su dung theo vi tri trong file
      char charCle=cle[vitri%dodaiCle];    
      int chenhlech=charCle-'a';   
      
      codekytu=kytu-'a';
      
      codeKytumahoa=(codekytu-chenhlech)%26;
      
      kytumahoa=codeKytumahoa+'a';
      
      cout << kytumahoa;
      vitri++;
      //cout << endl;
      sauvegarde << kytumahoa;
    }
    sauvegarde.close();
  }
    break;
  }
}

