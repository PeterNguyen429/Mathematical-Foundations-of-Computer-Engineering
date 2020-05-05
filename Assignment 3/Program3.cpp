#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

int number13 = 0;
int number14 = 0;
int number15 = 0;
int number16 = 0;
int number17 = 0;
int number18 = 0;


int rollFairDie(){
  int die = (int)(rand()%6 + 1); //returns a number 1-6
  return die;
}
int rollUnfairDie(){
  int die = (int)(rand()%100 +1);
  if (die <= 5){
    return 1;
  }
  else if (die > 5 && die <= 20){
    return 2;
  }
  else if (die > 20 && die <= 50){
    return 3;
  }
  else if (die > 50 && die <= 80){
    return 4;
  }
  else if (die > 80 && die <= 95){
    return 5;
  }
  else if (die > 95 && die <= 100){
    return 6;
  }
  else{
    return 0;
  }
}
int Game(){
  int total = 0;
  int numberDieRolls = 0;
  int diceRoll;

    while(total <= 12){
      int diceRoll = rollFairDie(); // change depend on fair trials or unfair, if statement messes it up
      numberDieRolls += 1;
      cout << diceRoll << "-";
      total += diceRoll; // adding die rolls

    }
  switch (total) {
    case 13: number13 += numberDieRolls;
      break;
    case 14: number14 += numberDieRolls;
      break;
    case 15: number15 += numberDieRolls;
      break;
    case 16: number16 += numberDieRolls;
      break;
    case 17: number17 += numberDieRolls;
      break;
    case 18: number18 += numberDieRolls;
      break;
    default:
      break;
  }
  return total;
}


int main(){
  srand(2);
  int N;
  int total;
  int count13 = 0;
  int count14 = 0;
  int count15 = 0;
  int count16 = 0;
  int count17 = 0;
  int count18 = 0;
  cout << setprecision(3);
  cout << "Insert how many trials for die: ";
  cin >> N;
  cout << endl;
  // cout << "What type of die? 1 for fair or 0 for unfair: ";
  // cin >> Y;
  // cout << endl;
  for(int i = 0; i < N; i++){
    cout << i+1 <<": ";
    total = Game();
    cout << total << endl;
      switch (total) {
        case 13: count13 += 1;
          break;
        case 14: count14 += 1;
          break;
        case 15: count15 += 1;
          break;
        case 16: count16 += 1;
          break;
        case 17: count17 += 1;
          break;
        case 18: count18 += 1;
          break;
        default:
          break;
      }
  }
  cout << "13: " << "count: " << count13 << " probability: "<< (float)count13/N << " average # of rolls: " << (float)number13/count13 << endl;
  cout << "14: " << "count: " << count14 << " probability: "<< (float)count14/N << " average # of rolls: " << (float)number14/count14 << endl;
  cout << "15: " << "count: " << count15 << " probability: "<< (float)count15/N << " average # of rolls: " << (float)number15/count15 << endl;
  cout << "16: " << "count: " << count16 << " probability: "<< (float)count16/N << " average # of rolls: " << (float)number16/count16 << endl;
  cout << "17: " << "count: " << count17 << " probability: "<< (float)count17/N << " average # of rolls: " << (float)number17/count17 << endl;
  cout << "18: " << "count: " << count18 << " probability: "<< (float)count18/N << " average # of rolls: " << (float)number18/count18 << endl;



  return 0;
}
