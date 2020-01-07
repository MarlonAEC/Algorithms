#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define MAX_DIGITS 1001
using namespace std;

/**
Author: Marlon A. Espinosa Castañeiras
https://www.linkedin.com/in/marlonaec/

Class for work whit big numbers and perform the basic operations
Keywords: Bigint, c/c++, class bigint,

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
        void operator=(const Bignum&);
        Bignum operator +(const Bignum&)const;
        Bignum operator -(const Bignum&)const;
        Bignum operator-()const;
        Bignum operator *(const Bignum&)const;
        bool operator<(const Bignum&)const;
        bool operator>(const Bignum&)const;
        bool operator<=(const Bignum&)const;
        bool operator>=(const Bignum&)const;
        bool operator==(const Bignum&)const;
        bool operator!=(const Bignum&)const;

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
    int stop;//variable for do not read the sign
    if(!isdigit(s[0])){//reading the sign
        this->set_sign(false);
        stop = 0;
    }
    else{
        this->set_sign(true);
        stop = -1;
    }
    for(int i = s.size()-1;i > stop;i--)//saving the number reverted for eazy operations.
        number.push_back(s[i]-'0');
}

Bignum Bignum::operator-()const{
    Bignum sol = *this;
    sol.set_sign(!this->get_sign());
    return sol;
}
void Bignum::operator=(const Bignum &b){
    sign = b.get_sign();
    number = b.get_number();
}

/**Operator  '<' for compare two Bignums **/
bool Bignum::operator<(const Bignum &b)const{
    if(this->get_sign() != b.get_sign()){//have diferents signs
        if(this->get_sign() && !b.get_sign())
            return false;
        return true;
    }
    else if(this->get_sign()){//both are positve
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
    else{//both are negative
        if(number.size() > b.get_number().size())//comparing the amount of digits
            return true;
        if(number.size() < b.get_number().size())//comparing the amount of digits
            return false;
        for(int i = 0;i < number.size();i++){//if both numbers have the same amount of digits then compare the digist one by one
            if(number[i] == b.get_number()[i])//if are equal just ignore it
                continue;
            else if( number[i] > b.get_number()[i])//if not then return the answer
                return true;
            return false;
        }
    }
}

/**Operator '>' for compare two Bignums**/
bool Bignum::operator==(const Bignum &b)const{
    return !(*this < b) && !(b < *this);
}
bool Bignum::operator>(const Bignum &b)const{
    return b < *this;
}

bool Bignum::operator<=(const Bignum &b)const{
    return !(b < *this);
}

bool Bignum::operator>=(const Bignum &b)const{
    return !(*this < b);
}

bool Bignum::operator!=(const Bignum &b)const{
    return *this < b || b < *this;
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
Bignum Bignum::operator-(const Bignum &b)const{
    Bignum sol;
    int carry = 0; //carry for operations that exceed
    int value; //auxiliary variable for get the value of the digit on the current operation
    int min_size = min(number.size(),b.get_number().size());

    if(this->get_sign() == b.get_sign()){
        if(*this >= b){// comparing to subtract the major from the minor
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
            //Cleaning the leding ceros
            int i = sol.number.size()-1;
            while(i > 0 && sol.number[i] == 0){
                sol.number.pop_back();
                i--;
            }
            return sol;
        }
        return -(b - *this);
    }
    return *this + (-b);


}

Bignum Bignum::operator +(const Bignum &b)const{
/**Bignum for save the result of the sum**/
      Bignum sol;

      int carry = 0; //carry for the sum
      int partial_sums; //partial sum of two digits
      int min_size = min(number.size(),b.get_number().size()); //minumum size of the both bignums

      if(this->get_sign() == b.get_sign()){
          sol.set_sign(this->get_sign());

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
     else
         return *this - (-b);
}

/**Operator '<<' overloaded for print bignum**/
ostream& operator <<(ostream &o, const Bignum &A){
    if(!A.get_sign() && A.get_number()[A.get_number().size() - 1] != 0)//Addin '-' sign to negatives numbers and removing it from '0'
        cout<<"-";
    for(int i =  A.get_number().size() - 1;i > -1;i--)
        o<<A.number[i];
    o<<endl;

    return o;
}

/**Operator '>>' overloaded for read bignum**/
istream& operator >>(istream &i, Bignum &A){
    string s;
    cout<<"Insert Bignum:\n";
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
    cout<<"The lesser is: ";
    if(A < B)
        cout<< A <<endl;
    else
        cout<<B<<endl;

    cout<<"The greater is: ";
    if(A > B)
        cout<< A<<endl;
    else
        cout<< B<<endl;
    return 0;
}
