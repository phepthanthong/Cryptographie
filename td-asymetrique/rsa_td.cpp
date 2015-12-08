#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
using namespace std;

bool estPremier(int valeur){
  int iCount;
  iCount=2;
  if(valeur<2)
    return false;
  while(iCount<=(valeur/2))
    {
      if(valeur%iCount==0)	
	return false;      
      iCount++;      
    }  
  return true;
}

int pgcd(int a, int b){
  int reste;
  int A = a, B = b; 
  while(B != 0){
    reste = A % B;
    A = B;
    B = reste;
  }
  return A;
}


int chercherD(int e, int phiN){
  int a1,a2,a3,b1,b2,b3,t1,t2,t3,reste;
  
  a1 = 1;
  a2 = 0;
  a3 = phiN; 
  
  b1 = 0;
  b2 = 1;
  b3 = e;

  while(b3!=1){
    reste = a3 / b3;

    t1 = a1 - reste*b1;
    t2 = a2 - reste*b2;
    t3 = a3 - reste*b3;

    a1 = b1;
    a2 = b2;
    a3 = b3;

    b1 = t1;
    b2 = t2;
    b3 = t3;
  }

  if (b2<0)
    b2 = b2 + phiN;
  return b2;
}

int chercherE(int phiN){
  int e = rand()%phiN+1;
  while (pgcd(e,phiN) != 1) 
    e = rand()%phiN+1;
  return e;
}  
  

void rsaCle(int nbPremier1 , int nbPremier2){
  
  //variable
  int e=0, n, d=0, phiN;
  ifstream file;

  if (estPremier(nbPremier1) && estPremier(nbPremier2)) {
    n = nbPremier1*nbPremier2;
    phiN = (nbPremier1-1)*(nbPremier2-1);
    while(d==e){
      e = chercherE(phiN);
      d = chercherD(e,phiN);
    }    
  }
  ofstream save("cle.txt",ios::app);
  // save << "Cle publique: (e = " << e << ", n = " << n << ")" << endl;
  // save << "Cle privee: (d = " << d << ", n = " << n << ")" << endl;
  save << e << "," << n << endl;
  save << d << "," << n << endl;
}

int getRandom(){
  int val;
  val = rand()%30+1;
  while(!estPremier(val))
    val = rand()%30+1;
  return val;
}

void chiffrer(int message){
  ifstream file;
  file.open("cle.txt",ios::in);
}

int main(){
  // entree
  int p,q,s,t,mess;
  srand(getpid());
  cout << "--- Implementation du RSA ---" << endl;
  cout << "Hello Alice! Voici vos cles: \n";  
  p = getRandom();
  q = getRandom();
  rsaCle(p,q);

  cout << "Hello Bob! Voici vos cles: \n";
  s = getRandom();
  t = getRandom();
  rsaCle(s,t);

  cout << "Alice, entrez un message quelconque: \n";
  cin >> mess;
  
  
  
  // long double randNb = 2;
  // long double chiffre = fmod(pow(randNb,31),91);
  // long double dechiffre = fmod(pow(chiffre,7),91);
  
  // cout << dechiffre << endl;


}
