#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define MAX_DIGITS 1001
using namespace std;

/**
Author: Marlon A. Espinosa Castañeiras
Class for work whit big numbers and perform the basic operations
**/
class Bignum{
    protected:
        bool sign;//sign of the number
        vector<int> number;//de digits of the number
    public:
    /**Contructor**/
        Bignum(){
            sign = true;
            this->number.clear();
        }
        Bignum(const Bignum&);
    /**End of Contructor**/

    /**OPERATORS**/
        Bignum operator +(const Bignum&);
        Bignum operator -(const Bignum&);
        bool operator<(const Bignum &) const;
        bool operator>(const Bignum &) const;

        friend ostream& operator <<(ostream&,const Bignum &);
        friend istream& operator >>(istream&, Bignum &A);
    /**End Of Operators**/

    /**Setters and Getters**/
        vector<int> get_number()const {return number;}
        bool get_sign()const {return sign;}
        void set_number(string s);
        void set_sign(bool a){sign = a;}
    /**End of Setters and Getters**/
};

Bignum::Bignum(const Bignum &A){
    *this = A;
}

/**Funtion for set the readed string into a Bignum*/
void Bignum::set_number(string s){
    for(int i = s.size()-1;i > -1;i--)
        number.push_back(s[i]-'0');
}

/**Operator  '<' for compare two Bignums **/
bool Bignum::operator<(const Bignum &b)const{
    if(number.size() < b.get_number().size())//comparing the amount of digits
        return true;
    if(number.size() > b.get_number().size())//comparing the amount of digits
        return false;
    for(int i = 0;i < number.size();i++){//if both numbers have the same amount of digits then compare the digist one by one
        if(number[i] == b.get_number()[i])//if are equal just ignore it
            continue;
        else if( number[i] < b.get_number()[i])//if not then return the answer
            return true;
        return false;
    }
}

/**Operator '>' for compare two Bignums**/
bool Bignum::operator>(const Bignum &b)const{
    if(number.size() > b.get_number().size())//comparing the amount of digits
        return true;
    if(number.size() < b.get_number().size())//comparing the amount of digits
        return false;
    for(int i = 0;i < number.size();i++){
        if(number[i] == b.get_number()[i])//if are equal just ignore it
            continue;
        else if( number[i] > b.get_number()[i])//if not then return the answer
            return true;
        return false;
    }
}

/**Operator '-' for substract two bignum
E.G:
 45645645
-   56632
---------
 45589013
---------
---------

**/
Bignum Bignum::operator-(const Bignum &b){
    Bignum sol;
    int carry = 0; //carry for operations that exceed
    int value; //auxiliary variable for get the value of the digit on the current operation
    int min_size = min(number.size(),b.get_number().size());

    if(*this > b){// comparing to subtract the major from the minor
        sol.set_sign(true); //if the last condition match then the result is positive because A - B = +C, if A > B
        for(int i = 0;i < number.size();i++){
            if(i >= b.get_number().size())//if the value of i exceed the amount of digits of B, then do de operation whit '0' value
                value = 0;
            else
                value = b.get_number()[i];//in other case is the current digit what we have to substract
            if(number[i] - carry < value){//if this condition match then is because the digit - carry is less than the digit below so we add it 10 and do the substraction and carry = 1 for next operation
                sol.number.push_back( (number[i] - carry + 10 - value) % 10);
                carry = 1;
            }
            else{//if not then we just substract the
                sol.number.push_back( (number[i]- carry - value) % 10 );
                carry = 0;
            }
        }
    }
    else{//if not then substract the second number from the first one following the same rules
        sol.set_sign(false);
        for(int i = 0;i < b.get_number().size();i++){
            if(i >= number.size())
                value = 0;
            else
                value = number[i];
            if(b.get_number()[i] - carry < number[i]){
                sol.number.push_back( (b.get_number()[i] - carry + 10 - value) % 10);
                carry = 1;
            }
            else{
                sol.number.push_back( (b.get_number()[i]- carry - value) % 10 );
                carry = 0;
            }
        }
    }

    //Cleaning the leding ceros
    int i = sol.number.size()-1;
    while(i > 0 && sol.number[i] == 0){
        sol.number.pop_back();
        i--;
    }

    return sol;
}

Bignum Bignum::operator +(const Bignum &b){
/**Bignum for save the result of the sum**/
      Bignum sol;

      int carry = 0; //carry for the sum
      int partial_sums; //partial sum of two digits
      int min_size = min(number.size(),b.get_number().size()); //minumum size of the both bignums

      /**Suming the numbers while they have the same amount of digits
      E.G:
       123456
      +  4566
      _______
       128022
      -------
      -------
      in this case we sum until 3 colum starting at 0, from rigth to left
      **/
      for(int i = 0;i < min_size;i++){
           partial_sums = number[i] + b.get_number()[i] + carry;
           sol.number.push_back(partial_sums % 10);
           if(partial_sums > 9)
                carry = 1;
           else
                carry = 0;
      }

      /**Suming the leding numbers **/
      if(number.size() < b.get_number().size()){
           for(int i = min(number.size(),b.get_number().size());i < b.get_number().size();i++){
                 partial_sums = b.number[i] + carry;
                 sol.number.push_back( partial_sums % 10);
                 if(partial_sums > 9)
                    carry = 1;
                 else
                    carry = 0;
           }
      }
    else{
           for(int i = min(number.size(),b.get_number().size());i < number.size();i++){
              partial_sums = number[i] + carry;
              sol.number.push_back(partial_sums % 10);
              if(partial_sums > 9)
                 carry = 1;
              else
                 carry = 0;
            }
    }
    //If at the end we have carry then we add it to the solution
    if(carry == 1)
        sol.number.push_back(1);

    return sol;
}

/**Operator '<<' overloaded for print bignum**/
ostream& operator <<(ostream &o, const Bignum &A){
    if(!A.get_sign() && A.get_number()[A.get_number().size() - 1] != 0)
        cout<<"-";
    for(int i =  A.get_number().size() - 1;i > -1;i--)
        o<<A.number[i];
    o<<endl;
}

/**Operator '>>' overloaded for read bignum**/
istream& operator >>(istream &i, Bignum &A){
    string s;
    cout<<"Introduzca el Bignum:\n";
    i>>s;
    A.set_number(s);
}


int main()
{

    Bignum A;
    cin>>A;
    Bignum B;
    cin>> B;

    cout<< "The sum is: \n";
    cout<< A+B;
    cout<< "The substraction is: \n";
    cout<< A-B;


    return 0;
}
