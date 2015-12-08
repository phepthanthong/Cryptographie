#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc,char** argv) {
  
  ifstream fichier;
  int pos = 0;
  int ronde = 2;
  bool message[64]={1,0,0,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0};
  bool gauche[32];
  bool droite[32];
  bool cle[32]={0,1,1,0,1,0,1,1,1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,0,0};
  bool temp;

  cout << "Texte inital: " << endl;
  for (int k = 0; k<64; k++){
    cout << message << endl;
  }

  /* La partie chiffrement */
  for (int i = 0; i<ronde; i++){
    for (int k = 0; k<32; k++){
      gauche[k] = message[k];
    }
    for (int k = 0; k<32; k++){
      droite[k] = message[k+32];
    }
    //on applique le XOR entre la partie gauche et droite
    for (int k = 0; k<32; k++){
      temp = cle[k]^droite[k];
      //temp = (cle[k] && !droite[k]) || (!cle[k] && droite[k])
      cout << temp;
      gauche[k] = gauche[k]^temp;
    }
    for (int k = 0; k<32; k++){
      message[k+32] = gauche[k];
    }
    for (int k = 0; k<32; k++){
      message[k] = droite[k];
    }
  }




}
