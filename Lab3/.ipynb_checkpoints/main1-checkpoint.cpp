#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
      int gDenom(int, int) const;
};

// Implement Rational class member functions here
Rational::Rational() {
    numerator = 0;
    denominator = 1;
}
Rational::Rational(int numer){
    numerator = numer;
    denominator = 1; 
}
Rational::Rational(int num, int denom){
    numerator = num;
    denominator = denom; 
}
int Rational::gcd(int denom1, int denom2) const{
    int bDenom;
    int lDenom;
    int gDenom;
    if(denom1 > denom2){
        bDenom = denom1;
        lDenom = denom2; 
    }else {
        bDenom = denom2;
        lDenom = denom1; 
    }
    
    for (int i = bDenom; i >= 1; i--){
        cout << i;
        if (bDenom%i == 0 && lDenom%i == 0){
            gDenom = i; 
            break; 
        }
    }
    return gDenom; 
}
int Rational::gDenom(int denom1, int denom2) const{
    if(denom1 > denom2)
        return denom1;
    else 
        return denom2;
    
}

void Rational::display() const{
    cout << numerator << " / " << denominator;
}
void Rational::simplify() {
    int num = gcd(numerator, denominator);
    numerator = numerator/num;
    denominator = denominator/num;
    
        
}
const Rational Rational::add(const Rational& value) const{
     int denom = value.denominator;
     int numer = value.numerator;
     int newNum;
     int newDenom; 
     int multiplier;
     int gcd = this->gcd(denom, denominator);
     if(gcd == 1){
        newDenom = denom*denominator;
        newNum = (numer * denominator + numerator * denom);
     }
     else {
         if(denom == gDenom(denom, denominator)){
             multiplier = denom/gcd;
             newNum = (numerator * multiplier) + numer;
             newDenom = denom;
         }
         else {
             multiplier = denominator/gcd;
             newNum = (numer * multiplier) + numerator; 
             newDenom = denominator; 
         } 
     }
    return Rational(newNum, newDenom);
    
}
const Rational Rational::subtract(const Rational& value) const{
     int denom = value.denominator;
     int numer = value.numerator;
     int newNum;
     int newDenom; 
     int multiplier;
     int gcd = this->gcd(denom, denominator);
     if(gcd == 1){
        newDenom = denom*denominator;
        newNum = (numerator * denom - numer * denominator);
     }
     else {
         if(denom == gDenom(denom, denominator)){
             multiplier = denom/gcd;
             newNum = (numerator * multiplier) - numer;
             newDenom = denom;
         }
         else {
             multiplier = denominator/gcd;
             newNum = numerator - (numer * multiplier); 
             newDenom = denominator; 
         } 
     }
    return Rational(newNum, newDenom);
}
const Rational Rational::multiply(const Rational& value) const{
    int denom = value.denominator;
    int numer = value.numerator;
    int newNum;
    int newDenom;
    newNum = numer * numerator;
    newDenom = denom * denominator; 
    return Rational(newNum,newDenom);
}
const Rational Rational::divide(const Rational& value) const{
    int denom = value.denominator;
    int numer = value.numerator;
    int newNum;
    int newDenom;
    newNum = numerator * denom;
    newDenom = denominator * numer; 
    return Rational(newNum, newDenom);
}


// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

