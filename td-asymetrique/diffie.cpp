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

long generate_prime(){
  long p = rand()%100+1;
  bool test = false;
  while (!test){
    if (puissance(2,p-1,p) != 1) test = true;
    else {
      cout << p << endl;
      p++;
    }
  }
  do generate_prime();
  while (test_fermat(p) == false);
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

int main(){
  srand(getpid());
  long p, q, g = 0;
  p = generate_prime();
  do g = rand()%(p-1)+1;
  while (pgcd(g,p) != 1);

  // Alice  
  long a = rand()%p; //garder secret
  long ga = puissance(g,a,p); // envoyer a Bob

  // Bob
  long b = rand()%p; //garder secret
  long gb = puissance(g,b,p); // envoyer a Alice

  // Alice calcule
  long gba = puissance(gb,a,p);
  cout << "gba = " << gba << endl;

  // Bob calcule
  long gab = puissance(ga,b,p); 
  cout << "gab = " << gab << endl;
}
