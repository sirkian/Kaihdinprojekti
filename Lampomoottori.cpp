#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <chrono>
#include <unistd.h>

void avaa(){
cout << "Death to monarchs!";
cout << "\n";
}

void sulje(){
cout << "Death to republicans!";
cout << "\n";
/*
for(int i = 0;i<181;i++){
    cout << "Death to republicans!";
    cout << "\n";
 }
 */
}

int main() {

  int lampotila;
  bool totta = true;
  do{
  cout << "Anna lampotila ";
  cin >> lampotila;

 if(lampotila <= 16){
    avaa();
    cout << "\n";
    usleep(3000000);

 } else if(lampotila >= 28){
    sulje();
    cout << "\n";
    usleep(3000000);

 } else {
  cout << "Anarchy, run for your lives!";
  cout << "\n";
  cout << lampotila;
  cout << "\n";
  usleep(3000000);
 }
} while(totta == true);
  return 0;
}
