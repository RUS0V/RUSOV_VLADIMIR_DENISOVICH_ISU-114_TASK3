#include <iostream>
#include <cmath>
using namespace std;

class Rational{
private:
    int a;
    int b;
public:
    Rational(int a_, int b_){
        a = a_;
        b = b_;
        reduce();
    }
    
    int getA(){ return a; }
    void setA(int a_){ a = a_; }
    
    int getB(){ return b; }
    void setB(int b_){ b = b_; }

    void reduce(){
        int min, nod = 1;
        if(a < b) min = a; 
        else min = b;
        for(int i = 2; i <= min; i++)
            if(a%i == 0 && b%i == 0) nod = i;
        
        a /= nod;
        b /= nod;
    }
    
    double decimal(){
        return (1.0*a)/(1.0*b);
    }
    
    void print(){
        cout << a << "/" << b << endl;
    }
    
    friend Rational& operator + (Rational& r1, Rational& r2){
        Rational *r = new Rational(r1.getA()*r2.getB() + r1.getB()*r2.getA(), r1.getB()*r2.getB());
        r->reduce();
        return *r;
    }
    
    friend Rational& operator - (Rational& r1, Rational& r2){
        Rational *r = new Rational(r1.getA()*r2.getB() - r1.getB()*r2.getA(), r1.getB()*r2.getB());
        r->reduce();
        return *r;
    }
    
    friend Rational& operator * (Rational& r1, Rational& r2){
        Rational *r = new Rational(r1.getA()*r2.getA(), r1.getB()*r2.getA());
        r->reduce();
        return *r;
    }
    
    friend Rational& operator / (Rational& r1, Rational& r2){
        Rational *r = new Rational(r1.getA()*r2.getB(), r1.getB()*r2.getA());
        r->reduce();
        return *r;
    }
    
    bool equal(Rational& r1){
        return (r1.getA() == a && r1.getB() == b);
    }
    
    bool greate(Rational& r1){
        return (decimal() > r1.decimal());
    }
    
    bool less(Rational& r1){
        return (decimal() < r1.decimal());
    }
    
};

int main(){
    Rational r1(5, 6);
    cout << "r1 = ";
    r1.print();
    
    Rational r2(1, 18);
    cout << "r2 = ";
    r2.print();
    
    Rational r3 = r1 + r2;
    cout << "r1 + r2 = ";
    r3.print();
    
    r3 = r1 - r2;
    cout << "r1 - r2 = ";
    r3.print();
    
    r3 = r1 * r2;
    cout << "r1 * r2 = ";
    r3.print();
    
    r3 = r1 / r2;
    cout << "r1 / r2 = ";
    r3.print();
    
    cout << "(r1 == r2) = ";
    cout << r1.equal(r2) << endl;
    
    cout << "(r1 > r2) = ";
    cout << r1.greate(r2) << endl; 
    
    cout << "(r1 < r2) = ";
    cout << r1.less(r2) << endl;
    return 0;
}
