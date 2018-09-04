#include <iostream>
#include<cmath>
using namespace std;
double fx(double x){
  /*faz a função aqui*/
  x = 2*pow(x,3) + 3 * pow(x,2) - 2;
  return x;
}
double f1x(double x){
  /*derivada primeira*/
  x = 4*pow(x,2) + 6 * x;
  return x;
}
double f2x(double x){
  /*derivada segunda*/
  x = 8*x + 6;
  return x;
}
double limInf(){
  double x;
  system("clear");
  cout << "Digite o valor do limite inferior do intervalo : " << endl;
  cin >> x;
  system("clear");
  return x;
}
double limSup(){
  double x;
  system("clear");
  cout << "Digite o valor do limite superior do intervalo : " << endl;
  cin >> x;
  system("clear");
  return x;
}
double epsilon(){
  double e;
  system("clear");
  cout << "Digite o valor arbitrário :"<< endl;
  cin >> e;
  system("clear");
  return e;
}
bool teorema1(double a , double b){
  system("clear");
  if(a == b){
    cout << "Intervalo inválido !" << endl;
    cout << "Pressione enter" << endl;
    getchar();
    getchar();
    system("clear");
    return false;
  }
  if(fx(a) * fx(b) > 0)
    return false;
  else
    return true;

}
bool teorema2(){
  double a = f1x(1);
  if(a > 0)
    return true;
  else
    return false;
}
void bisseccao(double a,double b,double e){
  int contador = 0;
  double x;
  do{
    x = (a+b) / 2;
    if(fx(x) < 0)
      a = x;
    else
      b = x;
    contador++;
  }while(abs(fx(x)) > e);
  cout << "Método da bissecção" << endl;
  cout << "Iterações : " << contador << endl;
  cout << "X = " << x << endl << endl;
}
void cordas(double a,double b,double e){;
  int contador = 0;
  double x;
  double x1,x0;
  x0 = a;
  x1 = b;
  do{
    x = ((x0*fx(x1)) - (x1*fx(x0))) / (fx(x1) - fx(x0));
    x0 = x1;
    x1 = x;
    contador++;
  }while(abs(fx(x)) > e);
    cout << "Método das cordas" << endl;
  cout << "Iterações : " << contador << endl;
  cout << "X = " << x << endl << endl;
}
void newton(double a,double b,double e){

  double x;
  int contador = 0;
  do{
    if(f1x(1) * f2x(1) < 0){
      x = a - (fx(a) / f1x(a));
      a = x;
    }else{
      x = b - (fx(b) / f1x(b));
      b = x;
    }
    contador++;
  }while(abs(fx(x)) > e);
  cout << "Método de Newton" << endl;
  cout << "Iterações : " << contador << endl;
  cout << "X = " << x << endl << endl;
}
int main(){
  int swit;
  double a,b,e;
  do {
    system("clear");
    cout << "1 : Inserir o intervalo e Épsilon " << endl;
    cout << "0 : Sair" << endl;
    cin >> swit;
    switch (swit) {
      case 1:
      system("clear");
      a = limInf();
      b = limSup();
      e = epsilon();
      if(teorema1(a,b)){
        cout << "Teorema 1 ok" << endl;
        if(teorema2()){
          cout << "teorema 2 ok" << endl << endl;
          bisseccao(a,b,e);
          cordas(a,b,e);
          newton(a,b,e);
          getchar();
          getchar();
        }else{
          cout << "Não satisfaz o teorema 2 !" << endl;
          getchar();
          getchar();
        }
      }else{
          cout << "Não satisfaz os teoremas !" << endl;
          getchar();
          getchar();
      }
        break;
      case 0 :
        break;
      default:
        cout << "Opção inválida" << endl;
        getchar();
        getchar();
        break;
    }
  } while(swit != 0);
}
