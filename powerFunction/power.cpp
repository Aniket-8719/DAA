#include <bits/stdc++.h>
using namespace std;

float power(float x, int y){
     float temp;
     if( y == 0)
          return 1;
     temp = power(x, y/2);
     if (y%2 == 0)
          return temp*temp; 
     else{
          if(y > 0)
               return x*temp*temp; 
          else
               return (temp*temp)/x;
     }
}

int main(){
     float x;
     int y;

     cout << "Enter a number: ";
     cin >> x;
     cout << "Enter the power: ";
     cin >> y;

     cout << power(x, y) << endl;
     return 0;
}
