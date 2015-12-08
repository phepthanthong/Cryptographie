#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

long puissance(long a, long e, long n){
  long p;
  for (p = 1; e>0; e = e/2){
    if (e % 2 != 0)
      p = (p*a) % n;
    a = (a*a) % n;
  }
  return p;
}

long bezout(long a, long b){
  // Ce programmme ne fonctionne qu'avec des entiers naturels
  // On sauvegarde les valeurs de a et b
  long a0 = a;
  long b0 = b;
  // Initialisations. On laisse invariant p*a0 + q*b0 = a et r*a0 + s*b0 = b
  long p = 1;
  long q = 0;
  long r = 0; 
  long s = 1;
  long c = 1;
  // La boucle principale
  while (b != 0){
    c = a % b;
    long quotient = a/b;
    a = b;
    b = c;
    long nouveau_r = p - quotient * r;
    long nouveau_s = q - quotient * s;
    p = r;
    q = s;
    r = nouveau_r;
    s = nouveau_s;
  }
  if (p<0) return p+b0;
  else return p;
}

long pgcd(long a, long b){
  long p = 1, q = 0, r = 0, s= 1;
  long quotient = 0, c = 0;
  long r_new = 0, s_new = 0;
  while (b != 0){
    c = a % b;
    quotient = a/b;
    a = b;
    b = c;
    r_new = p - quotient * r;
    s_new = q - quotient * s;
    p = r;
    q = s;
    r = r_new;
    s = s_new;
  }
  return abs(a);
}

bool test_fermat(long x){
  if (puissance(2,x-1,x) != 1) return false;
  else return true;
  if (puissance(3,x-1,x) != 1) return false;
  else return true;
  if (puissance(5,x-1,x) != 1) return false;
  else return true;
  if (puissance(7,x-1,x) != 1) return false;
  else return true;
  if (puissance(11,x-1,x) != 1) return false;
  else return true;
}

long premier(){
  long p = rand()%100+1;
  bool test = false;
  while (!test){
    if (puissance(2,p-1,p) != 1) test = true;
    else {
      cout << p << endl;
      p++;
    }
  }
  return p;
}

int main(){
  //srand(getpid());
  /*long n = 319; // longueur du cle
  long c = puissance(100,11,319);
  cout << "c = m^e mod(n) = " << c << endl;
  long d = bezout(11,280);
  cout <<  "d = " << d << endl;
  //cout << "d = " << d << ", " << "u = " << u << ", " << "v = " << v << endl;
  cout << "Verification: puissance(c,d,n) => m = " << puissance(c,d,n) << endl;*/
  cout << endl;

  long p = premier();
  cout << "p = " << p << endl;
  long n = premier();
  cout << "n = " << n << endl;
}
