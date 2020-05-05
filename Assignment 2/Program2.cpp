#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
using namespace std;


float RAN_LFSR(int& LFSR_number){
  int  bit_24 = (LFSR_number & 0b100000000000000000000000)>> 23; //extract the 24th bit
  int  bit_23 = (LFSR_number & 0b010000000000000000000000)>> 22; //extract the 23rd bit
  int  bit_22 = (LFSR_number & 0b001000000000000000000000)>> 21; //extract the 22nd bit
  int  bit_17 = (LFSR_number & 0b000000010000000000000000)>> 16; //extract the 17th bit

  int new_bit = bit_24 ^ bit_23 ^ bit_22 ^ bit_17; // XORed the bits to create new bit

  int new_LFSR = (LFSR_number << 1) & 0x0FFFFFF; // shift 1 bit left and omit the 25th bit
  new_LFSR = new_LFSR | new_bit; // tack on the new bit
  LFSR_number = new_LFSR; // pass by reference to modify the original LFSR
  int total = (int) pow(2,24);
  cout << setprecision(15);
  float random = static_cast<float>(new_LFSR) / static_cast<float>(total);
  return random;
}

float RAN_LCG(int &LCG){
  int a = 0x43FD43FD; // sets a
  int c = 0xC39EC3; // sets c
  int m = (int)pow(2,24); //sets m
  long long new_LCG = ((long long)a * (long long)LCG + (long long)c) % (long long) m; // random number calculation
  LCG = new_LCG; // sets the new seed for the next
  cout << setprecision(15);
  float random = (float)new_LCG/(float)m; // calculates the random number
  return random;
}

float RAN_RAN(){
    int number = (int)rand() % (int)pow(2,24); // a number between 0 and 2^24
    float random = (float)number / (float) pow(2,24); // divide by 2^24
    return random;
}

int main(){
  int LFSR = 0xFFFFFF; // intialize LFSR and LCG
  int LCG = 0xFFFFFF;
  srand(0xFFFFFF);//sets the seed for rand()
  int N;
  float LFSR_mean = 0;
  float LCG_mean = 0;
  float RAN_mean = 0;
  float LFSR_variance = 0;
  float LCG_variance = 0;
  float RAN_variance = 0; //intialize 0 to mean and variance
  cout << "Insert how many iterations: ";
  cin >> N; // how many calculations
  float LFSR_array[N];
  float LCG_array[N];
  float RAN_array[N]; // stores values into arrays
  for(int x = 0; x < N; x++){
    float random_LFSR = RAN_LFSR(LFSR);
    float random_LCG = RAN_LCG(LCG);
    float random_random = RAN_RAN(); // calculate the random values
    LFSR_array[x] = random_LFSR;
    LCG_array[x] = random_LCG;
    RAN_array[x] = random_random; // stores random values
    LFSR_mean += random_LFSR;
    LCG_mean += random_LCG;
    RAN_mean += random_random; //add random values to mean
    cout <<x+1<<": "<< "LFSR: "<< random_LFSR <<" LCG: "<<random_LCG << " Random Number: "<< random_random << endl;
  }
  LFSR_mean = LFSR_mean/N;
  LCG_mean = LCG_mean/N;
  RAN_mean = RAN_mean/N; //divide by total N to get mean
  cout << "LFSR Mean: " << LFSR_mean << endl << "LCG Mean: " << LCG_mean << endl << "RAN Mean: " << RAN_mean << endl;
  for(int x = 0; x < N; x++){
    LFSR_variance += (LFSR_array[x]-LFSR_mean) * (LFSR_array[x]-LFSR_mean);
    LCG_variance += (LCG_array[x]-LCG_mean) * (LCG_array[x]-LCG_mean);
    RAN_variance += (RAN_array[x]-RAN_mean) * (RAN_array[x]-RAN_mean); // calculate variance
  }
  LFSR_variance /= N;
  LCG_variance /= N;
  RAN_variance /= N; // divide by N to get population variance
  cout << "LFSR Variance: " << LFSR_variance << endl << "LCG Variance: " << LCG_variance << endl << "RAN Variance: " << RAN_variance << endl;

}
