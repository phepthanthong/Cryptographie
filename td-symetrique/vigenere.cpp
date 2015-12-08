#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc,char** argv) {
  
  ifstream fichier;
  string cle;

  if(argc<3) {
    cout<<"Usage: "<<argv[0]<<" <fichier> <cle (chaine de caracteres minuscules)>"<<endl;
    return -1;
  }

  //R�cup�re les arguments
  fichier.open(argv[1],ios::in);
  if(fichier.bad()) {
    cout << "Impossible d'ouvrir "<<argv[1]<<endl;
    return -1;

  }
  cle=argv[2];
  int taille_cle=cle.size();
  
  //Position dans le fichier
  int position=0;
  //Lit le fichier caract�re par caract�re
  while(true) {
    char lettreLue;
    int codeLettreLue;
    char lettreChiffree;
    int codeLettreChiffree;

    //Lit un caractere du fichier
    fichier >> lettreLue;

    //Fin de fichier ?
    if(fichier.eof()) {
      break;
    }

	//Selectionne le caract�re de la cl� � utiliser
	//en fonction de la position dans le fichier
	char charCle=cle[position%taille_cle];
	//Convertir le caractere en d�calage (a=0 ... z=25)
	int decalage=charCle-'a';


    //Convertir le caractere lu depuis le fichier en entier compris entre 0 et 25
    //avec 'a'=0 ... z='25'
    codeLettreLue=lettreLue-'a';
	//Ajoute le d�calage 
    codeLettreChiffree=(codeLettreLue+decalage)%26;
	//Reconvertit le code du chiffr� vers un 
	//caract�re (en ajoutant le code ascii de 'a' qui vaut 97)
    lettreChiffree=codeLettreChiffree+'a';
    
    cout << lettreChiffree;
    position++;
    cout << endl;
  }

  return 0;
}
