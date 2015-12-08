#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
  bool message[6] = {0,0,0,1,1,1};
  bool gauche[3];
  bool droite[3];
  bool temp;
  bool cle[6] = {1,1,0,1,1,0};
  int lap = 2;
  
  cout << "Texte initial:" << endl;
  for (int i = 0; i<6; i++)
    cout << message[i];
  /* Ma hoa */
  for (int i = 0; i<lap; i++){
    for (int k = 0; k<3; k++){
      gauche[k]=message[k];
    }
    for (int k = 0; k<3; k++){
      droite[k] = message[k+3];
    }
    // Thuc hien phep XOR giua 2 phia trai va phai
    for (int k = 0; k<3; k++){
      temp = cle[k]^droite[k];
      //cout << temp;
      gauche[k] = gauche[k]^temp;
    }
    for (int k = 0; k<3; k++){
      message[k+3] = gauche[k];
    }
    for (int k = 0; k<3; k++){
      message[k] = droite[k];
    }
  }
  cout << endl;
  cout << "Text chiffre :" << endl;
  for (int i = 0; i<6; i++)
    cout << message[i];
  cout << endl;

  /* Pha ma */
  for (int i = 0; i<lap; i++){
    for (int k = 0; k<3; k++){
      droite[k] = message[k];
    }
    for (int k = 0; k<3; k++){
      gauche[k] = message[k+3];
    }

    for (int k = 0; k<3; k++){
      temp = cle[k]^droite[k];
      gauche[k] = gauche[k]^temp;
    }
    for (int k = 0; k<3; k++){
      message[k+3] = droite[k];
    }
    for (int k = 0; k<3; k++){
      message[k] = gauche[k];
    }
  }
  
  cout << "Text dechiffre: " << endl;
  for (int i = 0; i<6; i++)
    cout << message[i];
  cout << endl;
    
}
