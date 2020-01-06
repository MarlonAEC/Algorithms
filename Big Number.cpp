#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define MAX_DIGITS 1001
using namespace std;

class Bignum{
    protected:
        bool sign;
        vector<int> number;
    public:
        Bignum(){
            sign = true;
            this->number.clear();
        }
        Bignum(const Bignum&);

        Bignum operator +(const Bignum&);
        Bignum operator -(const Bignum&);
        bool operator<(const Bignum &) const;
        bool operator>(const Bignum &) const;

        friend ostream& operator <<(ostream&,const Bignum &);
        friend istream& operator >>(istream&, Bignum &A);

        vector<int> get_number()const {return number;}
        bool get_sign()const {return sign;}
        void set_number(string s);
        void set_sign(bool a){sign = a;}
};

Bignum::Bignum(const Bignum &A){
    *this = A;
}
void Bignum::set_number(string s){
    for(int i = s.size()-1;i > -1;i--)
        number.push_back(s[i]-'0');
}

bool Bignum::operator<(const Bignum &b)const{
    if(number.size() < b.get_number().size())
        return true;
    if(number.size() > b.get_number().size())
        return false;
    for(int i = 0;i < number.size();i++){
        if(number[i] == b.get_number()[i])
            continue;
        else if( number[i] < b.get_number()[i])
            return true;
        return false;
    }
}

bool Bignum::operator>(const Bignum &b)const{
    if(number.size() > b.get_number().size())
        return true;
    if(number.size() < b.get_number().size())
        return false;
    for(int i = 0;i < number.size();i++){
        if(number[i] == b.get_number()[i])
            continue;
        else if( number[i] > b.get_number()[i])
            return true;
        return false;
    }
}

Bignum Bignum::operator-(const Bignum &b){
    Bignum sol;
    int carry = 0, value;
    int min_size = min(number.size(),b.get_number().size());

    if(*this > b){
        sol.set_sign(true);
        for(int i = 0;i < number.size();i++){
            if(i >= b.get_number().size())
                value = 0;
            else
                value = b.get_number()[i];
            if(number[i] - carry < b.get_number()[i]){
                sol.number.push_back( (number[i] - carry + 10 - value) % 10);
                carry = 1;
            }
            else{
                sol.number.push_back( (number[i]- carry - value) % 10 );
                carry = 0;
            }
        }
    }
    else{
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

      /**Variables for de carry, m(is for see which number is longer than
        the other), partial_sums(auxiliary variable just for control the partials sums)**/
      int carry = 0, partial_sums;
      int min_size = min(number.size(),b.get_number().size());

      for(int i = 0;i < min_size;i++){
           partial_sums = number[i] + b.get_number()[i] + carry;
           sol.number.push_back(partial_sums % 10);
           if(partial_sums > 9)
                carry = 1;
           else
                carry = 0;
      }

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
    if(carry == 1)
        sol.number.push_back(1);

    return sol;
}


ostream& operator <<(ostream &o, const Bignum &A){
    if(!A.get_sign() && A.get_number()[A.get_number().size() - 1] != 0)
        cout<<"-";
    for(int i =  A.get_number().size() - 1;i > -1;i--)
        o<<A.number[i];
    o<<endl;
}

istream& operator >>(istream &i, Bignum &A){
    string s;
    cout<<"Introduzca el Bignum:\n";
    i>>s;
    A.set_number(s);
}


int main()
{
    //ios::sync_with_stdio(0), cin.tie(0);

    Bignum A;
    cin>>A;
    Bignum B;
    cin>> B;

    cout<< "The sum is: \n";
    cout<< A+B;
    cout<< "The substraction is: \n";
    cout<< A-B;

    //system("pause");
    return 0;
}
