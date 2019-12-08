#include <iostream>
#include <stdlib.h>
#include <conio.h>;
 
using namespace std;
 
struct complex{
    double a,b;
};
class Complex{ // класс "Комплексное число"
    complex comp;
public:
    Complex(double x=0,double y=0){
        comp.a=x;
        comp.b=y;
    }
	//конструкторы
    Complex operator +(const Complex &c);
    Complex operator *(const Complex &c);
    Complex operator -(const Complex &c);
    Complex operator /(const Complex &c);
    const Complex& operator =(const Complex &c){
        comp.a=c.comp.a;
        comp.b=c.comp.b;
        return *this;
    }
    Complex conj();
    Complex Read();
    void Display();
};
//оператор сложения
Complex Complex::operator +(const Complex &c){
    Complex d;
    d.comp.a=comp.a+c.comp.a;
    d.comp.b=comp.b+c.comp.b;
    return d;
}
//оператор умножения
Complex Complex::operator *(const Complex &c){
    Complex t;
    t.comp.a=comp.a*c.comp.a-comp.b*c.comp.b;
    t.comp.b=comp.a*c.comp.b+comp.b*c.comp.a;
    return t;
}
//оператор деления
Complex Complex::operator /(const Complex &c){
    Complex t;
    t.comp.a=(comp.a*c.comp.a+comp.b*c.comp.b)/(comp.a*comp.a+comp.b*comp.b);
    t.comp.b=(comp.b*c.comp.a-comp.a*c.comp.b)/(comp.a*comp.a+comp.b*comp.b);
    return t;
}
//оператор вычитания
Complex Complex::operator -(const Complex &c){
    Complex y;
    y.comp.a=comp.a-c.comp.a;
    y.comp.b=comp.b-c.comp.b;
    return y;
}
Complex Complex::conj(){
    comp.a=comp.a;
    comp.b=-comp.b;
    return *this;
}
void Complex::Display(){
        if(comp.b>=0)
            cout<<comp.a<<"+"<<comp.b<<"i\n";
        else
            cout<<comp.a<<comp.b<<"i\n";
}
Complex Complex::Read(){
    double x,y;
    cout<<"Действительная часть: ";
    cin>>x;
    cout<<"Мнимая часть: ";
    cin>>y;
    Complex A=Complex(x,y);
    return A;
}
//-----------------------------------------------------------//
int chois(){
    int chois_1;
    cout<<"     Операции комплексными числами\n\n";
    cout<<" 1 - Сложение\n";
    cout<<" 2 - Вычитание\n ";
    cout<<"3 - Умножение\n";
    cout<<" 4 - Деление\n";
    cout<<" 0 - Выход\n\n";
    cout<<"\n Выберите действие : \n";
    cin>>chois_1;
    while((chois_1<0) || (chois_1>4)){
        cout<<"     !!!Не корректные данные!!!\n";
        cout<<" Ведите заново : ";
        cin>>chois_1;
    }
    return chois_1;
}
void choise(){
    switch (chois()){
    case 1: {  
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a+b;
        c.Display();
        break;
            }
    case 2:{  
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a-b;
        c.Display();
        break;
        }
    case 3 :{  
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a*b;
        c.Display();
        break;
            }
    case 4:{
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a/b;
        c.Display();
        break;
           }
    default :exit(0);
    }
    system("pause");
    system("cls");
    choise();
 
}
//-----------------------------------------------------------
int main (){
    setlocale(LC_ALL, "Russian" );
    Complex R,T,Y;
    R=Complex(-2,3);
    T=Complex(7,1);
    cout<<"\nПредпросмотр демонстрации метода деление\n";
    cout<<"(-2+3j)/(7+1j)= ";
    Y=R/T;
    Y.Display();
    system("pause");
    system("cls");
    cout<<"\n   -------------------------------------------------------\n";
    cout<<"\n\n";
    choise();
}
